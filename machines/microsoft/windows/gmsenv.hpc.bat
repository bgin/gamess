@REM ===================================================================
@REM
@REM We perform several FINDSTR so that the settings are echo-ed out.
@REM Which may be useful for troubleshooting. Much better than looking
@REM through a file containing both system's and the job's
@REM environmental variables.
@REM
@FINDSTR /I /R /C:"ERICFMT=" %ENVFIL%
@FINDSTR /I /R /C:"MCPPATH=" %ENVFIL%
@FINDSTR /I /R /C:"EXTBAS=" %ENVFIL%
@FINDSTR /I /R /C:"NUCBAS=" %ENVFIL%
@REM
@FINDSTR /I /R /C:"MAKEFP=" %ENVFIL%
@FINDSTR /I /R /C:"GAMMA=" %ENVFIL%
@FINDSTR /I /R /C:"TRAJECT=" %ENVFIL%
@FINDSTR /I /R /C:"RESTART=" %ENVFIL%
@FINDSTR /I /R /C:"INPUT=" %ENVFIL%
@FINDSTR /I /R /C:"PUNCH=" %ENVFIL%
@FINDSTR /I /R /C:"AOINTS=" %ENVFIL%
@FINDSTR /I /R /C:"MOINTS=" %ENVFIL%
@FINDSTR /I /R /C:"DICTNRY=" %ENVFIL%
@FINDSTR /I /R /C:"DRTFILE=" %ENVFIL%
@FINDSTR /I /R /C:"CIVECTR=" %ENVFIL%
@FINDSTR /I /R /C:"CASINTS=" %ENVFIL%
@FINDSTR /I /R /C:"CIINTS=" %ENVFIL%
@FINDSTR /I /R /C:"WORK15=" %ENVFIL%
@FINDSTR /I /R /C:"WORK16=" %ENVFIL%
@FINDSTR /I /R /C:"CSFSAVE=" %ENVFIL%
@FINDSTR /I /R /C:"FOCKDER=" %ENVFIL%
@FINDSTR /I /R /C:"WORK19=" %ENVFIL%
@FINDSTR /I /R /C:"DASORT=" %ENVFIL%
@FINDSTR /I /R /C:"DIABDAT=" %ENVFIL%
@FINDSTR /I /R /C:"DFTINTS=" %ENVFIL%
@FINDSTR /I /R /C:"DFTGRID=" %ENVFIL%
@FINDSTR /I /R /C:"JKFILE=" %ENVFIL%
@FINDSTR /I /R /C:"ORDINT=" %ENVFIL%
@FINDSTR /I /R /C:"EFPIND=" %ENVFIL%
@FINDSTR /I /R /C:"PCMDATA=" %ENVFIL%
@FINDSTR /I /R /C:"PCMINTS=" %ENVFIL%
@FINDSTR /I /R /C:"SVPWRK1=" %ENVFIL%
@FINDSTR /I /R /C:"SVPWRK2=" %ENVFIL%
@REM
@FINDSTR /I /R /C:"COSCAV=" %ENVFIL%
@FINDSTR /I /R /C:"COSDATA=" %ENVFIL%
@FINDSTR /I /R /C:"COSPOT=" %ENVFIL%
@REM
@FINDSTR /I /R /C:"MLTPL=" %ENVFIL%
@FINDSTR /I /R /C:"MLTPLT=" %ENVFIL%
@FINDSTR /I /R /C:"DAFL30=" %ENVFIL%
@FINDSTR /I /R /C:"SOINTX=" %ENVFIL%
@FINDSTR /I /R /C:"SOINTY=" %ENVFIL%
@FINDSTR /I /R /C:"SOINTZ=" %ENVFIL%
@FINDSTR /I /R /C:"SORESC=" %ENVFIL%
@REM
@REM 35 is used by RESTART, see above
@REM
@FINDSTR /I /R /C:"GCILIST=" %ENVFIL%
@FINDSTR /I /R /C:"HESSIAN=" %ENVFIL%
@FINDSTR /I /R /C:"QMMMTEI=" %ENVFIL%
@FINDSTR /I /R /C:"SOCCDAT=" %ENVFIL%
@FINDSTR /I /R /C:"AABB41=" %ENVFIL%
@FINDSTR /I /R /C:"BBAA42=" %ENVFIL%
@FINDSTR /I /R /C:"BBBB43=" %ENVFIL%
@FINDSTR /I /R /C:"REMD=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD50=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD51=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD52=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD53=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD54=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD55=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD56=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD57=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD58=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD59=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD60=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD61=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD62=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD63=" %ENVFIL%
@FINDSTR /I /R /C:"MCQD64=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT1=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT2=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT3=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT4=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT5=" %ENVFIL%
@FINDSTR /I /R /C:"NMRINT6=" %ENVFIL%
@FINDSTR /I /R /C:"DCPHFH2=" %ENVFIL%
@FINDSTR /I /R /C:"DCPHF21=" %ENVFIL%
@FINDSTR /I /R /C:"ELNUINT=" %ENVFIL%
@FINDSTR /I /R /C:"NUNUINT=" %ENVFIL%
@FINDSTR /I /R /C:"GVVPT=" %ENVFIL%
@FINDSTR /I /R /C:"NUMOIN=" %ENVFIL%
@FINDSTR /I /R /C:"NUMOCAS=" %ENVFIL%
@FINDSTR /I /R /C:"NUELMO=" %ENVFIL%
@FINDSTR /I /R /C:"NUELCAS=" %ENVFIL%
@REM
@REM Next files are for RI-MP2
@REM
@FINDSTR /I /R /C:"RIVMAT=" %ENVFIL%
@FINDSTR /I /R /C:"RIT2A=" %ENVFIL%
@FINDSTR /I /R /C:"RIT3A=" %ENVFIL%
@FINDSTR /I /R /C:"RIT2B=" %ENVFIL%
@FINDSTR /I /R /C:"RIT3B=" %ENVFIL%
@REM
@REM Next files are for GMCQDPT
@REM
@FINDSTR /I /R /C:"GMCREF=" %ENVFIL%
@FINDSTR /I /R /C:"GMCO2R=" %ENVFIL%
@FINDSTR /I /R /C:"GMCROC=" %ENVFIL%
@FINDSTR /I /R /C:"GMCOOC=" %ENVFIL%
@FINDSTR /I /R /C:"GMCCC0=" %ENVFIL%
@FINDSTR /I /R /C:"GMCHMA=" %ENVFIL%
@FINDSTR /I /R /C:"GMCEI1=" %ENVFIL%
@FINDSTR /I /R /C:"GMCEI2=" %ENVFIL%
@FINDSTR /I /R /C:"GMCEOB=" %ENVFIL%
@FINDSTR /I /R /C:"GMCEDT=" %ENVFIL%
@FINDSTR /I /R /C:"GMCERF=" %ENVFIL%
@FINDSTR /I /R /C:"GMCHCR=" %ENVFIL%
@FINDSTR /I /R /C:"GMCGJK=" %ENVFIL%
@FINDSTR /I /R /C:"GMCGAI=" %ENVFIL%
@FINDSTR /I /R /C:"GMCGEO=" %ENVFIL%
@FINDSTR /I /R /C:"GMCTE1=" %ENVFIL%
@FINDSTR /I /R /C:"GMCTE2=" %ENVFIL%
@FINDSTR /I /R /C:"GMCHEF=" %ENVFIL%
@FINDSTR /I /R /C:"GMCMOL=" %ENVFIL%
@FINDSTR /I /R /C:"GMCMOS=" %ENVFIL%
@FINDSTR /I /R /C:"GMCWGT=" %ENVFIL%
@FINDSTR /I /R /C:"GMCRM2=" %ENVFIL%
@FINDSTR /I /R /C:"GMCRM1=" %ENVFIL%
@FINDSTR /I /R /C:"GMCR00=" %ENVFIL%
@FINDSTR /I /R /C:"GMCRP1=" %ENVFIL%
@FINDSTR /I /R /C:"GMCRP2=" %ENVFIL%
@FINDSTR /I /R /C:"GMCVEF=" %ENVFIL%
@FINDSTR /I /R /C:"GMCDIN=" %ENVFIL%
@FINDSTR /I /R /C:"GMC2SZ=" %ENVFIL%
@FINDSTR /I /R /C:"GMCCCS=" %ENVFIL%
@REM
@REM Next files are used only during closed shell coupled cluster runs.
@REM
@FINDSTR /I /R /C:"CCTYP[(=]" %UNC_SCRATCHDIR%\%JOB%.%JOBID%.F05 > NUL
@IF NOT ERRORLEVEL 1 (
@FINDSTR /I /R /C:"CCREST=" %ENVFIL%
@FINDSTR /I /R /C:"CCDIIS=" %ENVFIL%
@FINDSTR /I /R /C:"CCINTS=" %ENVFIL%
@FINDSTR /I /R /C:"CCT1AMP=" %ENVFIL%
@FINDSTR /I /R /C:"CCT2AMP=" %ENVFIL%
@FINDSTR /I /R /C:"CCT3AMP=" %ENVFIL%
@FINDSTR /I /R /C:"CCVM=" %ENVFIL%
@FINDSTR /I /R /C:"CCVE=" %ENVFIL%
@FINDSTR /I /R /C:"CCQUADS=" %ENVFIL%
@FINDSTR /I /R /C:"QUADSVO=" %ENVFIL%
@FINDSTR /I /R /C:"EOMSTAR=" %ENVFIL%
@FINDSTR /I /R /C:"EOMVEC1=" %ENVFIL%
@FINDSTR /I /R /C:"EOMVEC2=" %ENVFIL%
@FINDSTR /I /R /C:"EOMHC1=" %ENVFIL%
@FINDSTR /I /R /C:"EOMHC2=" %ENVFIL%
@FINDSTR /I /R /C:"EOMHHHH=" %ENVFIL%
@FINDSTR /I /R /C:"EOMPPPP=" %ENVFIL%
@FINDSTR /I /R /C:"EOMRAMP=" %ENVFIL%
@FINDSTR /I /R /C:"EOMRTMP=" %ENVFIL%
@FINDSTR /I /R /C:"EOMDG12=" %ENVFIL%
@FINDSTR /I /R /C:"MMPP=" %ENVFIL%
@FINDSTR /I /R /C:"MMHPP=" %ENVFIL%
@FINDSTR /I /R /C:"MMCIVEC=" %ENVFIL%
@FINDSTR /I /R /C:"MMCIVC1=" %ENVFIL%
@FINDSTR /I /R /C:"MMCIITR=" %ENVFIL%
@FINDSTR /I /R /C:"EOMVL1=" %ENVFIL%
@FINDSTR /I /R /C:"EOMVL2=" %ENVFIL%
@FINDSTR /I /R /C:"EOMLVEC=" %ENVFIL%
@FINDSTR /I /R /C:"EOMHL1=" %ENVFIL%
@FINDSTR /I /R /C:"EOMHL2=" %ENVFIL%
@FINDSTR /I /R /C:"CCVVVV=" %ENVFIL%
@REM
@REM Next files are used only during open shell coupled cluster runs.
@REM
@FINDSTR /I /R /C:"AMPROCC=" %ENVFIL%
@FINDSTR /I /R /C:"ITOPNCC=" %ENVFIL%
@FINDSTR /I /R /C:"FOCKMTX=" %ENVFIL%
@FINDSTR /I /R /C:"LAMB23=" %ENVFIL%
@FINDSTR /I /R /C:"VHHAA=" %ENVFIL%
@FINDSTR /I /R /C:"VHHBB=" %ENVFIL%
@FINDSTR /I /R /C:"VHHAB=" %ENVFIL%
@FINDSTR /I /R /C:"VMAA=" %ENVFIL%
@FINDSTR /I /R /C:"VMBB=" %ENVFIL%
@FINDSTR /I /R /C:"VMAB=" %ENVFIL%
@FINDSTR /I /R /C:"VMBA=" %ENVFIL%
@FINDSTR /I /R /C:"VHPRAA=" %ENVFIL%
@FINDSTR /I /R /C:"VHPRBB=" %ENVFIL%
@FINDSTR /I /R /C:"VHPRAB=" %ENVFIL%
@FINDSTR /I /R /C:"VHPLAA=" %ENVFIL%
@FINDSTR /I /R /C:"VHPLBB=" %ENVFIL%
@FINDSTR /I /R /C:"VHPLAB=" %ENVFIL%
@FINDSTR /I /R /C:"VHPLBA=" %ENVFIL%
@FINDSTR /I /R /C:"VEAA=" %ENVFIL%
@FINDSTR /I /R /C:"VEBB=" %ENVFIL%
@FINDSTR /I /R /C:"VEAB=" %ENVFIL%
@FINDSTR /I /R /C:"VEBA=" %ENVFIL%
@FINDSTR /I /R /C:"VPPPP=" %ENVFIL%
@FINDSTR /I /R /C:"INTERM1=" %ENVFIL%
@FINDSTR /I /R /C:"INTERM2=" %ENVFIL%
@FINDSTR /I /R /C:"INTERM3=" %ENVFIL%
@FINDSTR /I /R /C:"ITSPACE=" %ENVFIL%
@FINDSTR /I /R /C:"INSTART=" %ENVFIL%
@FINDSTR /I /R /C:"ITSPC3=" %ENVFIL%
)
@REM
@REM Next files are used only during elongation method runs.
@REM
@FINDSTR /I /R /C:"NELONG=" %UNC_SCRATCHDIR%\%JOB%.%JOBID%.F05 > NUL
@IF NOT ERRORLEVEL 1 (
@FINDSTR /I /R /C:"ELGNAME=" %ENVFIL%
@FINDSTR /I /R /C:"AOINTS=" %ENVFIL%
@FINDSTR /I /R /C:"ELGDOS=" %ENVFIL%
@FINDSTR /I /R /C:"ELGDAT=" %ENVFIL%
@FINDSTR /I /R /C:"ELGPAR=" %ENVFIL%
@FINDSTR /I /R /C:"ELGCUT=" %ENVFIL%
@FINDSTR /I /R /C:"ELGVEC=" %ENVFIL%
@FINDSTR /I /R /C:"EGINTA=" %ENVFIL%
@FINDSTR /I /R /C:"EGINTB=" %ENVFIL%
@FINDSTR /I /R /C:"EGTDHF=" %ENVFIL%
@FINDSTR /I /R /C:"EGTEST=" %ENVFIL%
)
@REM
@REM Next files are used only during extended TDHF package runs.
@REM
@FINDSTR /I /R /C:"RUNTYP=TDHFX" %UNC_SCRATCHDIR%\%JOB%.%JOBID%.F05
@IF NOT ERRORLEVEL 1 (
@FINDSTR /I /R /C:"OLI201=" %ENVFIL%
@FINDSTR /I /R /C:"OLI202=" %ENVFIL%
@FINDSTR /I /R /C:"OLI203=" %ENVFIL%
@FINDSTR /I /R /C:"OLI204=" %ENVFIL%
@FINDSTR /I /R /C:"OLI205=" %ENVFIL%
@FINDSTR /I /R /C:"OLI206=" %ENVFIL%
@FINDSTR /I /R /C:"OLI207=" %ENVFIL%
@FINDSTR /I /R /C:"OLI208=" %ENVFIL%
@FINDSTR /I /R /C:"OLI209=" %ENVFIL%
@FINDSTR /I /R /C:"OLI210=" %ENVFIL%
@FINDSTR /I /R /C:"OLI211=" %ENVFIL%
@FINDSTR /I /R /C:"OLI212=" %ENVFIL%
@FINDSTR /I /R /C:"OLI213=" %ENVFIL%
@FINDSTR /I /R /C:"OLI214=" %ENVFIL%
@FINDSTR /I /R /C:"OLI215=" %ENVFIL%
@FINDSTR /I /R /C:"OLI216=" %ENVFIL%
@FINDSTR /I /R /C:"OLI217=" %ENVFIL%
@FINDSTR /I /R /C:"OLI218=" %ENVFIL%
@FINDSTR /I /R /C:"OLI219=" %ENVFIL%
@FINDSTR /I /R /C:"OLI220=" %ENVFIL%
@FINDSTR /I /R /C:"OLI221=" %ENVFIL%
@FINDSTR /I /R /C:"OLI222=" %ENVFIL%
@FINDSTR /I /R /C:"OLI223=" %ENVFIL%
@FINDSTR /I /R /C:"OLI224=" %ENVFIL%
@FINDSTR /I /R /C:"OLI225=" %ENVFIL%
@FINDSTR /I /R /C:"OLI226=" %ENVFIL%
@FINDSTR /I /R /C:"OLI227=" %ENVFIL%
@FINDSTR /I /R /C:"OLI228=" %ENVFIL%
@FINDSTR /I /R /C:"OLI229=" %ENVFIL%
@FINDSTR /I /R /C:"OLI230=" %ENVFIL%
@FINDSTR /I /R /C:"OLI231=" %ENVFIL%
@FINDSTR /I /R /C:"OLI232=" %ENVFIL%
@FINDSTR /I /R /C:"OLI233=" %ENVFIL%
@FINDSTR /I /R /C:"OLI234=" %ENVFIL%
@FINDSTR /I /R /C:"OLI235=" %ENVFIL%
@FINDSTR /I /R /C:"OLI236=" %ENVFIL%
@FINDSTR /I /R /C:"OLI237=" %ENVFIL%
@FINDSTR /I /R /C:"OLI238=" %ENVFIL%
@FINDSTR /I /R /C:"OLI239=" %ENVFIL%
)
@REM
@REM Next files are used only during divide-and-conquer runs
@REM
@FINDSTR /I /R /C:"DCSUB=" %ENVFIL%
@FINDSTR /I /R /C:"DCVEC=" %ENVFIL%
@FINDSTR /I /R /C:"DCEIG=" %ENVFIL%
@FINDSTR /I /R /C:"DCDM=" %ENVFIL%
@FINDSTR /I /R /C:"DCDMO=" %ENVFIL%
@FINDSTR /I /R /C:"DCQ=" %ENVFIL%
@FINDSTR /I /R /C:"DCW=" %ENVFIL%
@FINDSTR /I /R /C:"DCEDM=" %ENVFIL%
@REM
@REM Next files are used only during LMO hyperpolarizability analysis
@REM
@FINDSTR /I /R /C:"LHYPWRK=" %ENVFIL%
@FINDSTR /I /R /C:"LHYPWK2=" %ENVFIL%
@FINDSTR /I /R /C:"BONDDPF=" %ENVFIL%
@REM
@REM Next value is used only within the VB2000 add-on code
@REM
@FINDSTR /I /R /C:"VB2000PATH=" %ENVFIL%
@FINDSTR /I /R /C:"GMSJOBNAME=" %ENVFIL%
@REM
@REM Next files are used during EFMO runs
@REM
@FINDSTR /I /R /C:"IEFMO=" %UNC_SCRATCHDIR%\%JOB%.F05 > NUL
@IF NOT ERRORLEVEL 1 (
  @FINDSTR /I /R /C:"EFMOI" %ENVFIL%
  @FINDSTR /I /R /C:"EFMOF" %ENVFIL%
)
@REM
@REM Next files are used only during CIM runs
@REM
@FINDSTR /I /R /C:"CIMFILE" %ENVFIL%
@FINDSTR /I /R /C:"CIMDMN" %ENVFIL%
@FINDSTR /I /R /C:"CIMDCT" %ENVFIL%
@FINDSTR /I /R /C:"CIMAOI" %ENVFIL%
@FINDSTR /I /R /C:"CIMMOI" %ENVFIL%
@REM
@REM We are done echo-ing out the job's environmental variables
@REM
@REM ===================================================================
@REM
