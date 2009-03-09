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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GBSVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GBSVX_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void gbsvx( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            float* ab, integer_t const ldab, float* afb,
            integer_t const ldafb, integer_t* ipiv, char& equed, float* r,
            float* c, float* b, integer_t const ldb, float* x,
            integer_t const ldx, float& rcond, float* ferr, float* berr,
            float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SGBSVX( &fact, &trans, &n, &kl, &ku, &nrhs, ab, &ldab, afb,
                &ldafb, ipiv, &equed, r, c, b, &ldb, x, &ldx, &rcond, ferr,
                berr, work, iwork, &info );
    }
    inline void gbsvx( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            double* ab, integer_t const ldab, double* afb,
            integer_t const ldafb, integer_t* ipiv, char& equed, double* r,
            double* c, double* b, integer_t const ldb, double* x,
            integer_t const ldx, double& rcond, double* ferr, double* berr,
            double* work, integer_t* iwork, integer_t& info ) {
        LAPACK_DGBSVX( &fact, &trans, &n, &kl, &ku, &nrhs, ab, &ldab, afb,
                &ldafb, ipiv, &equed, r, c, b, &ldb, x, &ldx, &rcond, ferr,
                berr, work, iwork, &info );
    }
    inline void gbsvx( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            traits::complex_f* ab, integer_t const ldab,
            traits::complex_f* afb, integer_t const ldafb, integer_t* ipiv,
            char& equed, float* r, float* c, traits::complex_f* b,
            integer_t const ldb, traits::complex_f* x, integer_t const ldx,
            float& rcond, float* ferr, float* berr, traits::complex_f* work,
            float* rwork, integer_t& info ) {
        LAPACK_CGBSVX( &fact, &trans, &n, &kl, &ku, &nrhs,
                traits::complex_ptr(ab), &ldab, traits::complex_ptr(afb),
                &ldafb, ipiv, &equed, r, c, traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, &rcond, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
    inline void gbsvx( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, integer_t const nrhs,
            traits::complex_d* ab, integer_t const ldab,
            traits::complex_d* afb, integer_t const ldafb, integer_t* ipiv,
            char& equed, double* r, double* c, traits::complex_d* b,
            integer_t const ldb, traits::complex_d* x, integer_t const ldx,
            double& rcond, double* ferr, double* berr,
            traits::complex_d* work, double* rwork, integer_t& info ) {
        LAPACK_ZGBSVX( &fact, &trans, &n, &kl, &ku, &nrhs,
                traits::complex_ptr(ab), &ldab, traits::complex_ptr(afb),
                &ldafb, ipiv, &equed, r, c, traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, &rcond, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gbsvx_impl{};

// real specialization
template< typename ValueType >
struct gbsvx_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename IWORK >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixAFB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::vector_traits<
                VectorR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::vector_traits<
                VectorC >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_ASSERT( fact == 'F' || fact == 'N' || fact == 'E' );
        BOOST_ASSERT( trans == 'N' || trans == 'T' || trans == 'C' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( kl >= 0 );
        BOOST_ASSERT( ku >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(x) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(ab) >= kl+ku+1 );
        BOOST_ASSERT( traits::leading_dimension(afb) >= 2 );
        BOOST_ASSERT( equed == 'N' || equed == 'R' || equed == 'C' ||
                equed == 'B' );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(x) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::gbsvx( fact, trans, n, kl, ku, traits::matrix_num_columns(x),
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(afb), traits::leading_dimension(afb),
                traits::vector_storage(ipiv), equed,
                traits::vector_storage(r), traits::vector_storage(c),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        compute( fact, trans, n, kl, ku, ab, afb, ipiv, equed, r, c, b, x,
                rcond, ferr, berr, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( fact, trans, n, kl, ku, ab, afb, ipiv, equed, r, c, b, x,
                rcond, ferr, berr, info, minimal_workspace() );
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
struct gbsvx_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename RWORK >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorC >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixAFB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_ASSERT( fact == 'F' || fact == 'N' || fact == 'E' );
        BOOST_ASSERT( trans == 'N' || trans == 'T' || trans == 'C' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( kl >= 0 );
        BOOST_ASSERT( ku >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(x) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(ab) >= kl+ku+1 );
        BOOST_ASSERT( traits::leading_dimension(afb) >= 2 );
        BOOST_ASSERT( equed == 'N' || equed == 'R' || equed == 'C' ||
                equed == 'B' );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(x) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        detail::gbsvx( fact, trans, n, kl, ku, traits::matrix_num_columns(x),
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(afb), traits::leading_dimension(afb),
                traits::vector_storage(ipiv), equed,
                traits::vector_storage(r), traits::vector_storage(c),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        compute( fact, trans, n, kl, ku, ab, afb, ipiv, equed, r, c, b, x,
                rcond, ferr, berr, info, workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, integer_t const n,
            integer_t const kl, integer_t const ku, MatrixAB& ab,
            MatrixAFB& afb, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( fact, trans, n, kl, ku, ab, afb, ipiv, equed, r, c, b, x,
                rcond, ferr, berr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }
};


// template function to call gbsvx
template< typename MatrixAB, typename MatrixAFB, typename VectorIPIV,
        typename VectorR, typename VectorC, typename MatrixB,
        typename MatrixX, typename VectorFERR, typename VectorBERR,
        typename Workspace >
inline integer_t gbsvx( char const fact, char const trans,
        integer_t const n, integer_t const kl, integer_t const ku,
        MatrixAB& ab, MatrixAFB& afb, VectorIPIV& ipiv, char& equed,
        VectorR& r, VectorC& c, MatrixB& b, MatrixX& x,
        typename traits::matrix_traits< MatrixAB >::value_type& rcond,
        VectorFERR& ferr, VectorBERR& berr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    gbsvx_impl< value_type >::compute( fact, trans, n, kl, ku, ab, afb,
            ipiv, equed, r, c, b, x, rcond, ferr, berr, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
