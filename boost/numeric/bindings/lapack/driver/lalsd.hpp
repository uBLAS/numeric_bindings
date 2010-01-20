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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LALSD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LALSD_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for lalsd is the netlib-compatible backend.
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
inline std::ptrdiff_t lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const fortran_int_t nrhs, float* d, float* e,
        float* b, const fortran_int_t ldb, const float rcond,
        fortran_int_t& rank, float* work, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_SLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond, &rank,
            work, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const fortran_int_t nrhs, double* d, double* e,
        double* b, const fortran_int_t ldb, const double rcond,
        fortran_int_t& rank, double* work, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_DLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond, &rank,
            work, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const fortran_int_t nrhs, float* d, float* e,
        std::complex<float>* b, const fortran_int_t ldb, const float rcond,
        fortran_int_t& rank, std::complex<float>* work, float* rwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_CLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond, &rank,
            work, rwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const fortran_int_t nrhs, double* d, double* e,
        std::complex<double>* b, const fortran_int_t ldb, const double rcond,
        fortran_int_t& rank, std::complex<double>* work, double* rwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_ZLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond, &rank,
            work, rwork, iwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to lalsd.
//
template< typename Value, typename Enable = void >
struct lalsd_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct lalsd_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorD, typename VectorE, typename MatrixB,
            typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, detail::workspace2< WORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorE >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorD >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorE >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        std::ptrdiff_t nlvl = std::max< std::ptrdiff_t >( 0,
                static_cast<std::ptrdiff_t>(
            std::log(static_cast<real_type>(n)/static_cast<real_type>(smlsiz+
                    1)) /
            std::log(static_cast<real_type>(2.)) ) + 1 );
        BOOST_ASSERT( bindings::size(e) >= n-1 );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( n, nlvl ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( n, smlsiz, nlvl, bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(b) >= 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( n >= 0 );
        return detail::lalsd( uplo, smlsiz, n, bindings::size_column(b),
                bindings::begin_value(d), bindings::begin_value(e),
                bindings::begin_value(b), bindings::stride_major(b), rcond,
                rank, bindings::begin_value(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename VectorD, typename VectorE, typename MatrixB >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t nlvl = std::max< std::ptrdiff_t >( 0,
                static_cast<std::ptrdiff_t>(
            std::log(static_cast<real_type>(n)/static_cast<real_type>(smlsiz+
                    1)) /
            std::log(static_cast<real_type>(2.)) ) + 1 );
        bindings::detail::array< real_type > tmp_work( min_size_work( n,
                smlsiz, nlvl, bindings::size_column(b) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( n, nlvl ) );
        return invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
                workspace( tmp_work, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorD, typename VectorE, typename MatrixB >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
                minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n,
            const std::ptrdiff_t smlsiz, const std::ptrdiff_t nlvl,
            const std::ptrdiff_t nrhs ) {
        std::ptrdiff_t smlsiz_plus_one = smlsiz + 1;
        return 9*n + 2*n*smlsiz + 8*n*nlvl + n*nrhs +
                smlsiz_plus_one * smlsiz_plus_one;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n,
            const std::ptrdiff_t nlvl ) {
        return 3*n*nlvl + 11*n;
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct lalsd_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorD, typename VectorE, typename MatrixB,
            typename WORK, typename RWORK, typename IWORK >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, detail::workspace3< WORK, RWORK,
            IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorE >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorD >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorE >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        std::ptrdiff_t nlvl = std::max< std::ptrdiff_t >( 0,
                static_cast<std::ptrdiff_t>(
            std::log(static_cast<real_type>(std::min<
                    std::ptrdiff_t >(traits::matrix_size2(b),n))/
            static_cast<real_type>(smlsiz+1)) /
            std::log(static_cast<real_type>(2.))) + 1 );
        BOOST_ASSERT( bindings::size(e) >= n-1 );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( n, nlvl ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( n, smlsiz, nlvl, bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( n, bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(b) >= 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( n >= 0 );
        return detail::lalsd( uplo, smlsiz, n, bindings::size_column(b),
                bindings::begin_value(d), bindings::begin_value(e),
                bindings::begin_value(b), bindings::stride_major(b), rcond,
                rank, bindings::begin_value(work.select(value_type())),
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
    template< typename VectorD, typename VectorE, typename MatrixB >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        std::ptrdiff_t nlvl = std::max< std::ptrdiff_t >( 0,
                static_cast<std::ptrdiff_t>(
            std::log(static_cast<real_type>(std::min<
                    std::ptrdiff_t >(traits::matrix_size2(b),n))/
            static_cast<real_type>(smlsiz+1)) /
            std::log(static_cast<real_type>(2.))) + 1 );
        bindings::detail::array< value_type > tmp_work( min_size_work( n,
                bindings::size_column(b) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork( n,
                smlsiz, nlvl, bindings::size_column(b) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( n, nlvl ) );
        return invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
                workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorD, typename VectorE, typename MatrixB >
    static std::ptrdiff_t invoke( const char uplo,
            const fortran_int_t smlsiz, const fortran_int_t n,
            VectorD& d, VectorE& e, MatrixB& b, const real_type rcond,
            fortran_int_t& rank, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
                minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n,
            const std::ptrdiff_t nrhs ) {
        return n*nrhs;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t n,
            const std::ptrdiff_t smlsiz, const std::ptrdiff_t nlvl,
            const std::ptrdiff_t nrhs ) {
        std::ptrdiff_t smlsiz_plus_one = smlsiz + 1;
        return 9*n + 2*n*smlsiz + 8*n*nlvl + 3*smlsiz*nrhs +
                smlsiz_plus_one * smlsiz_plus_one;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n,
            const std::ptrdiff_t nlvl ) {
        return 3*n*nlvl+11*n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the lalsd_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * VectorE&
// * MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * VectorE&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * VectorE&
// * MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * VectorE&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * const VectorE&
// * MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, const VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * const VectorE&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, const VectorE& e, MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * const VectorE&
// * MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, const VectorE& e,
        MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank, Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * const VectorE&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, const VectorE& e,
        MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * VectorE&
// * const MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, VectorE& e, const MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank,
        Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * VectorE&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, VectorE& e, const MatrixB& b,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixB >::type >::type rcond, fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * VectorE&
// * const MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank, Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * VectorE&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * const VectorE&
// * const MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, const VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank, Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * VectorD&
// * const VectorE&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, VectorD& d, const VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * const VectorE&
// * const MatrixB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, const VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank, Workspace work ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            work );
}

//
// Overloaded function for lalsd. Its overload differs for
// * const VectorD&
// * const VectorE&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
lalsd( const char uplo, const fortran_int_t smlsiz,
        const fortran_int_t n, const VectorD& d, const VectorE& e,
        const MatrixB& b, const typename remove_imaginary<
        typename bindings::value_type< MatrixB >::type >::type rcond,
        fortran_int_t& rank ) {
    return lalsd_impl< typename bindings::value_type<
            MatrixB >::type >::invoke( uplo, smlsiz, n, d, e, b, rcond, rank,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
