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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HBEVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HBEVX_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
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
    inline void hbevx( char const jobz, char const range, char const uplo,
            integer_t const n, integer_t const kd, traits::complex_f* ab,
            integer_t const ldab, traits::complex_f* q, integer_t const ldq,
            float const vl, float const vu, integer_t const il,
            integer_t const iu, float const abstol, integer_t& m, float* w,
            traits::complex_f* z, integer_t const ldz,
            traits::complex_f* work, float* rwork, integer_t* iwork,
            integer_t* ifail, integer_t& info ) {
        LAPACK_CHBEVX( &jobz, &range, &uplo, &n, &kd, traits::complex_ptr(ab),
                &ldab, traits::complex_ptr(q), &ldq, &vl, &vu, &il, &iu,
                &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
    inline void hbevx( char const jobz, char const range, char const uplo,
            integer_t const n, integer_t const kd, traits::complex_d* ab,
            integer_t const ldab, traits::complex_d* q, integer_t const ldq,
            double const vl, double const vu, integer_t const il,
            integer_t const iu, double const abstol, integer_t& m, double* w,
            traits::complex_d* z, integer_t const ldz,
            traits::complex_d* work, double* rwork, integer_t* iwork,
            integer_t* ifail, integer_t& info ) {
        LAPACK_ZHBEVX( &jobz, &range, &uplo, &n, &kd, traits::complex_ptr(ab),
                &ldab, traits::complex_ptr(q), &ldq, &vl, &vu, &il, &iu,
                &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
}

// value-type based template
template< typename ValueType >
struct hbevx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL, typename WORK,
            typename RWORK, typename IWORK >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const kd, MatrixAB& ab, MatrixQ& q, real_type const vl,
            real_type const vu, integer_t const il, integer_t const iu,
            real_type const abstol, integer_t& m, VectorW& w, MatrixZ& z,
            VectorIFAIL& ifail, integer_t& info, detail::workspace3< WORK,
            RWORK, IWORK > work ) {
#ifndef NDEBUG
        assert( jobz == 'N' || jobz == 'V' );
        assert( range == 'A' || range == 'V' || range == 'I' );
        assert( traits::matrix_uplo_tag(ab) == 'U' ||
                traits::matrix_uplo_tag(ab) == 'L' );
        assert( n >= 0 );
        assert( kd >= 0 );
        assert( traits::leading_dimension(ab) >= kd );
        assert( traits::leading_dimension(q) >= std::max(1,n) );
        assert( traits::vector_size(w) >= n );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( n )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( n )));
        assert( traits::vector_size(work.select(integer_t()) >=
                min_size_iwork( n )));
#endif
        detail::hbevx( jobz, range, traits::matrix_uplo_tag(ab), n, kd,
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(q), traits::leading_dimension(q), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const kd, MatrixAB& ab, MatrixQ& q, real_type const vl,
            real_type const vu, integer_t const il, integer_t const iu,
            real_type const abstol, integer_t& m, VectorW& w, MatrixZ& z,
            VectorIFAIL& ifail, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        compute( jobz, range, n, kd, ab, q, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixQ, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const kd, MatrixAB& ab, MatrixQ& q, real_type const vl,
            real_type const vu, integer_t const il, integer_t const iu,
            real_type const abstol, integer_t& m, VectorW& w, MatrixZ& z,
            VectorIFAIL& ifail, integer_t& info, optimal_workspace work ) {
        compute( jobz, range, n, kd, ab, q, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 7*n;
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return 5*n;
    }
};


// template function to call hbevx
template< typename MatrixAB, typename MatrixQ, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline integer_t hbevx( char const jobz, char const range,
        integer_t const n, integer_t const kd, MatrixAB& ab, MatrixQ& q,
        typename traits::matrix_traits< MatrixAB >::value_type const vl,
        typename traits::matrix_traits< MatrixAB >::value_type const vu,
        integer_t const il, integer_t const iu,
        typename traits::matrix_traits< MatrixAB >::value_type const abstol,
        integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    hbevx_impl< value_type >::compute( jobz, range, n, kd, ab, q, vl, vu,
            il, iu, abstol, m, w, z, ifail, info, work );
    return info;
}


}}}} // namespace boost::numeric::bindings::lapack

#endif
