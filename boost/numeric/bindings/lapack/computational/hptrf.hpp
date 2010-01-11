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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HPTRF_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HPTRF_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_side.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for hptrf is the netlib-compatible backend.
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
inline std::ptrdiff_t hptrf( UpLo, fortran_int_t n, std::complex<float>* ap,
        fortran_int_t* ipiv ) {
    fortran_int_t info(0);
    LAPACK_CHPTRF( &lapack_option< UpLo >::value, &n, ap, ipiv, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hptrf( UpLo, fortran_int_t n, std::complex<double>* ap,
        fortran_int_t* ipiv ) {
    fortran_int_t info(0);
    LAPACK_ZHPTRF( &lapack_option< UpLo >::value, &n, ap, ipiv, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hptrf.
//
template< typename Value >
struct hptrf_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAP, typename VectorIPIV >
    static std::ptrdiff_t invoke( MatrixAP& ap, VectorIPIV& ipiv ) {
        typedef typename result_of::data_side< MatrixAP >::type uplo;
        BOOST_STATIC_ASSERT( (is_mutable< MatrixAP >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorIPIV >::value) );
        BOOST_ASSERT( size_column(ap) >= 0 );
        return detail::hptrf( uplo(), size_column(ap), begin_value(ap),
                begin_value(ipiv) );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the hptrf_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hptrf. Its overload differs for
// * MatrixAP&
// * VectorIPIV&
//
template< typename MatrixAP, typename VectorIPIV >
inline std::ptrdiff_t hptrf( MatrixAP& ap, VectorIPIV& ipiv ) {
    return hptrf_impl< typename value< MatrixAP >::type >::invoke( ap,
            ipiv );
}

//
// Overloaded function for hptrf. Its overload differs for
// * const MatrixAP&
// * VectorIPIV&
//
template< typename MatrixAP, typename VectorIPIV >
inline std::ptrdiff_t hptrf( const MatrixAP& ap, VectorIPIV& ipiv ) {
    return hptrf_impl< typename value< MatrixAP >::type >::invoke( ap,
            ipiv );
}

//
// Overloaded function for hptrf. Its overload differs for
// * MatrixAP&
// * const VectorIPIV&
//
template< typename MatrixAP, typename VectorIPIV >
inline std::ptrdiff_t hptrf( MatrixAP& ap, const VectorIPIV& ipiv ) {
    return hptrf_impl< typename value< MatrixAP >::type >::invoke( ap,
            ipiv );
}

//
// Overloaded function for hptrf. Its overload differs for
// * const MatrixAP&
// * const VectorIPIV&
//
template< typename MatrixAP, typename VectorIPIV >
inline std::ptrdiff_t hptrf( const MatrixAP& ap, const VectorIPIV& ipiv ) {
    return hptrf_impl< typename value< MatrixAP >::type >::invoke( ap,
            ipiv );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
