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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_AUXILIARY_LARRB_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_AUXILIARY_LARRB_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
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
// The LAPACK-backend for larrb is the netlib-compatible backend.
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
inline std::ptrdiff_t larrb( const fortran_int_t n, const float* d,
        const float* lld, const fortran_int_t ifirst,
        const fortran_int_t ilast, const float rtol1, const float rtol2,
        const fortran_int_t offset, float* w, float* wgap, float* werr,
        float* work, fortran_int_t* iwork, const float pivmin,
        const float spdiam, const fortran_int_t twist ) {
    fortran_int_t info(0);
    LAPACK_SLARRB( &n, d, lld, &ifirst, &ilast, &rtol1, &rtol2, &offset, w,
            wgap, werr, work, iwork, &pivmin, &spdiam, &twist, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t larrb( const fortran_int_t n, const double* d,
        const double* lld, const fortran_int_t ifirst,
        const fortran_int_t ilast, const double rtol1, const double rtol2,
        const fortran_int_t offset, double* w, double* wgap, double* werr,
        double* work, fortran_int_t* iwork, const double pivmin,
        const double spdiam, const fortran_int_t twist ) {
    fortran_int_t info(0);
    LAPACK_DLARRB( &n, d, lld, &ifirst, &ilast, &rtol1, &rtol2, &offset, w,
            wgap, werr, work, iwork, &pivmin, &spdiam, &twist, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to larrb.
//
template< typename Value >
struct larrb_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorD, typename VectorLLD, typename VectorW,
            typename VectorWGAP, typename VectorWERR, typename WORK,
            typename IWORK >
    static std::ptrdiff_t invoke( const fortran_int_t n, const VectorD& d,
            const VectorLLD& lld, const fortran_int_t ifirst,
            const fortran_int_t ilast, const real_type rtol1,
            const real_type rtol2, const fortran_int_t offset, VectorW& w,
            VectorWGAP& wgap, VectorWERR& werr, const real_type pivmin,
            const real_type spdiam, const fortran_int_t twist,
            detail::workspace2< WORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorLLD >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorW >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorWGAP >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorD >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorWERR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorW >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorWGAP >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorWERR >::value) );
        BOOST_ASSERT( bindings::size(d) >= n );
        BOOST_ASSERT( bindings::size(lld) >= n-1 );
        BOOST_ASSERT( bindings::size(w) >= n );
        BOOST_ASSERT( bindings::size(werr) >= n );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( n ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( n ));
        return detail::larrb( n, bindings::begin_value(d),
                bindings::begin_value(lld), ifirst, ilast, rtol1, rtol2,
                offset, bindings::begin_value(w), bindings::begin_value(wgap),
                bindings::begin_value(werr),
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())),
                pivmin, spdiam, twist );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename VectorD, typename VectorLLD, typename VectorW,
            typename VectorWGAP, typename VectorWERR >
    static std::ptrdiff_t invoke( const fortran_int_t n, const VectorD& d,
            const VectorLLD& lld, const fortran_int_t ifirst,
            const fortran_int_t ilast, const real_type rtol1,
            const real_type rtol2, const fortran_int_t offset, VectorW& w,
            VectorWGAP& wgap, VectorWERR& werr, const real_type pivmin,
            const real_type spdiam, const fortran_int_t twist,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< real_type > tmp_work( min_size_work( n ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( n ) );
        return invoke( n, d, lld, ifirst, ilast, rtol1, rtol2, offset, w,
                wgap, werr, pivmin, spdiam, twist, workspace( tmp_work,
                tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorD, typename VectorLLD, typename VectorW,
            typename VectorWGAP, typename VectorWERR >
    static std::ptrdiff_t invoke( const fortran_int_t n, const VectorD& d,
            const VectorLLD& lld, const fortran_int_t ifirst,
            const fortran_int_t ilast, const real_type rtol1,
            const real_type rtol2, const fortran_int_t offset, VectorW& w,
            VectorWGAP& wgap, VectorWERR& werr, const real_type pivmin,
            const real_type spdiam, const fortran_int_t twist,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( n, d, lld, ifirst, ilast, rtol1, rtol2, offset, w,
                wgap, werr, pivmin, spdiam, twist, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return 2*n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n ) {
        return 2*n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the larrb_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for larrb. Its overload differs for
// * User-defined workspace
//
template< typename VectorD, typename VectorLLD, typename VectorW,
        typename VectorWGAP, typename VectorWERR, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
larrb( const fortran_int_t n, const VectorD& d, const VectorLLD& lld,
        const fortran_int_t ifirst, const fortran_int_t ilast,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type rtol1, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type rtol2,
        const fortran_int_t offset, VectorW& w, VectorWGAP& wgap,
        VectorWERR& werr, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type spdiam, const fortran_int_t twist,
        Workspace work ) {
    return larrb_impl< typename bindings::value_type<
            VectorD >::type >::invoke( n, d, lld, ifirst, ilast, rtol1, rtol2,
            offset, w, wgap, werr, pivmin, spdiam, twist, work );
}

//
// Overloaded function for larrb. Its overload differs for
// * Default workspace-type (optimal)
//
template< typename VectorD, typename VectorLLD, typename VectorW,
        typename VectorWGAP, typename VectorWERR >
inline typename boost::disable_if< detail::is_workspace< VectorWERR >,
        std::ptrdiff_t >::type
larrb( const fortran_int_t n, const VectorD& d, const VectorLLD& lld,
        const fortran_int_t ifirst, const fortran_int_t ilast,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type rtol1, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type rtol2,
        const fortran_int_t offset, VectorW& w, VectorWGAP& wgap,
        VectorWERR& werr, const typename remove_imaginary<
        typename bindings::value_type< VectorD >::type >::type pivmin,
        const typename remove_imaginary< typename bindings::value_type<
        VectorD >::type >::type spdiam, const fortran_int_t twist ) {
    return larrb_impl< typename bindings::value_type<
            VectorD >::type >::invoke( n, d, lld, ifirst, ilast, rtol1, rtol2,
            offset, w, wgap, werr, pivmin, spdiam, twist,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
