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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_SPTRS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_SPTRS_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void sptrs( char const uplo, integer_t const n,
            integer_t const nrhs, float* ap, integer_t* ipiv, float* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_SSPTRS( &uplo, &n, &nrhs, ap, ipiv, b, &ldb, &info );
    }
    inline void sptrs( char const uplo, integer_t const n,
            integer_t const nrhs, double* ap, integer_t* ipiv, double* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_DSPTRS( &uplo, &n, &nrhs, ap, ipiv, b, &ldb, &info );
    }
    inline void sptrs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_f* ap, integer_t* ipiv,
            traits::complex_f* b, integer_t const ldb, integer_t& info ) {
        LAPACK_CSPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap), ipiv,
                traits::complex_ptr(b), &ldb, &info );
    }
    inline void sptrs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_d* ap, integer_t* ipiv,
            traits::complex_d* b, integer_t const ldb, integer_t& info ) {
        LAPACK_ZSPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap), ipiv,
                traits::complex_ptr(b), &ldb, &info );
    }
}

// value-type based template
template< typename ValueType >
struct sptrs_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename MatrixAP, typename VectorIPIV, typename MatrixB >
    static void compute( char const uplo, integer_t const n, MatrixAP& ap,
            VectorIPIV& ipiv, MatrixB& b, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_ASSERT( uplo == 'U' || uplo == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::vector_size(ap) >= n*(n+1)/2 );
        BOOST_ASSERT( traits::vector_size(ipiv) >= n );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        detail::sptrs( uplo, n, traits::matrix_num_columns(b),
                traits::matrix_storage(ap), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};


// template function to call sptrs
template< typename MatrixAP, typename VectorIPIV, typename MatrixB >
inline integer_t sptrs( char const uplo, integer_t const n, MatrixAP& ap,
        VectorIPIV& ipiv, MatrixB& b ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    sptrs_impl< value_type >::compute( uplo, n, ap, ipiv, b, info );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
