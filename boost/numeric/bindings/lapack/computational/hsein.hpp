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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HSEIN_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HSEIN_HPP

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
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void hsein( char const side, char const eigsrc, char const initv,
            logical_t* select, integer_t const n, float* h,
            integer_t const ldh, float* wr, float* wi, float* vl,
            integer_t const ldvl, float* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, float* work, integer_t* ifaill,
            integer_t* ifailr, integer_t& info ) {
        LAPACK_SHSEIN( &side, &eigsrc, &initv, select, &n, h, &ldh, wr, wi,
                vl, &ldvl, vr, &ldvr, &mm, &m, work, ifaill, ifailr, &info );
    }
    inline void hsein( char const side, char const eigsrc, char const initv,
            logical_t* select, integer_t const n, double* h,
            integer_t const ldh, double* wr, double* wi, double* vl,
            integer_t const ldvl, double* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, double* work, integer_t* ifaill,
            integer_t* ifailr, integer_t& info ) {
        LAPACK_DHSEIN( &side, &eigsrc, &initv, select, &n, h, &ldh, wr, wi,
                vl, &ldvl, vr, &ldvr, &mm, &m, work, ifaill, ifailr, &info );
    }
    inline void hsein( char const side, char const eigsrc, char const initv,
            logical_t* select, integer_t const n, traits::complex_f* h,
            integer_t const ldh, traits::complex_f* w, traits::complex_f* vl,
            integer_t const ldvl, traits::complex_f* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, traits::complex_f* work,
            float* rwork, integer_t* ifaill, integer_t* ifailr,
            integer_t& info ) {
        LAPACK_CHSEIN( &side, &eigsrc, &initv, select, &n,
                traits::complex_ptr(h), &ldh, traits::complex_ptr(w),
                traits::complex_ptr(vl), &ldvl, traits::complex_ptr(vr),
                &ldvr, &mm, &m, traits::complex_ptr(work), rwork, ifaill,
                ifailr, &info );
    }
    inline void hsein( char const side, char const eigsrc, char const initv,
            logical_t* select, integer_t const n, traits::complex_d* h,
            integer_t const ldh, traits::complex_d* w, traits::complex_d* vl,
            integer_t const ldvl, traits::complex_d* vr, integer_t const ldvr,
            integer_t const mm, integer_t& m, traits::complex_d* work,
            double* rwork, integer_t* ifaill, integer_t* ifailr,
            integer_t& info ) {
        LAPACK_ZHSEIN( &side, &eigsrc, &initv, select, &n,
                traits::complex_ptr(h), &ldh, traits::complex_ptr(w),
                traits::complex_ptr(vl), &ldvl, traits::complex_ptr(vr),
                &ldvr, &mm, &m, traits::complex_ptr(work), rwork, ifaill,
                ifailr, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct hsein_impl{};

// real specialization
template< typename ValueType >
struct hsein_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorWR,
            typename VectorWI, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR, typename WORK >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorWR& wr, VectorWI& wi,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::vector_traits<
                VectorWR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::vector_traits<
                VectorWI >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorIFAILL >::value_type, typename traits::vector_traits<
                VectorIFAILR >::value_type >::value) );
#ifndef NDEBUG
        assert( side == 'R' || side == 'L' || side == 'B' );
        assert( eigsrc == 'Q' || eigsrc == 'N' );
        assert( initv == 'N' || initv == 'U' );
        assert( traits::vector_size(select) >= traits::matrix_num_columns(h) );
        assert( traits::matrix_num_columns(h) >= 0 );
        assert( traits::leading_dimension(h) >= std::max(1,
                traits::matrix_num_columns(h)) );
        assert( traits::vector_size(wr) >= traits::matrix_num_columns(h) );
        assert( traits::vector_size(wi) >= traits::matrix_num_columns(h) );
        assert( mm >= m );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                traits::matrix_num_columns(h), ?2 )));
