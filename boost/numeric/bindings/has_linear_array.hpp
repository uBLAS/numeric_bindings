//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_HAS_LINEAR_ARRAY_HPP
#define BOOST_NUMERIC_BINDINGS_HAS_LINEAR_ARRAY_HPP

#include <boost/type_traits/is_same.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
struct has_linear_array: 
        detail::is_same_at< T, detail::tag::data_structure, detail::tag::linear_array > {};


} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
