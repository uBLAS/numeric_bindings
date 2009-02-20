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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GEEVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GEEVX_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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
    inline void geevx( char const balanc, char const jobvl, char const jobvr,
            char const sense, integer_t const n, float* a,
            integer_t const lda, float* wr, float* wi, float* vl,
            integer_t const ldvl, float* vr, integer_t const ldvr,
            integer_t& ilo, integer_t& ihi, float* scale, float& abnrm,
            float* rconde, float* rcondv, float* work, integer_t const lwork,
            integer_t* iwork, integer_t& info ) {
        LAPACK_SGEEVX( &balanc, &jobvl, &jobvr, &sense, &n, a, &lda, wr, wi,
                vl, &ldvl, vr, &ldvr, &ilo, &ihi, scale, &abnrm, rconde,
                rcondv, work, &lwork, iwork, &info );
    }
    inline void geevx( char const balanc, char const jobvl, char const jobvr,
            char const sense, integer_t const n, double* a,
            integer_t const lda, double* wr, double* wi, double* vl,
            integer_t const ldvl, double* vr, integer_t const ldvr,
            integer_t& ilo, integer_t& ihi, double* scale, double& abnrm,
            double* rconde, double* rcondv, double* work,
            integer_t const lwork, integer_t* iwork, integer_t& info ) {
        LAPACK_DGEEVX( &balanc, &jobvl, &jobvr, &sense, &n, a, &lda, wr, wi,
                vl, &ldvl, vr, &ldvr, &ilo, &ihi, scale, &abnrm, rconde,
                rcondv, work, &lwork, iwork, &info );
    }
    inline void geevx( char const balanc, char const jobvl, char const jobvr,
            char const sense, integer_t const n, traits::complex_f* a,
            integer_t const lda, traits::complex_f* w, traits::complex_f* vl,
            integer_t const ldvl, traits::complex_f* vr, integer_t const ldvr,
            integer_t& ilo, integer_t& ihi, float* scale, float& abnrm,
            float* rconde, float* rcondv, traits::complex_f* work,
            integer_t const lwork, float* rwork, integer_t& info ) {
        LAPACK_CGEEVX( &balanc, &jobvl, &jobvr, &sense, &n,
                traits::complex_ptr(a), &lda, traits::complex_ptr(w),
                traits::complex_ptr(vl), &ldvl, traits::complex_ptr(vr),
                &ldvr, &ilo, &ihi, scale, &abnrm, rconde, rcondv,
                traits::complex_ptr(work), &lwork, rwork, &info );
    }
    inline void geevx( char const balanc, char const jobvl, char const jobvr,
            char const sense, integer_t const n, traits::complex_d* a,
            integer_t const lda, traits::complex_d* w, traits::complex_d* vl,
            integer_t const ldvl, traits::complex_d* vr, integer_t const ldvr,
            integer_t& ilo, integer_t& ihi, double* scale, double& abnrm,
            double* rconde, double* rcondv, traits::complex_d* work,
            integer_t const lwork, double* rwork, integer_t& info ) {
        LAPACK_ZGEEVX( &balanc, &jobvl, &jobvr, &sense, &n,
                traits::complex_ptr(a), &lda, traits::complex_ptr(w),
                traits::complex_ptr(vl), &ldvl, traits::complex_ptr(vr),
                &ldvr, &ilo, &ihi, scale, &abnrm, rconde, rcondv,
                traits::complex_ptr(work), &lwork, rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct geevx_impl{};

// real specialization
template< typename ValueType >
struct geevx_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVL, typename MatrixVR, typename VectorSCALE,
            typename VectorRCONDE, typename VectorRCONDV, typename WORK,
            typename IWORK >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorWR& wr,
            VectorWI& wi, MatrixVL& vl, MatrixVR& vr, integer_t& ilo,
            integer_t& ihi, VectorSCALE& scale, real_type& abnrm,
            VectorRCONDE& rconde, VectorRCONDV& rcondv, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
#ifndef NDEBUG
        assert( balanc == 'N' || balanc == 'P' || balanc == 'S' ||
                balanc == 'B' );
        assert( jobvl == 'N' || jobvl == 'V' || jobvl == 'E' || jobvl == 'B' );
        assert( jobvr == 'N' || jobvr == 'V' || jobvr == 'E' || jobvr == 'B' );
        assert( sense == 'N' || sense == 'E' || sense == 'V' || sense == 'B' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(wr) >= traits::matrix_size2(a) );
        assert( traits::vector_size(wi) >= traits::matrix_size2(a) );
        assert( traits::vector_size(rconde) >= traits::matrix_size2(a) );
        assert( traits::vector_size(rcondv) >= traits::matrix_size2(a) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                sense, jobvl, jobvr, traits::matrix_size2(a) )));
        assert( traits::vector_size(work.select(integer_t()) >=
                min_size_iwork( sense, traits::matrix_size2(a) )));
