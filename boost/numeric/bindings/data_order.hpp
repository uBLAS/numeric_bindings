//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DATA_ORDER_HPP
#define BOOST_NUMERIC_BINDINGS_DATA_ORDER_HPP

#include <boost/numeric/bindings/detail/property_map.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
struct data_order {
    typedef typename detail::property_at< T, tag::data_order >::type type;
};

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
