//
// Copyright (c) 2009 by Rutger ter Borg and Thomas Klimpel
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRAITS_UBLAS_STORAGE_HPP
#define BOOST_NUMERIC_BINDINGS_TRAITS_UBLAS_STORAGE_HPP

#include <boost/numeric/bindings/traits/vector_traits.hpp>

#ifndef BOOST_UBLAS_HAVE_BINDINGS
#  include <boost/numeric/ublas/storage.hpp>
#endif

namespace boost { namespace numeric { namespace bindings { namespace traits {

   // ublas::bounded array
  template <typename T, std::size_t N, typename V>
  struct vector_detail_traits< ublas::bounded_array< T, N>, V >:
  public default_vector_traits< V, T > {};

   // ublas::unbounded array
  template< typename T, typename Allocator, typename V >
  struct vector_detail_traits< ublas::unbounded_array< T, Allocator >, V >:
  public default_vector_traits< V, T > {};

}}}}

#endif
