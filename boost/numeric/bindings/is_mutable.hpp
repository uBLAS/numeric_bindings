//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_IS_MUTABLE_HPP
#define BOOST_NUMERIC_BINDINGS_IS_MUTABLE_HPP

#include <boost/type_traits/value.hpp>

namespace boost {
namespace numeric {
namespace bindings {

//
// TODO things like index arrays should be mutable, too
//
template< typename T >
struct is_mutable:
    mpl::and_<
            is_reference< typename value<T>::type >,
            mpl::not_< is_const< typename value<T>::type > >
    >::type {};

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
