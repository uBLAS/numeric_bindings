//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRAITS_IS_VECTOR_HPP
#define BOOST_NUMERIC_BINDINGS_TRAITS_IS_VECTOR_HPP

#include <boost/mpl/bool.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace traits {

template< typename T >
struct is_vector: boost::mpl::bool_<false> {};

}}}}

#endif
