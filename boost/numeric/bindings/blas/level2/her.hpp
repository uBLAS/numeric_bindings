//
// Copyright (c) 2003--2009
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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_HER_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_HER_HPP

#include <boost/numeric/bindings/blas/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//$DESCRIPTION

// overloaded functions to call blas
namespace detail {
    inline void her( char const uplo, integer_t const n, float const alpha,
            traits::complex_f* x, integer_t const incx, traits::complex_f* a,
            integer_t const lda ) {
        BLAS_CHER( &uplo, &n, &alpha, traits::complex_ptr(x), &incx,
                traits::complex_ptr(a), &lda );
    }
    inline void her( char const uplo, integer_t const n, double const alpha,
            traits::complex_d* x, integer_t const incx, traits::complex_d* a,
            integer_t const lda ) {
        BLAS_ZHER( &uplo, &n, &alpha, traits::complex_ptr(x), &incx,
                traits::complex_ptr(a), &lda );
    }
}

// value-type based template
template< typename ValueType >
struct her_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename MatrixA >
    static return_type compute( char const uplo, real_type const alpha,
            VectorX& x, MatrixA& a ) {
        detail::her( uplo, traits::matrix_size2(a), alpha,
                traits::vector_storage(x), traits::vector_stride(x),
                traits::matrix_storage(a), traits::leading_dimension(a) );
    }
};

// template function to call her
template< typename VectorX, typename MatrixA >
inline integer_t her( char const uplo,
        typename traits::vector_traits< VectorX >::value_type const alpha,
        VectorX& x, MatrixA& a ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    her_impl< value_type >::compute( uplo, alpha, x, a );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
