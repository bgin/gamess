/* -------------------------------------------------------------------- *\
 * Distributed Data Interface
 * ==========================
 * 
 * Subroutines to control dynamic load-balancing.
 *
 * Author: Ryan M. Olson
 * 10 Jun 09 - RMO - update ddi_send_request args
 * 18 May 14 - AG  - changes for ML-GDDI (communicator-associated DDA used for DLB)
\* -------------------------------------------------------------------- */
 # include "ddi_base.h"


   void DDI_GDLBDestroy_Comm(DDI_Comm* world_comm) {
     int id=world_comm->hdlb;
     if (id!=-1) DDI_ProcDLB_destroy(id);
   }

   void DDI_GDLBReset_Commid(int world_comm_id) {
     // DDI_Comm* curr_comm=Comm_find(DDI_WORKING_COMM);
     int curr_comm_id=DDI_WORKING_COMM;
     DDI_Comm* world_comm=Comm_find(world_comm_id);
     
     DDI_Scope(world_comm_id);
     if (world_comm->hdlb==-1) {
       DDI_ProcDLB_create(&(world_comm->hdlb));
     }
     DDI_ProcDLB_reset(world_comm->hdlb);
     DDI_Scope(curr_comm_id);
   }

/* -------------------------------------------------------- *\
   DDI_GDLBRest()
   ==============
   
   Reset the global dynamic load-balance counter.
\* -------------------------------------------------------- */
   void DDI_GDLBReset() {
      int np,me;

    # if !defined USE_SYSV
      int remote_id = 0;
      DDI_Patch Patch;
    # endif

      if(DDI_WORKING_COMM != DDI_COMM_WORLD) {
         /* fprintf(stdout," DDI Error: group dlb counter must be reset in DDI_WORLD scope.\n"); */
         /* Fatal_error(911); */

        /* This communicator should act as WORLD */
        DDI_GDLBReset_Commid(DDI_WORKING_COMM);
        return;
      }

      DDI_NProc(&np,&me);
      DDI_Sync(3041);

#if defined DDI_ARMCI
      DDI_ARMCI_GDLBReset();
#elif defined DDI_MPI2
      DDI_MPI2_GDLBReset();
#else
      if(me == 0) {
    # if defined USE_SYSV
         DDI_GDLBReset_local();
    # else
         # if defined WINTEL
         Patch.oper = DDI_GDLBRESET_OP;
         # else
         Patch.oper = DDI_GDLBRESET;
         # endif
         DDI_Send_request(&Patch,&remote_id,NULL);
    # endif
      }
#endif

      DDI_Sync(3042);
   }


/* -------------------------------------------------------- *\
   DDI_GDLBRest_local()
   ===================
   
   Subroutine that actually resets the global counter.  May
   be called by the master compute process (if FULL_SMP),
   otherwise by the master data server (if !FULL_SMP).
\* -------------------------------------------------------- */
   void DDI_GDLBReset_local() {
    # if FULL_SMP
    # if defined DDI_LAPI
      gv(lapi_gdlb_cntr) = 0;
    # else
      DDI_Sem_acquire(gv(dlb_access),0,DDI_WRITE_ACCESS);
      *gv(gdlb_counter) = 0;
      DDI_Sem_release(gv(dlb_access),0,DDI_WRITE_ACCESS);
    # endif
    # else
      *gv(gdlb_counter) = 0;
    # endif
   }


   void DDI_GDLBNext_Commid(size_t *counter, int world_comm_id) {
     int me,np;

     DDI_NProc(&np,&me);
     if (me==0) {
       DDI_Comm* world_comm=Comm_find(world_comm_id);
       DDI_ProcDLB_next(world_comm->hdlb,0,counter);
     }
     DDI_BCast(counter,sizeof(*counter),0);
   }

