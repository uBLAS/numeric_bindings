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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HETRF_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HETRF_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void hetrf( char const uplo, integer_t const n,
            traits::complex_f* a, integer_t const lda, integer_t* ipiv,
            traits::complex_f* work, integer_t const lwork, integer_t& info ) {
        LAPACK_CHETRF( &uplo, &n, traits::complex_ptr(a), &lda, ipiv,
                traits::complex_ptr(work), &lwork, &info );
    }
    inline void hetrf( char const uplo, integer_t const n,
            traits::complex_d* a, integer_t const lda, integer_t* ipiv,
            traits::complex_d* work, integer_t const lwork, integer_t& info ) {
        LAPACK_ZHETRF( &uplo, &n, traits::complex_ptr(a), &lda, ipiv,
                traits::complex_ptr(work), &lwork, &info );
    }
}

// value-type based template
template< typename ValueType >
struct hetrf_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorIPIV, typename WORK >
    static void compute( MatrixA& a, VectorIPIV& ipiv, integer_t& info,
            detail::workspace1< WORK > work ) {
        
#ifndef NDEBUG
        assert( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        assert( traits::matrix_num_columns(a) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_num_columns(a)) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work(  )));
#endif
        detail::hetrf( traits::matrix_uplo_tag(a),
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(ipiv),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorIPIV >
    static void compute( MatrixA& a, VectorIPIV& ipiv, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(  ) );
        compute( a, ipiv, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorIPIV >
    static void compute( MatrixA& a, VectorIPIV& ipiv, integer_t& info,
            optimal_workspace work ) {
        compute( a, ipiv, info, minimal_workspace() );
    }

    static integer_t min_size_work(  ) {
        return 1;
    }
};


// template function to call hetrf
template< typename MatrixA, typename VectorIPIV, typename Workspace >
inline integer_t hetrf( MatrixA& a, VectorIPIV& ipiv,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    hetrf_impl< value_type >::compute( a, ipiv, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
