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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_LAEBZ_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_LAEBZ_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for laebz is the netlib-compatible backend.
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
inline std::ptrdiff_t laebz( const fortran_int_t ijob,
        const fortran_int_t nitmax, const fortran_int_t n,
        const fortran_int_t mmax, const fortran_int_t minp,
        const fortran_int_t nbmin, const float abstol, const float reltol,
        const float pivmin, const float* d, const float* e, const float* e2,
        fortran_int_t* nval, float* ab, float* c, fortran_int_t& mout,
        fortran_int_t* nab, float* work, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_SLAEBZ( &ijob, &nitmax, &n, &mmax, &minp, &nbmin, &abstol, &reltol,
            &pivmin, d, e, e2, nval, ab, c, &mout, nab, work, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t laebz( const fortran_int_t ijob,
        const fortran_int_t nitmax, const fortran_int_t n,
        const fortran_int_t mmax, const fortran_int_t minp,
        const fortran_int_t nbmin, const double abstol, const double reltol,
        const double pivmin, const double* d, const double* e,
        const double* e2, fortran_int_t* nval, double* ab, double* c,
        fortran_int_t& mout, fortran_int_t* nab, double* work,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_DLAEBZ( &ijob, &nitmax, &n, &mmax, &minp, &nbmin, &abstol, &reltol,
            &pivmin, d, e, e2, nval, ab, c, &mout, nab, work, iwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to laebz.
//
template< typename Value >
struct laebz_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorD, typename VectorE, typename VectorE2,
            typename VectorNVAL, typename MatrixAB, typename VectorC,
            typename MatrixNAB, typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const fortran_int_t ijob,
            const fortran_int_t nitmax, const fortran_int_t n,
            const fortran_int_t minp, const fortran_int_t nbmin,
            const real_type abstol, const real_type reltol,
            const real_type pivmin, const VectorD& d, const VectorE& e,
            const VectorE2& e2, VectorNVAL& nval, MatrixAB& ab, VectorC& c,
            fortran_int_t& mout, MatrixNAB& nab, detail::workspace2< WORK,
            IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixAB >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorE >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorE2 >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixAB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorNVAL >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixNAB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorNVAL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixAB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorC >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixNAB >::value) );
        BOOST_ASSERT( bindings::size(d) >= n );
        BOOST_ASSERT( bindings::size(e) >= n );
        BOOST_ASSERT( bindings::size(e2) >= n );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( bindings::stride_major(ab) ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( bindings::stride_major(ab) ));
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        return detail::laebz( ijob, nitmax, n, bindings::stride_major(ab),
                minp, nbmin, abstol, reltol, pivmin, bindings::begin_value(d),
                bindings::begin_value(e), bindings::begin_value(e2),
                bindings::begin_value(nval), bindings::begin_value(ab),
                bindings::begin_value(c), mout, bindings::begin_value(nab),
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
    template< typename VectorD, typename VectorE, typename VectorE2,
            typename VectorNVAL, typename MatrixAB, typename VectorC,
            typename MatrixNAB >
    static std::ptrdiff_t invoke( const fortran_int_t ijob,
            const fortran_int_t nitmax, const fortran_int_t n,
            const fortran_int_t minp, const fortran_int_t nbmin,
            const real_type abstol, const real_type reltol,
            const real_type pivmin, const VectorD& d, const VectorE& e,
            const VectorE2& e2, VectorNVAL& nval, MatrixAB& ab, VectorC& c,
            fortran_int_t& mout, MatrixNAB& nab, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                bindings::stride_major(ab) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( bindings::stride_major(ab) ) );
        return invoke( ijob, nitmax, n, minp, nbmin, abstol, reltol, pivmin,
                d, e, e2, nval, ab, c, mout, nab, workspace( tmp_work,
                tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorD, typename VectorE, typename VectorE2,
            typename VectorNVAL, typename MatrixAB, typename VectorC,
            typename MatrixNAB >
    static std::ptrdiff_t invoke( const fortran_int_t ijob,
            const fortran_int_t nitmax, const fortran_int_t n,
            const fortran_int_t minp, const fortran_int_t nbmin,
            const real_type abstol, const real_type reltol,
            const real_type pivmin, const VectorD& d, const VectorE& e,
            const VectorE2& e2, VectorNVAL& nval, MatrixAB& ab, VectorC& c,
            fortran_int_t& mout, MatrixNAB& nab, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( ijob, nitmax, n, minp, nbmin, abstol, reltol, pivmin,
                d, e, e2, nval, ab, c, mout, nab, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t mmax ) {
        return mmax;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t mmax ) {
        return mmax;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the laebz_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for laebz. Its overload differs for
// * MatrixAB&
// * MatrixNAB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, MatrixAB& ab, VectorC& c, fortran_int_t& mout,
        MatrixNAB& nab, Workspace work ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab, work );
}

//
// Overloaded function for laebz. Its overload differs for
// * MatrixAB&
// * MatrixNAB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB >
inline typename boost::disable_if< detail::is_workspace< MatrixNAB >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, MatrixAB& ab, VectorC& c, fortran_int_t& mout,
        MatrixNAB& nab ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab,
            optimal_workspace() );
}

//
// Overloaded function for laebz. Its overload differs for
// * const MatrixAB&
// * MatrixNAB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, const MatrixAB& ab, VectorC& c,
        fortran_int_t& mout, MatrixNAB& nab, Workspace work ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab, work );
}

//
// Overloaded function for laebz. Its overload differs for
// * const MatrixAB&
// * MatrixNAB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB >
inline typename boost::disable_if< detail::is_workspace< MatrixNAB >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, const MatrixAB& ab, VectorC& c,
        fortran_int_t& mout, MatrixNAB& nab ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab,
            optimal_workspace() );
}

//
// Overloaded function for laebz. Its overload differs for
// * MatrixAB&
// * const MatrixNAB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, MatrixAB& ab, VectorC& c, fortran_int_t& mout,
        const MatrixNAB& nab, Workspace work ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab, work );
}

//
// Overloaded function for laebz. Its overload differs for
// * MatrixAB&
// * const MatrixNAB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB >
inline typename boost::disable_if< detail::is_workspace< MatrixNAB >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, MatrixAB& ab, VectorC& c, fortran_int_t& mout,
        const MatrixNAB& nab ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab,
            optimal_workspace() );
}

//
// Overloaded function for laebz. Its overload differs for
// * const MatrixAB&
// * const MatrixNAB&
// * User-defined workspace
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, const MatrixAB& ab, VectorC& c,
        fortran_int_t& mout, const MatrixNAB& nab, Workspace work ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab, work );
}

//
// Overloaded function for laebz. Its overload differs for
// * const MatrixAB&
// * const MatrixNAB&
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorE, typename VectorE2,
        typename VectorNVAL, typename MatrixAB, typename VectorC,
        typename MatrixNAB >
inline typename boost::disable_if< detail::is_workspace< MatrixNAB >,
        std::ptrdiff_t >::type
laebz( const fortran_int_t ijob, const fortran_int_t nitmax,
        const fortran_int_t n, const fortran_int_t minp,
        const fortran_int_t nbmin, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type abstol,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type reltol, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const VectorD& d, const VectorE& e, const VectorE2& e2,
        VectorNVAL& nval, const MatrixAB& ab, VectorC& c,
        fortran_int_t& mout, const MatrixNAB& nab ) {
    return laebz_impl< typename bindings::value_type<
            VectorD >::type >::invoke( ijob, nitmax, n, minp, nbmin, abstol,
            reltol, pivmin, d, e, e2, nval, ab, c, mout, nab,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