/* ---------------------------------------------------------- *\
   DDI_GDLBNext(counter)
   ====================
   @param [OUT] counter - value of the load balance counter returned
                   to the calling process.

   @brief An atomic operation that sets the value of counter to the
   value of the global load-balance counter, then increments
   the global counter.
   @author Ryan Olsen and/or Graham Fletcher
\* --------------------------------------------------------- */

   void DDI_GDLBNext(size_t *counter) {
      int np,me,nn,my,tmp_scope,remote_id=0;
      DDI_Patch Patch;
      DDI_Comm* curr_comm=Comm_find(DDI_WORKING_COMM);
      
      /* Check if the current communicator's parent is NOT global WORLD ("universe") */
      if (curr_comm->parent!=DDI_COMM_WORLD && curr_comm->parent!=DDI_COMM_NULL) {
        /* then use the communicator-specific GDLB code */
        DDI_GDLBNext_Commid(counter,curr_comm->parent);
        return;
      }
      
    # if defined DDI_LAPI
      lapi_cntr_t org_cntr;
      uint tgt          = gv(lapi_map)[0];
      int *tgt_var      = gv(lapi_gdlb_cntr_addr)[tgt];
      int  in_val       = 1;
      int  prev_tgt_val = -1;
    # endif

#if defined DDI_ARMCI
      DDI_ARMCI_GDLBNext(counter);
      return;
#elif defined DDI_MPI2
      DDI_MPI2_GDLBNext(counter);
      return;
#endif
    
      DDI_NProc(&np,&me);

      if(me == 0) {
      /* ---------------------------------- *\
         We need to work in the world scope
      \* ---------------------------------- */
         tmp_scope = DDI_WORKING_COMM;
         gv(ddi_working_comm) = DDI_COMM_WORLD;
   
         DDI_NProc(&np,&me);
         DDI_NNode(&nn,&my);

       # if FULL_SMP
       # if defined DDI_LAPI
         if(LAPI_Setcntr(gv(lapi_hnd),&org_cntr,0) != LAPI_SUCCESS) {
            fprintf(stdout,"%s: LAPI_Setcntr failed in DDI_GDLBNext.\n",DDI_Id());
            Fatal_error(911);
         }
         
         if(LAPI_Rmw(gv(lapi_hnd),FETCH_AND_ADD,tgt,tgt_var,&in_val,
                       &prev_tgt_val,&org_cntr) != LAPI_SUCCESS) {
            fprintf(stdout,"%s: LAPI_Rmw failed in DDI_GDLBNext.\n",DDI_Id());
            Fatal_error(911);
         }
         
         if(LAPI_Waitcntr(gv(lapi_hnd),&org_cntr,1,NULL) != LAPI_SUCCESS) {
            fprintf(stdout,"%s: LAPI_Waitcntr failed in DDI_GDLBNext.\n",DDI_Id());
            Fatal_error(911);
         }
         
         if(prev_tgt_val == -1) {
            fprintf(stdout,"%s: LAPI version of DDI_GDLBNext is not working correctly.\n",DDI_Id());
            Fatal_error(911);
         } else {
            *counter = (size_t) prev_tgt_val;
         }
       # else
         if(my == 0) {
            DDI_GDLBNext_local(counter);
         } else {
            # if defined WINTEL
            Patch.oper = DDI_GDLBNEXT_OP;
            # else
            Patch.oper = DDI_GDLBNEXT;
            # endif
            DDI_Send_request(&Patch,&remote_id,NULL);
            DDI_Recv(counter,sizeof(size_t),remote_id);
         }
       # endif
       # else
         # if defined WINTEL
         Patch.oper = DDI_GDLBNEXT_OP;
         # else
         Patch.oper = DDI_GDLBNEXT;
         # endif
         DDI_Send_request(&Patch,&remote_id,NULL);
         DDI_Recv(counter,sizeof(size_t),remote_id);
       # endif
   
      /* --------------------------- *\
         Return to the working scope
      \* --------------------------- */
         gv(ddi_working_comm) = tmp_scope;
      }

      DDI_BCast(counter,sizeof(size_t),0);
   }


/* ---------------------------------------------------------- *\
   DDI_GDLBNext_local(counter)
   ==========================
   [OUT] counter - value of the load balance counter returned
                   to the calling process.

   Subroutine that performs the DDI_GDLBNext operation.  May
   be called from the master compute process (if FULL_SMP)
   or from the master data server (if !FULL_SMP).
\* --------------------------------------------------------- */
   void DDI_GDLBNext_local(size_t *counter) {

      size_t tmp_val;
  
    # if FULL_SMP
      DDI_Sem_acquire(gv(dlb_access),0,DDI_WRITE_ACCESS);
    # endif

      tmp_val           = *gv(gdlb_counter);
      *counter          = tmp_val++;
      *gv(gdlb_counter) = tmp_val;

    # if FULL_SMP
      DDI_Sem_release(gv(dlb_access),0,DDI_WRITE_ACCESS);
    # endif

   }
 