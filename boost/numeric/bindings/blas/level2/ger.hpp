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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_GER_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_GER_HPP

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
    inline void ger( integer_t const m, integer_t const n, float const alpha,
            float* x, integer_t const incx, float* y, integer_t const incy,
            float* a, integer_t const lda ) {
        BLAS_SGER( &m, &n, &alpha, x, &incx, y, &incy, a, &lda );
    }
    inline void ger( integer_t const m, integer_t const n, double const alpha,
            double* x, integer_t const incx, double* y, integer_t const incy,
            double* a, integer_t const lda ) {
        BLAS_DGER( &m, &n, &alpha, x, &incx, y, &incy, a, &lda );
    }
}

// value-type based template
template< typename ValueType >
struct ger_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename VectorY, typename MatrixA >
    static return_type compute( real_type const alpha, VectorX& x, VectorY& y,
            MatrixA& a ) {
        detail::ger( traits::matrix_size1(a), traits::matrix_size2(a),
                alpha, traits::vector_storage(x), traits::vector_stride(x),
                traits::vector_storage(y), traits::vector_stride(y),
                traits::matrix_storage(a), traits::leading_dimension(a) );
    }
};

// template function to call ger
template< typename VectorX, typename VectorY, typename MatrixA >

        inline integer_t ger( typename traits::vector_traits< VectorX >::value_type const alpha,
        VectorX& x, VectorY& y, MatrixA& a ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    ger_impl< value_type >::compute( alpha, x, y, a );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
