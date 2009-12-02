//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_PROPERTY_MAP_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_PROPERTY_MAP_HPP

#include <boost/mpl/at.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Key >
struct property_has_key: mpl::has_key< typename adaptor_access<T>::property_map, Key > {};

template< typename T, typename Key >
struct property_at {
    typedef typename mpl::at< typename adaptor_access<T>::property_map, Key >::type type;
};

template< typename T, typename Key, typename Value >
struct is_same_at: is_same< typename property_at< T, Key >::type, Value > {};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
