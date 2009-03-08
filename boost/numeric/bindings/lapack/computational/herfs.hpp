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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HERFS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HERFS_HPP

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
    inline void herfs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_f* a, integer_t const lda,
            traits::complex_f* af, integer_t const ldaf, integer_t* ipiv,
            traits::complex_f* b, integer_t const ldb, traits::complex_f* x,
            integer_t const ldx, float* ferr, float* berr,
            traits::complex_f* work, float* rwork, integer_t& info ) {
        LAPACK_CHERFS( &uplo, &n, &nrhs, traits::complex_ptr(a), &lda,
                traits::complex_ptr(af), &ldaf, ipiv, traits::complex_ptr(b),
                &ldb, traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
    inline void herfs( char const uplo, integer_t const n,
            integer_t const nrhs, traits::complex_d* a, integer_t const lda,
            traits::complex_d* af, integer_t const ldaf, integer_t* ipiv,
            traits::complex_d* b, integer_t const ldb, traits::complex_d* x,
            integer_t const ldx, double* ferr, double* berr,
            traits::complex_d* work, double* rwork, integer_t& info ) {
        LAPACK_ZHERFS( &uplo, &n, &nrhs, traits::complex_ptr(a), &lda,
                traits::complex_ptr(af), &ldaf, ipiv, traits::complex_ptr(b),
                &ldb, traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType >
struct herfs_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR, typename WORK, typename RWORK >
    static void compute( MatrixA& a, MatrixAF& af, VectorIPIV& ipiv,
            MatrixB& b, MatrixX& x, VectorFERR& ferr, VectorBERR& berr,
            integer_t& info, detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorFERR >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixAF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
#ifndef NDEBUG
        assert( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        assert( traits::matrix_num_columns(a) >= 0 );
        assert( traits::matrix_num_columns(x) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_num_columns(a)) );
        assert( traits::leading_dimension(af) >= std::max(1,
                traits::matrix_num_columns(a)) );
        assert( traits::vector_size(ipiv) >= traits::matrix_num_columns(a) );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_num_columns(a)) );
        assert( traits::leading_dimension(x) >= std::max(1,
                traits::matrix_num_columns(a)) );
        assert( traits::vector_size(berr) >= traits::matrix_num_columns(x) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( traits::matrix_num_columns(a) )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( traits::matrix_num_columns(a) )));
#endif
        detail::herfs( traits::matrix_uplo_tag(a),
                traits::matrix_num_columns(a), traits::matrix_num_columns(x),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(af), traits::leading_dimension(af),
                traits::vector_storage(ipiv), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(x),
                traits::leading_dimension(x), traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( MatrixA& a, MatrixAF& af, VectorIPIV& ipiv,
            MatrixB& b, MatrixX& x, VectorFERR& ferr, VectorBERR& berr,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_num_columns(a) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        compute( a, af, ipiv, b, x, ferr, berr, info, workspace( tmp_work,
                tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( MatrixA& a, MatrixAF& af, VectorIPIV& ipiv,
            MatrixB& b, MatrixX& x, VectorFERR& ferr, VectorBERR& berr,
            integer_t& info, optimal_workspace work ) {
        compute( a, af, ipiv, b, x, ferr, berr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }
};


// template function to call herfs
template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
        typename MatrixB, typename MatrixX, typename VectorFERR,
        typename VectorBERR, typename Workspace >
inline integer_t herfs( MatrixA& a, MatrixAF& af, VectorIPIV& ipiv,
        MatrixB& b, MatrixX& x, VectorFERR& ferr, VectorBERR& berr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    herfs_impl< value_type >::compute( a, af, ipiv, b, x, ferr, berr,
            info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
