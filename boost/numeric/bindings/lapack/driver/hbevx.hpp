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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HBEVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HBEVX_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/bandwidth.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for hbevx is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hbevx( const char jobz, const char range,
        const UpLo uplo, const fortran_int_t n, const fortran_int_t kd,
        std::complex<float>* ab, const fortran_int_t ldab,
        std::complex<float>* q, const fortran_int_t ldq, const float vl,
        const float vu, const fortran_int_t il, const fortran_int_t iu,
        const float abstol, fortran_int_t& m, float* w,
        std::complex<float>* z, const fortran_int_t ldz,
        std::complex<float>* work, float* rwork, fortran_int_t* iwork,
        fortran_int_t* ifail ) {
    fortran_int_t info(0);
    LAPACK_CHBEVX( &jobz, &range, &lapack_option< UpLo >::value, &n, &kd, ab,
            &ldab, q, &ldq, &vl, &vu, &il, &iu, &abstol, &m, w, z, &ldz, work,
            rwork, iwork, ifail, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hbevx( const char jobz, const char range,
        const UpLo uplo, const fortran_int_t n, const fortran_int_t kd,
        std::complex<double>* ab, const fortran_int_t ldab,
        std::complex<double>* q, const fortran_int_t ldq, const double vl,
        const double vu, const fortran_int_t il, const fortran_int_t iu,
        const double abstol, fortran_int_t& m, double* w,
        std::complex<double>* z, const fortran_int_t ldz,
        std::complex<double>* work, double* rwork, fortran_int_t* iwork,
        fortran_int_t* ifail ) {
    fortran_int_t info(0);
    LAPACK_ZHBEVX( &jobz, &range, &lapack_option< UpLo >::value, &n, &kd, ab,
            &ldab, q, &ldq, &vl, &vu, &il, &iu, &abstol, &m, w, z, &ldz, work,
            rwork, iwork, ifail, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hbevx.
//
template< typename Value >
struct hbevx_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL, typename WORK,
            typename RWORK, typename IWORK >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAB& ab, MatrixQ& q, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, detail::workspace3< WORK, RWORK,
            IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixAB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixQ >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixZ >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixQ >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixZ >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixAB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixQ >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorW >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixZ >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorIFAIL >::value) );
        BOOST_ASSERT( bindings::bandwidth(ab, uplo()) >= 0 );
        BOOST_ASSERT( bindings::size(w) >= bindings::size_column(ab) );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::size_minor(q) == 1 ||
                bindings::stride_minor(q) == 1 );
        BOOST_ASSERT( bindings::size_minor(z) == 1 ||
                bindings::stride_minor(z) == 1 );
        BOOST_ASSERT( bindings::stride_major(ab) >= bindings::bandwidth(ab,
                uplo())+1 );
        BOOST_ASSERT( bindings::stride_major(q) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(ab)) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        return detail::hbevx( jobz, range, uplo(), bindings::size_column(ab),
                bindings::bandwidth(ab, uplo()), bindings::begin_value(ab),
                bindings::stride_major(ab), bindings::begin_value(q),
                bindings::stride_major(q), vl, vu, il, iu, abstol, m,
                bindings::begin_value(w), bindings::begin_value(z),
                bindings::stride_major(z),
                bindings::begin_value(work.select(value_type())),
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())),
                bindings::begin_value(ifail) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAB& ab, MatrixQ& q, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, minimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(ab) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(ab) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( bindings::size_column(ab) ) );
        return invoke( jobz, range, ab, q, vl, vu, il, iu, abstol, m, w, z,
                ifail, workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAB& ab, MatrixQ& q, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, optimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        return invoke( jobz, range, ab, q, vl, vu, il, iu, abstol, m, w, z,
                ifail, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t n ) {
        return 7*n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n ) {
        return 5*n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the hbevx_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * MatrixQ&
// * MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * MatrixQ&
// * MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * MatrixQ&
// * MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * MatrixQ&
// * MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * const MatrixQ&
// * MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, const MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * const MatrixQ&
// * MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, const MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * const MatrixQ&
// * MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab,
        const MatrixQ& q, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vl,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vu, const fortran_int_t il,
        const fortran_int_t iu, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type abstol,
        fortran_int_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
        Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * const MatrixQ&
// * MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab,
        const MatrixQ& q, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vl,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vu, const fortran_int_t il,
        const fortran_int_t iu, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type abstol,
        fortran_int_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * MatrixQ&
// * const MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * MatrixQ&
// * const MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * MatrixQ&
// * const MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * MatrixQ&
// * const MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab, MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * const MatrixQ&
// * const MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, const MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * MatrixAB&
// * const MatrixQ&
// * const MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, MatrixAB& ab, const MatrixQ& q,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vl, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * const MatrixQ&
// * const MatrixZ&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab,
        const MatrixQ& q, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vl,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vu, const fortran_int_t il,
        const fortran_int_t iu, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type abstol,
        fortran_int_t& m, VectorW& w, const MatrixZ& z,
        VectorIFAIL& ifail, Workspace work ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, work );
}

//
// Overloaded function for hbevx. Its overload differs for
// * const MatrixAB&
// * const MatrixQ&
// * const MatrixZ&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline typename boost::disable_if< detail::is_workspace< VectorIFAIL >,
        std::ptrdiff_t >::type
hbevx( const char jobz, const char range, const MatrixAB& ab,
        const MatrixQ& q, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type vl,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type vu, const fortran_int_t il,
        const fortran_int_t iu, const typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type abstol,
        fortran_int_t& m, VectorW& w, const MatrixZ& z,
        VectorIFAIL& ifail ) {
    return hbevx_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( jobz, range, ab, q, vl, vu, il, iu,
            abstol, m, w, z, ifail, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
