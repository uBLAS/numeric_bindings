//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_ADAPTOR_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_ADAPTOR_HPP

#include <boost/utility/enable_if.hpp>
#include <boost/numeric/bindings/is_numeric.hpp>
#include <boost/numeric/bindings/detail/tag.hpp>
#include <boost/numeric/bindings/detail/copy_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/has_key.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable = void >
struct adaptor {
    typedef mpl::map<
        mpl::pair< tag::value_type, void >
    > property_map;
};

template< typename T, typename Enable = void >
struct adaptor_access {};

template< typename T >
struct is_adaptable: is_numeric< typename mpl::at<
        typename adaptor< typename boost::remove_const<T>::type, T >::property_map,
        tag::value_type >::type > {};

template< typename T >
struct adaptor_access< T,
        typename boost::enable_if< is_adaptable<T> >::type >:
    adaptor< typename boost::remove_const<T>::type, T > {};

template< typename T, typename Key >
struct property_has_key: mpl::has_key< typename adaptor_access<T>::property_map, Key > {};

template< typename T, typename Key >
struct property_at {
    typedef typename mpl::at< typename adaptor_access<T>::property_map, Key >::type type;
};

} // detail
} // bindings
} // numeric
} // boost

// Include support for POD types
#include <boost/numeric/bindings/detail/pod.hpp>

#endif
