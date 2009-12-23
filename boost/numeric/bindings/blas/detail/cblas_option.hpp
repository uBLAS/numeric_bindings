//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_DETAIL_CBLAS_OPTION_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_DETAIL_CBLAS_OPTION_HPP

#include <boost/mpl/int.hpp>
#include <boost/numeric/bindings/blas/cblas.h>
#include <boost/numeric/bindings/tag.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {
namespace detail {

template< typename Tag >
struct cblas_option {};

template<>
struct cblas_option< tag::row_major >:  mpl::int_< CblasRowMajor > {};

template<>
struct cblas_option< tag::column_major >:  mpl::int_< CblasColMajor > {};

template<>
struct cblas_option< tag::transpose >:  mpl::int_< CblasTrans > {};

template<>
struct cblas_option< tag::no_transpose >:  mpl::int_< CblasNoTrans > {};

template<>
struct cblas_option< tag::conjugate >:  mpl::int_< CblasConjTrans > {};

template<>
struct cblas_option< tag::upper >:  mpl::int_< CblasUpper > {};

template<>
struct cblas_option< tag::lower >:  mpl::int_< CblasLower > {};

template<>
struct cblas_option< tag::unit >:  mpl::int_< CblasUnit > {};

template<>
struct cblas_option< tag::non_unit >:  mpl::int_< CblasNonUnit > {};

template<>
struct cblas_option< tag::left >:  mpl::int_< CblasLeft > {};

template<>
struct cblas_option< tag::right >:  mpl::int_< CblasRight > {};

} // namespace detail
} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
