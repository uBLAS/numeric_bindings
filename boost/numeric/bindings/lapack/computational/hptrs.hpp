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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HPTRS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HPTRS_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void hptrs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_f* ap, integer_t* ipiv,
            traits::complex_f* b, integer_t const ldb, integer_t& info ) {
        LAPACK_CHPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap), ipiv,
                traits::complex_ptr(b), &ldb, &info );
    }
    inline void hptrs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_d* ap, integer_t* ipiv,
            traits::complex_d* b, integer_t const ldb, integer_t& info ) {
        LAPACK_ZHPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap), ipiv,
                traits::complex_ptr(b), &ldb, &info );
    }
}

// value-type based template
template< typename ValueType >
struct hptrs_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename MatrixAP, typename VectorIPIV, typename MatrixB >
    static void compute( char const uplo, integer_t const n, MatrixAP& ap,
            VectorIPIV& ipiv, MatrixB& b, integer_t& info ) {
#ifndef NDEBUG
        assert( uplo == 'U' || uplo == 'L' );
        assert( n >= 0 );
        assert( traits::matrix_size2(b) >= 0 );
        assert( traits::vector_size(ap) >= n*(n+1)/2 );
        assert( traits::vector_size(ipiv) >= n );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
#endif
        detail::hptrs( uplo, n, traits::matrix_size2(b),
                traits::matrix_storage(ap), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};


// template function to call hptrs
template< typename MatrixAP, typename VectorIPIV, typename MatrixB >
inline integer_t hptrs( char const uplo, integer_t const n, MatrixAP& ap,
        VectorIPIV& ipiv, MatrixB& b ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    hptrs_impl< value_type >::compute( uplo, n, ap, ipiv, b, info );
    return info;
}


}}}} // namespace boost::numeric::bindings::lapack

#endif
