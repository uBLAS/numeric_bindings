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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_STEDC_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_STEDC_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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
    inline void stedc( char const compz, integer_t const n, float* d,
            float* e, float* z, integer_t const ldz, float* work,
            integer_t const lwork, integer_t* iwork, integer_t const liwork,
            integer_t& info ) {
        LAPACK_SSTEDC( &compz, &n, d, e, z, &ldz, work, &lwork, iwork,
                &liwork, &info );
    }
    inline void stedc( char const compz, integer_t const n, double* d,
            double* e, double* z, integer_t const ldz, double* work,
            integer_t const lwork, integer_t* iwork, integer_t const liwork,
            integer_t& info ) {
        LAPACK_DSTEDC( &compz, &n, d, e, z, &ldz, work, &lwork, iwork,
                &liwork, &info );
    }
    inline void stedc( char const compz, integer_t const n, float* d,
            float* e, traits::complex_f* z, integer_t const ldz,
            traits::complex_f* work, integer_t const lwork, float* rwork,
            integer_t const lrwork, integer_t* iwork, integer_t const liwork,
            integer_t& info ) {
        LAPACK_CSTEDC( &compz, &n, d, e, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), &lwork, rwork, &lrwork, iwork,
                &liwork, &info );
    }
    inline void stedc( char const compz, integer_t const n, double* d,
            double* e, traits::complex_d* z, integer_t const ldz,
            traits::complex_d* work, integer_t const lwork, double* rwork,
            integer_t const lrwork, integer_t* iwork, integer_t const liwork,
            integer_t& info ) {
        LAPACK_ZSTEDC( &compz, &n, d, e, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), &lwork, rwork, &lrwork, iwork,
                &liwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct stedc_impl{};

// real specialization
template< typename ValueType >
struct stedc_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ,
            typename WORK, typename IWORK >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, detail::workspace2< WORK,
            IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( compz == 'N' || compz == 'I' || compz == 'V' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(e) >= n-1 );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( compz, n ));
        detail::stedc( compz, n, traits::vector_storage(d),
                traits::vector_storage(e), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_size(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( compz,
                n ) );
        invoke( compz, n, d, e, z, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, optimal_workspace work ) {
        real_type opt_size_work;
        integer_t opt_size_iwork;
        detail::stedc( compz, n, traits::vector_storage(d),
                traits::vector_storage(e), traits::matrix_storage(z),
                traits::leading_dimension(z), &opt_size_work, -1,
                &opt_size_iwork, -1, info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        traits::detail::array< integer_t > tmp_iwork( opt_size_iwork );
        invoke( compz, n, d, e, z, info, workspace( tmp_work, tmp_iwork ) );
    }

    static integer_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE
    }

    static integer_t min_size_iwork( char const compz, integer_t const n ) {
        // some formula
    }
};

// complex specialization
template< typename ValueType >
struct stedc_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ,
            typename WORK, typename RWORK, typename IWORK >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, detail::workspace3< WORK,
            RWORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_ASSERT( compz == 'N' || compz == 'I' || compz == 'V' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(e) >= n-1 );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( $CALL_MIN_SIZE ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( compz, n ));
        detail::stedc( compz, n, traits::vector_storage(d),
                traits::vector_storage(e), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_size(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                $CALL_MIN_SIZE ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( compz,
                n ) );
        invoke( compz, n, d, e, z, info, workspace( tmp_work, tmp_rwork,
                tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void invoke( char const compz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        real_type opt_size_rwork;
        integer_t opt_size_iwork;
        detail::stedc( compz, n, traits::vector_storage(d),
                traits::vector_storage(e), traits::matrix_storage(z),
                traits::leading_dimension(z), &opt_size_work, -1,
                &opt_size_rwork, -1, &opt_size_iwork, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        traits::detail::array< real_type > tmp_rwork(
                traits::detail::to_int( opt_size_rwork ) );
        traits::detail::array< integer_t > tmp_iwork( opt_size_iwork );
        invoke( compz, n, d, e, z, info, workspace( tmp_work, tmp_rwork,
                tmp_iwork ) );
    }

    static integer_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE
    }

    static integer_t min_size_rwork( $ARGUMENTS ) {
        $MIN_SIZE
    }

    static integer_t min_size_iwork( char const compz, integer_t const n ) {
        // some formula
    }
};


// template function to call stedc
template< typename VectorD, typename VectorE, typename MatrixZ,
        typename Workspace >
inline integer_t stedc( char const compz, integer_t const n, VectorD& d,
        VectorE& e, MatrixZ& z, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixZ >::value_type value_type;
    integer_t info(0);
    stedc_impl< value_type >::invoke( compz, n, d, e, z, info, work );
    return info;
}

// template function to call stedc, default workspace type
template< typename VectorD, typename VectorE, typename MatrixZ >
inline integer_t stedc( char const compz, integer_t const n, VectorD& d,
        VectorE& e, MatrixZ& z ) {
    typedef typename traits::matrix_traits< MatrixZ >::value_type value_type;
    integer_t info(0);
    stedc_impl< value_type >::invoke( compz, n, d, e, z, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
