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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GELSD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GELSD_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/lapack/auxiliary/ilaenv.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for gelsd is the netlib-compatible backend.
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
// * float value-type.
//
inline std::ptrdiff_t gelsd( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t nrhs, float* a, const fortran_int_t lda, float* b,
        const fortran_int_t ldb, float* s, const float rcond,
        fortran_int_t& rank, float* work, const fortran_int_t lwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_SGELSD( &m, &n, &nrhs, a, &lda, b, &ldb, s, &rcond, &rank, work,
            &lwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t gelsd( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t nrhs, double* a, const fortran_int_t lda,
        double* b, const fortran_int_t ldb, double* s, const double rcond,
        fortran_int_t& rank, double* work, const fortran_int_t lwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_DGELSD( &m, &n, &nrhs, a, &lda, b, &ldb, s, &rcond, &rank, work,
            &lwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t gelsd( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t nrhs, std::complex<float>* a,
        const fortran_int_t lda, std::complex<float>* b,
        const fortran_int_t ldb, float* s, const float rcond,
        fortran_int_t& rank, std::complex<float>* work,
        const fortran_int_t lwork, float* rwork, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_CGELSD( &m, &n, &nrhs, a, &lda, b, &ldb, s, &rcond, &rank, work,
            &lwork, rwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t gelsd( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t nrhs, const std::complex<double>* a,
        const fortran_int_t lda, std::complex<double>* b,
        const fortran_int_t ldb, double* s, const double rcond,
        fortran_int_t& rank, std::complex<double>* work,
        const fortran_int_t lwork, double* rwork, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_ZGELSD( &m, &n, &nrhs, a, &lda, b, &ldb, s, &rcond, &rank, work,
            &lwork, rwork, iwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to gelsd.
//
template< typename Value, typename Enable = void >
struct gelsd_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct gelsd_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename VectorS,
            typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            detail::workspace2< WORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorS >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorS >::value) );
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        BOOST_ASSERT( bindings::size(s) >= std::min<
                std::ptrdiff_t >(bindings::size_row(a),
                bindings::size_column(a)) );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( minmn, nlvl ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( minmn, smlsiz, nlvl,
                bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(a) >= 0 );
        BOOST_ASSERT( bindings::size_column(b) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_row(a) >= 0 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_row(a)) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                std::max< std::ptrdiff_t >(bindings::size_row(a),
                bindings::size_column(a))) );
        return detail::gelsd( bindings::size_row(a), bindings::size_column(a),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), bindings::begin_value(s), rcond,
                rank, bindings::begin_value(work.select(real_type())),
                bindings::size(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixA, typename MatrixB, typename VectorS >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        bindings::detail::array< real_type > tmp_work( min_size_work( minmn,
                smlsiz, nlvl, bindings::size_column(b) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( minmn, nlvl ) );
        return invoke( a, b, s, rcond, rank, workspace( tmp_work,
                tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename MatrixB, typename VectorS >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        real_type opt_size_work;
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( minmn, nlvl ) );
        detail::gelsd( bindings::size_row(a), bindings::size_column(a),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), bindings::begin_value(s), rcond,
                rank, &opt_size_work, -1, bindings::begin_value(tmp_iwork) );
        bindings::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( a, b, s, rcond, rank, workspace( tmp_work,
                tmp_iwork ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t minmn,
            const std::ptrdiff_t smlsiz, const std::ptrdiff_t nlvl,
            const std::ptrdiff_t nrhs ) {
        std::ptrdiff_t smlsiz_plus_one = smlsiz + 1;
        return std::max< std::ptrdiff_t >( 1, 12*minmn + 2*minmn*smlsiz +
                8*minmn*nlvl + minmn*nrhs +
                smlsiz_plus_one * smlsiz_plus_one );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t minmn,
            const std::ptrdiff_t nlvl ) {
        return std::max< std::ptrdiff_t >( 1, 3*minmn*nlvl + 11*minmn );
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct gelsd_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename VectorS,
            typename WORK, typename RWORK, typename IWORK >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            detail::workspace3< WORK, RWORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorS >::value) );
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        BOOST_ASSERT( bindings::size(s) >= std::min<
                std::ptrdiff_t >(bindings::size_row(a),
                bindings::size_column(a)) );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( minmn, nlvl ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( minmn, smlsiz, nlvl,
                bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(a), minmn,
                bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(a) >= 0 );
        BOOST_ASSERT( bindings::size_column(b) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_row(a) >= 0 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_row(a)) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                std::max< std::ptrdiff_t >(bindings::size_row(a),
                bindings::size_column(a))) );
        return detail::gelsd( bindings::size_row(a), bindings::size_column(a),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), bindings::begin_value(s), rcond,
                rank, bindings::begin_value(work.select(value_type())),
                bindings::size(work.select(value_type())),
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixA, typename MatrixB, typename VectorS >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(a), minmn, bindings::size_column(b) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork( minmn,
                smlsiz, nlvl, bindings::size_column(b) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( minmn, nlvl ) );
        return invoke( a, b, s, rcond, rank, workspace( tmp_work, tmp_rwork,
                tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename MatrixB, typename VectorS >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, VectorS& s,
            const real_type rcond, fortran_int_t& rank,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t minmn = std::min< std::ptrdiff_t >( size_row(a),
                size_column(a) );
        std::ptrdiff_t smlsiz = ilaenv(9, "GELSD", "");
        std::ptrdiff_t nlvl = std::max<
                std::ptrdiff_t >( static_cast<std::ptrdiff_t>(std::log(
                static_cast<real_type>(minmn)/static_cast<real_type>(smlsiz+
                1))/std::log(2.0)) + 1, 0 );
        value_type opt_size_work;
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork( minmn,
                smlsiz, nlvl, bindings::size_column(b) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( minmn, nlvl ) );
        detail::gelsd( bindings::size_row(a), bindings::size_column(a),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), bindings::begin_value(s), rcond,
                rank, &opt_size_work, -1, bindings::begin_value(tmp_rwork),
                bindings::begin_value(tmp_iwork) );
        bindings::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( a, b, s, rcond, rank, workspace( tmp_work, tmp_rwork,
                tmp_iwork ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n,
            const std::ptrdiff_t minmn, const std::ptrdiff_t nrhs ) {
        return std::max< std::ptrdiff_t >( 1, 2*minmn + std::max<
                std::ptrdiff_t >( n, minmn*nrhs ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t minmn,
            const std::ptrdiff_t smlsiz, const std::ptrdiff_t nlvl,
            const std::ptrdiff_t nrhs ) {
        std::ptrdiff_t smlsiz_plus_one = smlsiz + 1;
        return std::max< std::ptrdiff_t >( 1, 10*minmn + 2*minmn*smlsiz +
                8*minmn*nlvl + 3*smlsiz*nrhs +
                smlsiz_plus_one * smlsiz_plus_one );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t minmn,
            const std::ptrdiff_t nlvl ) {
        return std::max< std::ptrdiff_t >( 1, 3*minmn*nlvl + 11*minmn );
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the gelsd_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for gelsd. Its overload differs for
// * MatrixA&
// * MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorS,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gelsd( MatrixA& a, MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank, work );
}

//
// Overloaded function for gelsd. Its overload differs for
// * MatrixA&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorS >
inline typename boost::disable_if< detail::is_workspace< VectorS >,
        std::ptrdiff_t >::type
gelsd( MatrixA& a, MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for gelsd. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorS,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gelsd( const MatrixA& a, MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank, work );
}

//
// Overloaded function for gelsd. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorS >
inline typename boost::disable_if< detail::is_workspace< VectorS >,
        std::ptrdiff_t >::type
gelsd( const MatrixA& a, MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for gelsd. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorS,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gelsd( MatrixA& a, const MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank, work );
}

//
// Overloaded function for gelsd. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorS >
inline typename boost::disable_if< detail::is_workspace< VectorS >,
        std::ptrdiff_t >::type
gelsd( MatrixA& a, const MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for gelsd. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorS,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gelsd( const MatrixA& a, const MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank, work );
}

//
// Overloaded function for gelsd. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorS >
inline typename boost::disable_if< detail::is_workspace< VectorS >,
        std::ptrdiff_t >::type
gelsd( const MatrixA& a, const MatrixB& b, VectorS& s,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type rcond, fortran_int_t& rank ) {
    return gelsd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( a, b, s, rcond, rank,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
