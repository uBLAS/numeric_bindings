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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGHRD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGHRD_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for gghrd is the netlib-compatible backend.
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
inline std::ptrdiff_t gghrd( const char compq, const char compz,
        const fortran_int_t n, const fortran_int_t ilo,
        const fortran_int_t ihi, float* a, const fortran_int_t lda, float* b,
        const fortran_int_t ldb, float* q, const fortran_int_t ldq, float* z,
        const fortran_int_t ldz ) {
    fortran_int_t info(0);
    LAPACK_SGGHRD( &compq, &compz, &n, &ilo, &ihi, a, &lda, b, &ldb, q, &ldq,
            z, &ldz, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t gghrd( const char compq, const char compz,
        const fortran_int_t n, const fortran_int_t ilo,
        const fortran_int_t ihi, double* a, const fortran_int_t lda,
        double* b, const fortran_int_t ldb, double* q,
        const fortran_int_t ldq, double* z, const fortran_int_t ldz ) {
    fortran_int_t info(0);
    LAPACK_DGGHRD( &compq, &compz, &n, &ilo, &ihi, a, &lda, b, &ldb, q, &ldq,
            z, &ldz, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t gghrd( const char compq, const char compz,
        const fortran_int_t n, const fortran_int_t ilo,
        const fortran_int_t ihi, std::complex<float>* a,
        const fortran_int_t lda, std::complex<float>* b,
        const fortran_int_t ldb, std::complex<float>* q,
        const fortran_int_t ldq, std::complex<float>* z,
        const fortran_int_t ldz ) {
    fortran_int_t info(0);
    LAPACK_CGGHRD( &compq, &compz, &n, &ilo, &ihi, a, &lda, b, &ldb, q, &ldq,
            z, &ldz, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t gghrd( const char compq, const char compz,
        const fortran_int_t n, const fortran_int_t ilo,
        const fortran_int_t ihi, std::complex<double>* a,
        const fortran_int_t lda, std::complex<double>* b,
        const fortran_int_t ldb, std::complex<double>* q,
        const fortran_int_t ldq, std::complex<double>* z,
        const fortran_int_t ldz ) {
    fortran_int_t info(0);
    LAPACK_ZGGHRD( &compq, &compz, &n, &ilo, &ihi, a, &lda, b, &ldb, q, &ldq,
            z, &ldz, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to gghrd.
//
template< typename Value >
struct gghrd_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename MatrixQ,
            typename MatrixZ >
    static std::ptrdiff_t invoke( const char compq, const char compz,
            const fortran_int_t ilo, MatrixA& a, MatrixB& b, MatrixQ& q,
            MatrixZ& z ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixQ >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixZ >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixQ >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixZ >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixQ >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixZ >::value) );
        BOOST_ASSERT( bindings::size_column(a) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_minor(q) == 1 ||
                bindings::stride_minor(q) == 1 );
        BOOST_ASSERT( bindings::size_minor(z) == 1 ||
                bindings::stride_minor(z) == 1 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(a)) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(a)) );
        BOOST_ASSERT( compq == 'N' || compq == 'I' || compq == 'V' );
        BOOST_ASSERT( compz == 'N' || compz == 'I' || compz == 'V' );
        return detail::gghrd( compq, compz, bindings::size_column(a), ilo,
                bindings::size_column(a), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), bindings::begin_value(q),
                bindings::stride_major(q), bindings::begin_value(z),
                bindings::stride_major(z) );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the gghrd_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for gghrd. Its overload differs for
//
template< typename MatrixA, typename MatrixB, typename MatrixQ,
        typename MatrixZ >
inline std::ptrdiff_t gghrd( const char compq, const char compz,
        const fortran_int_t ilo, MatrixA& a, MatrixB& b, MatrixQ& q,
        MatrixZ& z ) {
    return gghrd_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( compq, compz, ilo, a, b, q, z );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
