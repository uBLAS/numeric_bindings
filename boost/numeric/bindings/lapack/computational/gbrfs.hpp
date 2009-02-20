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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GBRFS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GBRFS_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/utility/enable_if.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void gbrfs( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            float* ab, integer_t const ldab, float* afb,
            integer_t const ldafb, integer_t* ipiv, float* b,
            integer_t const ldb, float* x, integer_t const ldx, float* ferr,
            float* berr, float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SGBRFS( &trans, &n, &kl, &ku, &nrhs, ab, &ldab, afb, &ldafb,
                ipiv, b, &ldb, x, &ldx, ferr, berr, work, iwork, &info );
    }
    inline void gbrfs( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            double* ab, integer_t const ldab, double* afb,
            integer_t const ldafb, integer_t* ipiv, double* b,
            integer_t const ldb, double* x, integer_t const ldx, double* ferr,
            double* berr, double* work, integer_t* iwork, integer_t& info ) {
        LAPACK_DGBRFS( &trans, &n, &kl, &ku, &nrhs, ab, &ldab, afb, &ldafb,
                ipiv, b, &ldb, x, &ldx, ferr, berr, work, iwork, &info );
    }
    inline void gbrfs( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            traits::complex_f* ab, integer_t const ldab,
            traits::complex_f* afb, integer_t const ldafb, integer_t* ipiv,
            traits::complex_f* b, integer_t const ldb, traits::complex_f* x,
            integer_t const ldx, float* ferr, float* berr,
            traits::complex_f* work, float* rwork, integer_t& info ) {
        LAPACK_CGBRFS( &trans, &n, &kl, &ku, &nrhs, traits::complex_ptr(ab),
                &ldab, traits::complex_ptr(afb), &ldafb, ipiv,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
    inline void gbrfs( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            traits::complex_d* ab, integer_t const ldab,
            traits::complex_d* afb, integer_t const ldafb, integer_t* ipiv,
            traits::complex_d* b, integer_t const ldb, traits::complex_d* x,
            integer_t const ldx, double* ferr, double* berr,
            traits::complex_d* work, double* rwork, integer_t& info ) {
        LAPACK_ZGBRFS( &trans, &n, &kl, &ku, &nrhs, traits::complex_ptr(ab),
                &ldab, traits::complex_ptr(afb), &ldafb, ipiv,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gbrfs_impl{};

// real specialization
template< typename ValueType >
struct gbrfs_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR, typename WORK, typename IWORK >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
#ifndef NDEBUG
        assert( trans == 'N' || trans == 'T' || trans == 'C' );
        assert( n >= 0 );
        assert( kl >= 0 );
        assert( ku >= 0 );
        assert( traits::matrix_size2(x) >= 0 );
        assert( traits::leading_dimension(ab) >= kl+ku+1 );
        assert( traits::leading_dimension(afb) >= 2 );
        assert( traits::vector_size(ipiv) >= n );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
        assert( traits::leading_dimension(x) >= std::max(1,n) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(x) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                n )));
        assert( traits::vector_size(work.select(integer_t()) >=
                min_size_iwork( n )));
#endif
        detail::gbrfs( trans, n, kl, ku, traits::matrix_size2(x),
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(afb), traits::leading_dimension(afb),
                traits::vector_storage(ipiv), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(x),
                traits::leading_dimension(x), traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        compute( trans, n, kl, ku, ab, afb, ipiv, b, x, ferr, berr, info,
                workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( trans, n, kl, ku, ab, afb, ipiv, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 3*n;
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return n;
    }
};

// complex specialization
template< typename ValueType >
struct gbrfs_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR, typename WORK, typename RWORK >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
#ifndef NDEBUG
        assert( trans == 'N' || trans == 'T' || trans == 'C' );
        assert( n >= 0 );
        assert( kl >= 0 );
        assert( ku >= 0 );
        assert( traits::matrix_size2(x) >= 0 );
        assert( traits::leading_dimension(ab) >= kl+ku+1 );
        assert( traits::leading_dimension(afb) >= 2 );
        assert( traits::vector_size(ipiv) >= n );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
        assert( traits::leading_dimension(x) >= std::max(1,n) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(x) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( n )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( n )));
#endif
        detail::gbrfs( trans, n, kl, ku, traits::matrix_size2(x),
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(afb), traits::leading_dimension(afb),
                traits::vector_storage(ipiv), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(x),
                traits::leading_dimension(x), traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        compute( trans, n, kl, ku, ab, afb, ipiv, b, x, ferr, berr, info,
                workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void compute( char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( trans, n, kl, ku, ab, afb, ipiv, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }
};


// template function to call gbrfs
template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
        typename MatrixB, typename MatrixX, typename VectorFERR,
        typename VectorBERR, typename Workspace >
inline integer_t gbrfs( char const trans, integer_t const n,
        integer_t const kl, integer_t const ku, MatrixAB& ab, MatrixAFB& afb,
        VectorIPIV& ipiv, MatrixB& b, MatrixX& x, VectorFERR& ferr,
        VectorBERR& berr, Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    gbrfs_impl< value_type >::compute( trans, n, kl, ku, ab, afb, ipiv,
            b, x, ferr, berr, info, work );
    return info;
}


}}}} // namespace boost::numeric::bindings::lapack

#endif
