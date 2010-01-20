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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEGV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEGV_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for hegv is the netlib-compatible backend.
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
// * complex<float> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hegv( const fortran_int_t itype, const char jobz,
        const UpLo uplo, const fortran_int_t n, std::complex<float>* a,
        const fortran_int_t lda, std::complex<float>* b,
        const fortran_int_t ldb, float* w, std::complex<float>* work,
        const fortran_int_t lwork, float* rwork ) {
    fortran_int_t info(0);
    LAPACK_CHEGV( &itype, &jobz, &lapack_option< UpLo >::value, &n, a, &lda,
            b, &ldb, w, work, &lwork, rwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hegv( const fortran_int_t itype, const char jobz,
        const UpLo uplo, const fortran_int_t n, std::complex<double>* a,
        const fortran_int_t lda, std::complex<double>* b,
        const fortran_int_t ldb, double* w, std::complex<double>* work,
        const fortran_int_t lwork, double* rwork ) {
    fortran_int_t info(0);
    LAPACK_ZHEGV( &itype, &jobz, &lapack_option< UpLo >::value, &n, a, &lda,
            b, &ldb, w, work, &lwork, rwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hegv.
//
template< typename Value >
struct hegv_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename WORK, typename RWORK >
    static std::ptrdiff_t invoke( const fortran_int_t itype,
            const char jobz, MatrixA& a, MatrixB& b, VectorW& w,
            detail::workspace2< WORK, RWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixA >::type uplo;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorW >::value) );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( bindings::size_column(a) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(a) ));
        BOOST_ASSERT( bindings::size_column(a) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(a)) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(a)) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        return detail::hegv( itype, jobz, uplo(), bindings::size_column(a),
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(w),
                bindings::begin_value(work.select(value_type())),
                bindings::size(work.select(value_type())),
                bindings::begin_value(work.select(real_type())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixA, typename MatrixB, typename VectorW >
    static std::ptrdiff_t invoke( const fortran_int_t itype,
            const char jobz, MatrixA& a, MatrixB& b, VectorW& w,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixA >::type uplo;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(a) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(a) ) );
        return invoke( itype, jobz, a, b, w, workspace( tmp_work,
                tmp_rwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename MatrixB, typename VectorW >
    static std::ptrdiff_t invoke( const fortran_int_t itype,
            const char jobz, MatrixA& a, MatrixB& b, VectorW& w,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixA >::type uplo;
        value_type opt_size_work;
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(a) ) );
        detail::hegv( itype, jobz, uplo(), bindings::size_column(a),
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(w), &opt_size_work, -1,
                bindings::begin_value(tmp_rwork) );
        bindings::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( itype, jobz, a, b, w, workspace( tmp_work,
                tmp_rwork ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return std::max< std::ptrdiff_t >( 1, 2*n-1 );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t n ) {
        return std::max< std::ptrdiff_t >( 1, 3*n-2 );
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the hegv_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * MatrixB&
// * VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        MatrixB& b, VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * MatrixB&
// * VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        MatrixB& b, VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        MatrixB& b, VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        MatrixB& b, VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        const MatrixB& b, VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        const MatrixB& b, VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        const MatrixB& b, VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        const MatrixB& b, VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * MatrixB&
// * const VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        MatrixB& b, const VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * MatrixB&
// * const VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        MatrixB& b, const VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * const VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        MatrixB& b, const VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * const VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        MatrixB& b, const VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * const VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        const MatrixB& b, const VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * const VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, MatrixA& a,
        const MatrixB& b, const VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * const VectorW&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        const MatrixB& b, const VectorW& w, Workspace work ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w, work );
}

//
// Overloaded function for hegv. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * const VectorW&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB, typename VectorW >
inline typename boost::disable_if< detail::is_workspace< VectorW >,
        std::ptrdiff_t >::type
hegv( const fortran_int_t itype, const char jobz, const MatrixA& a,
        const MatrixB& b, const VectorW& w ) {
    return hegv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( itype, jobz, a, b, w,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
