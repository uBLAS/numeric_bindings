//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_INDEX_MAJOR_HPP
#define BOOST_NUMERIC_BINDINGS_INDEX_MAJOR_HPP

#include <boost/mpl/if.hpp>
#include <boost/mpl/max.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
struct index_major:
    mpl::if_<
        is_column_major< T >,
        tag::index<
            mpl::max< tag::matrix, rank< T > >::type::value
        >,
        tag::index<1>
    >::type {};

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
