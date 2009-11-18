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
#include <boost/type_traits/remove_const.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable = void >
struct adaptor {};

template< typename T, typename Enable = void >
struct adaptor_access {};

template< typename T >
struct adaptor_access< T,
        typename boost::enable_if< is_numeric< typename adaptor< 
                typename boost::remove_const<T>::type, T >::value_type > >::type >:
    adaptor< typename boost::remove_const<T>::type, T > {};

} // detail
} // bindings
} // numeric
} // boost

// Include support for POD types
#include <boost/numeric/bindings/detail/pod.hpp>

#endif