#endif
        detail::geevx( balanc, jobvl, jobvr, sense, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::vector_storage(wr), traits::vector_storage(wi),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                ilo, ihi, traits::vector_storage(scale), abnrm,
                traits::vector_storage(rconde),
                traits::vector_storage(rcondv),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVL, typename MatrixVR, typename VectorSCALE,
            typename VectorRCONDE, typename VectorRCONDV >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorWR& wr,
            VectorWI& wi, MatrixVL& vl, MatrixVR& vr, integer_t& ilo,
            integer_t& ihi, VectorSCALE& scale, real_type& abnrm,
            VectorRCONDE& rconde, VectorRCONDV& rcondv, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( sense,
                jobvl, jobvr, traits::matrix_size2(a) ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( sense,
                traits::matrix_size2(a) ) );
        compute( balanc, jobvl, jobvr, sense, a, wr, wi, vl, vr, ilo, ihi,
                scale, abnrm, rconde, rcondv, info, workspace( tmp_work,
                tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVL, typename MatrixVR, typename VectorSCALE,
            typename VectorRCONDE, typename VectorRCONDV >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorWR& wr,
            VectorWI& wi, MatrixVL& vl, MatrixVR& vr, integer_t& ilo,
            integer_t& ihi, VectorSCALE& scale, real_type& abnrm,
            VectorRCONDE& rconde, VectorRCONDV& rcondv, integer_t& info,
            optimal_workspace work ) {
        real_type opt_size_work;
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( sense,
                traits::matrix_size2(a) ) );
        detail::geevx( balanc, jobvl, jobvr, sense,
                traits::matrix_size2(a), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(wr),
                traits::vector_storage(wi), traits::matrix_storage(vl),
                traits::leading_dimension(vl), traits::matrix_storage(vr),
                traits::leading_dimension(vr), ilo, ihi,
                traits::vector_storage(scale), abnrm,
                traits::vector_storage(rconde),
                traits::vector_storage(rcondv), &opt_size_work, -1,
                traits::vector_storage(tmp_iwork), info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( balanc, jobvl, jobvr, sense, a, wr, wi, vl, vr, ilo, ihi,
                scale, abnrm, rconde, rcondv, info, workspace( tmp_work,
                tmp_iwork ) );
    }

    static integer_t min_size_work( char const sense, char const jobvl,
            char const jobvr, integer_t const n ) {
        if ( sense == 'N' || sense == 'E' ) {
            if ( jobvl =='V' || jobvr == 'V' )
                return std::max( 1, 3*n );
            else
                return std::max( 1, 2*n );
        } else
            return std::max( 1, n*(n+6) );
    }

    static integer_t min_size_iwork( char const sense, integer_t const n ) {
        if ( sense == 'N' || sense == 'E' )
            return 0;
        else
            return 2*n-2;
    }
};

// complex specialization
template< typename ValueType >
struct geevx_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVL,
            typename MatrixVR, typename VectorSCALE, typename VectorRCONDE,
            typename VectorRCONDV, typename WORK, typename RWORK >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorW& w,
            MatrixVL& vl, MatrixVR& vr, integer_t& ilo, integer_t& ihi,
            VectorSCALE& scale, real_type& abnrm, VectorRCONDE& rconde,
            VectorRCONDV& rcondv, integer_t& info, detail::workspace2< WORK,
            RWORK > work ) {
#ifndef NDEBUG
        assert( balanc == 'N' || balanc == 'P' || balanc == 'S' ||
                balanc == 'B' );
        assert( jobvl == 'N' || jobvl == 'V' || jobvl == 'E' || jobvl == 'B' );
        assert( jobvr == 'N' || jobvr == 'V' || jobvr == 'E' || jobvr == 'B' );
        assert( sense == 'N' || sense == 'E' || sense == 'V' || sense == 'B' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(w) >= traits::matrix_size2(a) );
        assert( traits::vector_size(rconde) >= traits::matrix_size2(a) );
        assert( traits::vector_size(rcondv) >= traits::matrix_size2(a) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( sense, traits::matrix_size2(a) )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( traits::matrix_size2(a) )));
