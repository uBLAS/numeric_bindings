//
// Copyright (c) 2002--2010
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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGSNA_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGSNA_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for tgsna is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * float value-type.
//
inline std::ptrdiff_t tgsna( const char job, const char howmny,
        const logical_t* select, const fortran_int_t n, const float* a,
        const fortran_int_t lda, const float* b, const fortran_int_t ldb,
        const float* vl, const fortran_int_t ldvl, const float* vr,
        const fortran_int_t ldvr, float* s, float* dif,
        const fortran_int_t mm, fortran_int_t& m, float* work,
        const fortran_int_t lwork, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_STGSNA( &job, &howmny, select, &n, a, &lda, b, &ldb, vl, &ldvl, vr,
            &ldvr, s, dif, &mm, &m, work, &lwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t tgsna( const char job, const char howmny,
        const logical_t* select, const fortran_int_t n, const double* a,
        const fortran_int_t lda, const double* b, const fortran_int_t ldb,
        const double* vl, const fortran_int_t ldvl, const double* vr,
        const fortran_int_t ldvr, double* s, double* dif,
        const fortran_int_t mm, fortran_int_t& m, double* work,
        const fortran_int_t lwork, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_DTGSNA( &job, &howmny, select, &n, a, &lda, b, &ldb, vl, &ldvl, vr,
            &ldvr, s, dif, &mm, &m, work, &lwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t tgsna( const char job, const char howmny,
        const logical_t* select, const fortran_int_t n,
        const std::complex<float>* a, const fortran_int_t lda,
        const std::complex<float>* b, const fortran_int_t ldb,
        const std::complex<float>* vl, const fortran_int_t ldvl,
        const std::complex<float>* vr, const fortran_int_t ldvr, float* s,
        float* dif, const fortran_int_t mm, fortran_int_t& m,
        std::complex<float>* work, const fortran_int_t lwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_CTGSNA( &job, &howmny, select, &n, a, &lda, b, &ldb, vl, &ldvl, vr,
            &ldvr, s, dif, &mm, &m, work, &lwork, iwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t tgsna( const char job, const char howmny,
        const logical_t* select, const fortran_int_t n,
        const std::complex<double>* a, const fortran_int_t lda,
        const std::complex<double>* b, const fortran_int_t ldb,
        const std::complex<double>* vl, const fortran_int_t ldvl,
        const std::complex<double>* vr, const fortran_int_t ldvr, double* s,
        double* dif, const fortran_int_t mm, fortran_int_t& m,
        std::complex<double>* work, const fortran_int_t lwork,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_ZTGSNA( &job, &howmny, select, &n, a, &lda, b, &ldb, vl, &ldvl, vr,
            &ldvr, s, dif, &mm, &m, work, &lwork, iwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to tgsna.
//
template< typename Value, typename Enable = void >
struct tgsna_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct tgsna_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF, typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            detail::workspace2< WORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVL >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorS >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorDIF >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorS >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorDIF >::value) );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( $CALL_MIN_SIZE ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_minor(vl) == 1 ||
                bindings::stride_minor(vl) == 1 );
        BOOST_ASSERT( bindings::size_minor(vr) == 1 ||
                bindings::stride_minor(vr) == 1 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( howmny == 'A' || howmny == 'S' );
        BOOST_ASSERT( job == 'E' || job == 'V' || job == 'B' );
        BOOST_ASSERT( n >= 0 );
        return detail::tgsna( job, howmny, bindings::begin_value(select), n,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(vl), bindings::stride_major(vl),
                bindings::begin_value(vr), bindings::stride_major(vr),
                bindings::begin_value(s), bindings::begin_value(dif), mm, m,
                bindings::begin_value(work.select(real_type())),
                bindings::size(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            minimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( $CALL_MIN_SIZE ) );
        return invoke( job, howmny, select, n, a, b, vl, vr, s, dif, mm, m,
                workspace( tmp_work, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            optimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        real_type opt_size_work;
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( $CALL_MIN_SIZE ) );
        detail::tgsna( job, howmny, bindings::begin_value(select), n,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(vl), bindings::stride_major(vl),
                bindings::begin_value(vr), bindings::stride_major(vr),
                bindings::begin_value(s), bindings::begin_value(dif), mm, m,
                &opt_size_work, -1, bindings::begin_value(tmp_iwork) );
        bindings::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( job, howmny, select, n, a, b, vl, vr, s, dif, mm, m,
                workspace( tmp_work, tmp_iwork ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    template< $TYPES >
    static std::ptrdiff_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE_IMPLEMENTATION
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    template< $TYPES >
    static std::ptrdiff_t min_size_iwork( $ARGUMENTS ) {
        $MIN_SIZE_IMPLEMENTATION
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct tgsna_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF, typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            detail::workspace2< WORK, IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorS >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorDIF >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVL >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorS >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorDIF >::value) );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( $CALL_MIN_SIZE ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_minor(vl) == 1 ||
                bindings::stride_minor(vl) == 1 );
        BOOST_ASSERT( bindings::size_minor(vr) == 1 ||
                bindings::stride_minor(vr) == 1 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        BOOST_ASSERT( howmny == 'A' || howmny == 'S' );
        BOOST_ASSERT( job == 'E' || job == 'V' || job == 'B' );
        BOOST_ASSERT( n >= 0 );
        return detail::tgsna( job, howmny, bindings::begin_value(select), n,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(vl), bindings::stride_major(vl),
                bindings::begin_value(vr), bindings::stride_major(vr),
                bindings::begin_value(s), bindings::begin_value(dif), mm, m,
                bindings::begin_value(work.select(value_type())),
                bindings::size(work.select(value_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            minimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( $CALL_MIN_SIZE ) );
        return invoke( job, howmny, select, n, a, b, vl, vr, s, dif, mm, m,
                workspace( tmp_work, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename VectorSELECT, typename MatrixA, typename MatrixB,
            typename MatrixVL, typename MatrixVR, typename VectorS,
            typename VectorDIF >
    static std::ptrdiff_t invoke( const char job, const char howmny,
            const VectorSELECT& select, const fortran_int_t n,
            const MatrixA& a, const MatrixB& b, const MatrixVL& vl,
            const MatrixVR& vr, VectorS& s, VectorDIF& dif,
            const fortran_int_t mm, fortran_int_t& m,
            optimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( job, howmny, select, n, a, b, vl, vr, s, dif, mm, m,
                minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    template< $TYPES >
    static std::ptrdiff_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE_IMPLEMENTATION
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    template< $TYPES >
    static std::ptrdiff_t min_size_iwork( $ARGUMENTS ) {
        $MIN_SIZE_IMPLEMENTATION
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the tgsna_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for tgsna. Its overload differs for
// * User-defined workspace
//
template< typename VectorSELECT, typename MatrixA, typename MatrixB,
        typename MatrixVL, typename MatrixVR, typename VectorS,
        typename VectorDIF, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
tgsna( const char job, const char howmny, const VectorSELECT& select,
        const fortran_int_t n, const MatrixA& a, const MatrixB& b,
        const MatrixVL& vl, const MatrixVR& vr, VectorS& s, VectorDIF& dif,
        const fortran_int_t mm, fortran_int_t& m, Workspace work ) {
    return tgsna_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( job, howmny, select, n, a, b, vl, vr,
            s, dif, mm, m, work );
}

//
// Overloaded function for tgsna. Its overload differs for
// * Default workspace-type (optimal)
//
template< typename VectorSELECT, typename MatrixA, typename MatrixB,
        typename MatrixVL, typename MatrixVR, typename VectorS,
        typename VectorDIF >
inline typename boost::disable_if< detail::is_workspace< VectorDIF >,
        std::ptrdiff_t >::type
tgsna( const char job, const char howmny, const VectorSELECT& select,
        const fortran_int_t n, const MatrixA& a, const MatrixB& b,
        const MatrixVL& vl, const MatrixVR& vr, VectorS& s, VectorDIF& dif,
        const fortran_int_t mm, fortran_int_t& m ) {
    return tgsna_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( job, howmny, select, n, a, b, vl, vr,
            s, dif, mm, m, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
