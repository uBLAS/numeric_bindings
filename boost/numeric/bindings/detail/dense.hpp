//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_DENSE_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_DENSE_HPP

#include <boost/mpl/int.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

// Storage layout tags
struct dense_tag {};

// Dense stuff
struct column_major_tag {};
struct row_major_tag {};

} // detail
} // bindings
} // numeric
} // boost

#endif
