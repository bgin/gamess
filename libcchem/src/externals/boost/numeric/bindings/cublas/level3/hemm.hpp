//
// Copyright (c) 2002--2010
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_CUBLAS_LEVEL3_HEMM_HPP
#define BOOST_NUMERIC_BINDINGS_CUBLAS_LEVEL3_HEMM_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_order.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The BLAS-backend is selected by defining a pre-processor variable,
//  which can be one of
// * for CBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
// * for CUBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
// * netlib-compatible BLAS is the default
//
//// #if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
//// #include <boost/numeric/bindings/blas/detail/cblas.h>
//// #include <boost/numeric/bindings/blas/detail/cblas_option.hpp>
//// #elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
#include <boost/numeric/bindings/blas/detail/cublas.h>
#include <boost/numeric/bindings/blas/detail/default_order.hpp>
#include <boost/numeric/bindings/cublas/exception.hpp>
#include <boost/numeric/bindings/blas/detail/blas_option.hpp>
//// #else
//// #include <boost/numeric/bindings/blas/detail/blas.h>
//// #include <boost/numeric/bindings/blas/detail/blas_option.hpp>
//// #endif

namespace boost {
namespace numeric {
namespace bindings {
namespace cublas {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end BLAS-routine.
//
namespace detail {
using blas::detail::blas_option;
using blas::detail::default_order;

//// #if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
//// //
//// // Overloaded function for dispatching to
//// // * CBLAS backend, and
//// // * float value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const int m, const int n, const float alpha, const float* a,
////         const int lda, const float* b, const int ldb, const float beta,
////         float* c, const int ldc ) {
////     cblas_ssymm( cblas_option< Order >::value, cblas_option< Side >::value,
////             cblas_option< UpLo >::value, m, n, alpha, a, lda, b, ldb, beta, c,
////             ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * CBLAS backend, and
//// // * double value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const int m, const int n, const double alpha, const double* a,
////         const int lda, const double* b, const int ldb, const double beta,
////         double* c, const int ldc ) {
////     cblas_dsymm( cblas_option< Order >::value, cblas_option< Side >::value,
////             cblas_option< UpLo >::value, m, n, alpha, a, lda, b, ldb, beta, c,
////             ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * CBLAS backend, and
//// // * complex<float> value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const int m, const int n, const std::complex<float> alpha,
////         const std::complex<float>* a, const int lda,
////         const std::complex<float>* b, const int ldb,
////         const std::complex<float> beta, std::complex<float>* c,
////         const int ldc ) {
////     cblas_chemm( cblas_option< Order >::value, cblas_option< Side >::value,
////             cblas_option< UpLo >::value, m, n, &alpha, a, lda, b, ldb, &beta,
////             c, ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * CBLAS backend, and
//// // * complex<double> value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const int m, const int n, const std::complex<double> alpha,
////         const std::complex<double>* a, const int lda,
////         const std::complex<double>* b, const int ldb,
////         const std::complex<double> beta, std::complex<double>* c,
////         const int ldc ) {
////     cblas_zhemm( cblas_option< Order >::value, cblas_option< Side >::value,
////             cblas_option< UpLo >::value, m, n, &alpha, a, lda, b, ldb, &beta,
////             c, ldc );
//// }
//// 
//// #elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * float value-type.
//
template< typename Order, typename Side, typename UpLo >
inline void hemm( const Order order, const Side side, const UpLo uplo,
        const int m, const int n, const float alpha, const float* a,
        const int lda, const float* b, const int ldb, const float beta,
        float* c, const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasSsymm( blas::detail::blas_option< Side >::value, blas::detail::blas_option< UpLo >::value, m, n,
            alpha, a, lda, b, ldb, beta, c, ldc );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * double value-type.
//
template< typename Order, typename Side, typename UpLo >
inline void hemm( const Order order, const Side side, const UpLo uplo,
        const int m, const int n, const double alpha, const double* a,
        const int lda, const double* b, const int ldb, const double beta,
        double* c, const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasDsymm( blas::detail::blas_option< Side >::value, blas::detail::blas_option< UpLo >::value, m, n,
            alpha, a, lda, b, ldb, beta, c, ldc );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * complex<float> value-type.
//
template< typename Order, typename Side, typename UpLo >
inline void hemm( const Order order, const Side side, const UpLo uplo,
        const int m, const int n, const std::complex<float> alpha,
        const std::complex<float>* a, const int lda,
        const std::complex<float>* b, const int ldb,
        const std::complex<float> beta, std::complex<float>* c,
        const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    (throw std::runtime_error(std::string(__FILE__) + ":not implemented"), 0);;
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * complex<double> value-type.
//
template< typename Order, typename Side, typename UpLo >
inline void hemm( const Order order, const Side side, const UpLo uplo,
        const int m, const int n, const std::complex<double> alpha,
        const std::complex<double>* a, const int lda,
        const std::complex<double>* b, const int ldb,
        const std::complex<double> beta, std::complex<double>* c,
        const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    (throw std::runtime_error(std::string(__FILE__) + ":not implemented"), 0);;;
}

//// #else
//// //
//// // Overloaded function for dispatching to
//// // * netlib-compatible BLAS backend (the default), and
//// // * float value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const fortran_int_t m, const fortran_int_t n, const float alpha,
////         const float* a, const fortran_int_t lda, const float* b,
////         const fortran_int_t ldb, const float beta, float* c,
////         const fortran_int_t ldc ) {
////     BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
////     BLAS_SSYMM( &blas_option< Side >::value, &blas_option< UpLo >::value, &m,
////             &n, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * netlib-compatible BLAS backend (the default), and
//// // * double value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const fortran_int_t m, const fortran_int_t n, const double alpha,
////         const double* a, const fortran_int_t lda, const double* b,
////         const fortran_int_t ldb, const double beta, double* c,
////         const fortran_int_t ldc ) {
////     BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
////     BLAS_DSYMM( &blas_option< Side >::value, &blas_option< UpLo >::value, &m,
////             &n, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * netlib-compatible BLAS backend (the default), and
//// // * complex<float> value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const fortran_int_t m, const fortran_int_t n,
////         const std::complex<float> alpha, const std::complex<float>* a,
////         const fortran_int_t lda, const std::complex<float>* b,
////         const fortran_int_t ldb, const std::complex<float> beta,
////         std::complex<float>* c, const fortran_int_t ldc ) {
////     BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
////     BLAS_CHEMM( &blas_option< Side >::value, &blas_option< UpLo >::value, &m,
////             &n, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
//// }
//// 
//// //
//// // Overloaded function for dispatching to
//// // * netlib-compatible BLAS backend (the default), and
//// // * complex<double> value-type.
//// //
//// template< typename Order, typename Side, typename UpLo >
//// inline void hemm( const Order order, const Side side, const UpLo uplo,
////         const fortran_int_t m, const fortran_int_t n,
////         const std::complex<double> alpha, const std::complex<double>* a,
////         const fortran_int_t lda, const std::complex<double>* b,
////         const fortran_int_t ldb, const std::complex<double> beta,
////         std::complex<double>* c, const fortran_int_t ldc ) {
////     BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
////     BLAS_ZHEMM( &blas_option< Side >::value, &blas_option< UpLo >::value, &m,
////             &n, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
//// }
//// 
//// #endif

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hemm.
//
template< typename Value >
struct hemm_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef void result_type;

    //
    // Static member function that
    // * Deduces the required arguments for dispatching to BLAS, and
    // * Asserts that most arguments make sense.
    //
    template< typename Side, typename MatrixA, typename MatrixB,
            typename MatrixC >
    static result_type invoke( const Side side, const value_type alpha,
            const MatrixA& a, const MatrixB& b, const value_type beta,
            MatrixC& c ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::data_order< MatrixA >::type order;
        typedef typename result_of::uplo_tag< MatrixA >::type uplo;
        BOOST_STATIC_ASSERT( (is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixC >::value) );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_minor(c) == 1 ||
                bindings::stride_minor(c) == 1 );
        detail::hemm( order(), side, uplo(), bindings::size_row(c),
                bindings::size_column(c), alpha, bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), beta, bindings::begin_value(c),
                bindings::stride_major(c) );
    }
};

//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. Calls
// to these functions are passed to the hemm_impl classes. In the 
// documentation, the const-overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hemm. Its overload differs for
//
template< typename Side, typename MatrixA, typename MatrixB, typename MatrixC >
inline typename hemm_impl< typename bindings::value_type<
        MatrixA >::type >::result_type
hemm( const Side side, const typename bindings::value_type<
        MatrixA >::type alpha, const MatrixA& a, const MatrixB& b,
        const typename bindings::value_type< MatrixA >::type beta,
        MatrixC& c ) {
    hemm_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( side, alpha, a, b, beta, c );
    BOOST_NUMERIC_BINDINGS_CUBLAS_CHECK_STATUS();
}

} // namespace cublas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

