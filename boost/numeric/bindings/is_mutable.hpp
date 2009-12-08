//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_IS_MUTABLE_HPP
#define BOOST_NUMERIC_BINDINGS_IS_MUTABLE_HPP

#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/bindings/has_linear_array.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T, typename Enable = void >
struct is_mutable {};

template< typename T >
struct is_mutable< T, typename enable_if< has_linear_array<T> >::type >:
        is_same< typename value<T>::type, 
                 typename remove_const< typename value<T>::type >::type 
        > {};

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