#endif
        detail::hsein( side, eigsrc, initv, traits::vector_storage(select),
                traits::matrix_num_columns(h), traits::matrix_storage(h),
                traits::leading_dimension(h), traits::vector_storage(wr),
                traits::vector_storage(wi), traits::matrix_storage(vl),
                traits::leading_dimension(vl), traits::matrix_storage(vr),
                traits::leading_dimension(vr), mm, m,
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(ifaill),
                traits::vector_storage(ifailr), info );
    }

    // minimal workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorWR,
            typename VectorWI, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorWR& wr, VectorWI& wi,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                traits::matrix_num_columns(h), ?2 ) );
        compute( side, eigsrc, initv, select, h, wr, wi, vl, vr, mm, m,
                ifaill, ifailr, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorWR,
            typename VectorWI, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorWR& wr, VectorWI& wi,
            MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            optimal_workspace work ) {
        compute( side, eigsrc, initv, select, h, wr, wi, vl, vr, mm, m,
                ifaill, ifailr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n, ?? ) {
        return (n+2)*n;
    }
};

// complex specialization
template< typename ValueType >
struct hsein_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorW,
            typename MatrixVL, typename MatrixVR, typename VectorIFAILL,
            typename VectorIFAILR, typename WORK, typename RWORK >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorW& w, MatrixVL& vl,
            MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorIFAILL >::value_type, typename traits::vector_traits<
                VectorIFAILR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixH >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type >::value) );
#ifndef NDEBUG
        assert( side == 'R' || side == 'L' || side == 'B' );
        assert( eigsrc == 'Q' || eigsrc == 'N' );
        assert( initv == 'N' || initv == 'U' );
        assert( traits::vector_size(select) >= traits::matrix_num_columns(h) );
        assert( traits::matrix_num_columns(h) >= 0 );
        assert( traits::leading_dimension(h) >= std::max(1,
                traits::matrix_num_columns(h)) );
        assert( traits::vector_size(w) >= traits::matrix_num_columns(h) );
        assert( mm >= m );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( traits::matrix_num_columns(h) )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( traits::matrix_num_columns(h) )));
#endif
        detail::hsein( side, eigsrc, initv, traits::vector_storage(select),
                traits::matrix_num_columns(h), traits::matrix_storage(h),
                traits::leading_dimension(h), traits::vector_storage(w),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr), mm,
                m, traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(ifaill),
                traits::vector_storage(ifailr), info );
    }

    // minimal workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorW,
            typename MatrixVL, typename MatrixVR, typename VectorIFAILL,
            typename VectorIFAILR >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorW& w, MatrixVL& vl,
            MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_num_columns(h) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(h) ) );
        compute( side, eigsrc, initv, select, h, w, vl, vr, mm, m, ifaill,
                ifailr, info, workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename VectorSELECT, typename MatrixH, typename VectorW,
            typename MatrixVL, typename MatrixVR, typename VectorIFAILL,
            typename VectorIFAILR >
    static void compute( char const side, char const eigsrc, char const initv,
            VectorSELECT& select, MatrixH& h, VectorW& w, MatrixVL& vl,
            MatrixVR& vr, integer_t const mm, integer_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, integer_t& info,
            optimal_workspace work ) {
        compute( side, eigsrc, initv, select, h, w, vl, vr, mm, m, ifaill,
                ifailr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return n*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }
};


// template function to call hsein
template< typename VectorSELECT, typename MatrixH, typename VectorWR,
        typename VectorWI, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR, typename Workspace >
inline integer_t hsein( char const side, char const eigsrc,
        char const initv, VectorSELECT& select, MatrixH& h, VectorWR& wr,
        VectorWI& wi, MatrixVL& vl, MatrixVR& vr, integer_t const mm,
        integer_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits<
            VectorSELECT >::value_type value_type;
    integer_t info(0);
    hsein_impl< value_type >::compute( side, eigsrc, initv, select, h,
            wr, wi, vl, vr, mm, m, ifaill, ifailr, info, work );
    return info;
}
// template function to call hsein
template< typename VectorSELECT, typename MatrixH, typename VectorW,
        typename MatrixVL, typename MatrixVR, typename VectorIFAILL,
        typename VectorIFAILR, typename Workspace >
inline integer_t hsein( char const side, char const eigsrc,
        char const initv, VectorSELECT& select, MatrixH& h, VectorW& w,
        MatrixVL& vl, MatrixVR& vr, integer_t const mm, integer_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits<
            VectorSELECT >::value_type value_type;
    integer_t info(0);
    hsein_impl< value_type >::compute( side, eigsrc, initv, select, h, w,
            vl, vr, mm, m, ifaill, ifailr, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