#endif
        detail::geevx( balanc, jobvl, jobvr, sense, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::vector_storage(w), traits::matrix_storage(vl),
                traits::leading_dimension(vl), traits::matrix_storage(vr),
                traits::leading_dimension(vr), ilo, ihi,
                traits::vector_storage(scale), abnrm,
                traits::vector_storage(rconde),
                traits::vector_storage(rcondv),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVL,
            typename MatrixVR, typename VectorSCALE, typename VectorRCONDE,
            typename VectorRCONDV >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorW& w,
            MatrixVL& vl, MatrixVR& vr, integer_t& ilo, integer_t& ihi,
            VectorSCALE& scale, real_type& abnrm, VectorRCONDE& rconde,
            VectorRCONDV& rcondv, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( sense,
                traits::matrix_size2(a) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_size2(a) ) );
        compute( balanc, jobvl, jobvr, sense, a, w, vl, vr, ilo, ihi, scale,
                abnrm, rconde, rcondv, info, workspace( tmp_work,
                tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVL,
            typename MatrixVR, typename VectorSCALE, typename VectorRCONDE,
            typename VectorRCONDV >
    static void compute( char const balanc, char const jobvl,
            char const jobvr, char const sense, MatrixA& a, VectorW& w,
            MatrixVL& vl, MatrixVR& vr, integer_t& ilo, integer_t& ihi,
            VectorSCALE& scale, real_type& abnrm, VectorRCONDE& rconde,
            VectorRCONDV& rcondv, integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_size2(a) ) );
        detail::geevx( balanc, jobvl, jobvr, sense,
                traits::matrix_size2(a), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(w),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                ilo, ihi, traits::vector_storage(scale), abnrm,
                traits::vector_storage(rconde),
                traits::vector_storage(rcondv), &opt_size_work, -1,
                traits::vector_storage(tmp_rwork), info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( balanc, jobvl, jobvr, sense, a, w, vl, vr, ilo, ihi, scale,
                abnrm, rconde, rcondv, info, workspace( tmp_work,
                tmp_rwork ) );
    }

    static integer_t min_size_work( char const sense, integer_t const n ) {
        if ( sense == 'N' || sense == 'E' )
            return std::max( 1, 2*n );
        else
            return std::max( 1, n*n + 2*n );
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 2*n;
    }
};


// template function to call geevx
template< typename MatrixA, typename VectorWR, typename VectorWI,
        typename MatrixVL, typename MatrixVR, typename VectorSCALE,
        typename VectorRCONDE, typename VectorRCONDV, typename Workspace >
inline integer_t geevx( char const balanc, char const jobvl,
        char const jobvr, char const sense, MatrixA& a, VectorWR& wr,
        VectorWI& wi, MatrixVL& vl, MatrixVR& vr, integer_t& ilo,
        integer_t& ihi, VectorSCALE& scale,
        typename traits::matrix_traits< MatrixA >::value_type& abnrm,
        VectorRCONDE& rconde, VectorRCONDV& rcondv,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geevx_impl< value_type >::compute( balanc, jobvl, jobvr, sense, a,
            wr, wi, vl, vr, ilo, ihi, scale, abnrm, rconde, rcondv, info,
            work );
    return info;
}

// template function to call geevx
template< typename MatrixA, typename VectorW, typename MatrixVL,
        typename MatrixVR, typename VectorSCALE, typename VectorRCONDE,
        typename VectorRCONDV, typename Workspace >
inline integer_t geevx( char const balanc, char const jobvl,
        char const jobvr, char const sense, MatrixA& a, VectorW& w,
        MatrixVL& vl, MatrixVR& vr, integer_t& ilo, integer_t& ihi,
        VectorSCALE& scale,
        typename traits::matrix_traits< MatrixA >::value_type& abnrm,
        VectorRCONDE& rconde, VectorRCONDV& rcondv,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geevx_impl< value_type >::compute( balanc, jobvl, jobvr, sense, a, w,
            vl, vr, ilo, ihi, scale, abnrm, rconde, rcondv, info, work );
    return info;
}


}}}} // namespace boost::numeric::bindings::lapack

#endif
