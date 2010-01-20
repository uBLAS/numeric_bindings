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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GBEQU_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GBEQU_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/bandwidth.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for gbequ is the netlib-compatible backend.
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
inline std::ptrdiff_t gbequ( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t kl, const fortran_int_t ku, const float* ab,
        const fortran_int_t ldab, float* r, float* c, float& rowcnd,
        float& colcnd, float& amax ) {
    fortran_int_t info(0);
    LAPACK_SGBEQU( &m, &n, &kl, &ku, ab, &ldab, r, c, &rowcnd, &colcnd, &amax,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t gbequ( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t kl, const fortran_int_t ku, const double* ab,
        const fortran_int_t ldab, double* r, double* c, double& rowcnd,
        double& colcnd, double& amax ) {
    fortran_int_t info(0);
    LAPACK_DGBEQU( &m, &n, &kl, &ku, ab, &ldab, r, c, &rowcnd, &colcnd, &amax,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t gbequ( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t kl, const fortran_int_t ku,
        const std::complex<float>* ab, const fortran_int_t ldab, float* r,
        float* c, float& rowcnd, float& colcnd, float& amax ) {
    fortran_int_t info(0);
    LAPACK_CGBEQU( &m, &n, &kl, &ku, ab, &ldab, r, c, &rowcnd, &colcnd, &amax,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t gbequ( const fortran_int_t m, const fortran_int_t n,
        const fortran_int_t kl, const fortran_int_t ku,
        const std::complex<double>* ab, const fortran_int_t ldab, double* r,
        double* c, double& rowcnd, double& colcnd, double& amax ) {
    fortran_int_t info(0);
    LAPACK_ZGBEQU( &m, &n, &kl, &ku, ab, &ldab, r, c, &rowcnd, &colcnd, &amax,
            &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to gbequ.
//
template< typename Value, typename Enable = void >
struct gbequ_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct gbequ_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename VectorR, typename VectorC >
    static std::ptrdiff_t invoke( const MatrixAB& ab, VectorR& r, VectorC& c,
            real_type& rowcnd, real_type& colcnd, real_type& amax ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorR >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorC >::value) );
        BOOST_ASSERT( bindings::bandwidth_lower(ab) >= 0 );
        BOOST_ASSERT( bindings::bandwidth_upper(ab) >= 0 );
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::size_row(ab) >= 0 );
        BOOST_ASSERT( bindings::stride_major(ab) >=
                bindings::bandwidth_lower(ab)+bindings::bandwidth_upper(ab)+
                1 );
        return detail::gbequ( bindings::size_row(ab),
                bindings::size_column(ab), bindings::bandwidth_lower(ab),
                bindings::bandwidth_upper(ab), bindings::begin_value(ab),
                bindings::stride_major(ab), bindings::begin_value(r),
                bindings::begin_value(c), rowcnd, colcnd, amax );
    }

};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct gbequ_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename VectorR, typename VectorC >
    static std::ptrdiff_t invoke( const MatrixAB& ab, VectorR& r, VectorC& c,
            real_type& rowcnd, real_type& colcnd, real_type& amax ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorR >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorR >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorC >::value) );
        BOOST_ASSERT( bindings::bandwidth_lower(ab) >= 0 );
        BOOST_ASSERT( bindings::bandwidth_upper(ab) >= 0 );
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::size_row(ab) >= 0 );
        BOOST_ASSERT( bindings::stride_major(ab) >=
                bindings::bandwidth_lower(ab)+bindings::bandwidth_upper(ab)+
                1 );
        return detail::gbequ( bindings::size_row(ab),
                bindings::size_column(ab), bindings::bandwidth_lower(ab),
                bindings::bandwidth_upper(ab), bindings::begin_value(ab),
                bindings::stride_major(ab), bindings::begin_value(r),
                bindings::begin_value(c), rowcnd, colcnd, amax );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the gbequ_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for gbequ. Its overload differs for
// * VectorR&
// * VectorC&
//
template< typename MatrixAB, typename VectorR, typename VectorC >
inline std::ptrdiff_t gbequ( const MatrixAB& ab, VectorR& r, VectorC& c,
        typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& rowcnd, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& colcnd,
        typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& amax ) {
    return gbequ_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( ab, r, c, rowcnd, colcnd, amax );
}

//
// Overloaded function for gbequ. Its overload differs for
// * const VectorR&
// * VectorC&
//
template< typename MatrixAB, typename VectorR, typename VectorC >
inline std::ptrdiff_t gbequ( const MatrixAB& ab, const VectorR& r,
        VectorC& c, typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& rowcnd, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& colcnd,
        typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& amax ) {
    return gbequ_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( ab, r, c, rowcnd, colcnd, amax );
}

//
// Overloaded function for gbequ. Its overload differs for
// * VectorR&
// * const VectorC&
//
template< typename MatrixAB, typename VectorR, typename VectorC >
inline std::ptrdiff_t gbequ( const MatrixAB& ab, VectorR& r,
        const VectorC& c, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& rowcnd,
        typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& colcnd, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& amax ) {
    return gbequ_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( ab, r, c, rowcnd, colcnd, amax );
}

//
// Overloaded function for gbequ. Its overload differs for
// * const VectorR&
// * const VectorC&
//
template< typename MatrixAB, typename VectorR, typename VectorC >
inline std::ptrdiff_t gbequ( const MatrixAB& ab, const VectorR& r,
        const VectorC& c, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& rowcnd,
        typename remove_imaginary< typename bindings::value_type<
        MatrixAB >::type >::type& colcnd, typename remove_imaginary<
        typename bindings::value_type< MatrixAB >::type >::type& amax ) {
    return gbequ_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( ab, r, c, rowcnd, colcnd, amax );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
