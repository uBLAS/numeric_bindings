/*
 * 
 * Copyright (c) Kresimir Fresl 2003
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Author acknowledges the support of the Faculty of Civil Engineering, 
 * University of Zagreb, Croatia.
 *
 */

#ifndef BOOST_NUMERIC_BINDINGS_TRAITS_DETAIL_ARRAY_HPP
#define BOOST_NUMERIC_BINDINGS_TRAITS_DETAIL_ARRAY_HPP

#include <boost/numeric/bindings/traits/vector_traits.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>

#ifndef BOOST_NUMERIC_BINDINGS_POOR_MANS_TRAITS 

#include <boost/numeric/bindings/traits/detail/array_impl.hpp>

namespace boost { namespace numeric { namespace bindings { namespace traits {

  template <typename T>
  struct vector_traits<detail::array<T> > {
    typedef T value_type;
    typedef std::ptrdiff_t size_type;
    typedef T* pointer; 

    static pointer storage (detail::array<T>& a) { return a.storage(); }
    static size_type size (detail::array<T>& a) { return a.size(); } 
  }; 

} namespace detail {

  template< typename T, typename Id, typename Enable >
  struct adaptor< traits::detail::array< T >, Id, Enable > {
    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::data_structure, tag::linear_array >,
        mpl::pair< tag::stride_type<1>, tag::contiguous >
    > property_map;

    static std::ptrdiff_t size1( const Id& t ) {
        return t.size();
    }

    static value_type* begin_value( Id& t ) {
        return t.storage();
    }

    static value_type* end_value( Id& t ) {
        return t.storage() + t.size();
    }
};

}}}}

#endif // BOOST_NUMERIC_BINDINGS_POOR_MANS_TRAITS 

#endif // BOOST_NUMERIC_BINDINGS_TRAITS_DETAIL_ARRAY_HPP
