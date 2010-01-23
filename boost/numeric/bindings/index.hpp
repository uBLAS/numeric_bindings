//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_INDEX_HPP
#define BOOST_NUMERIC_BINDINGS_INDEX_HPP

#include <boost/mpl/if.hpp>
#include <boost/mpl/max.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
struct index_minor:
    mpl::if_<
        is_column_major< T >,
        tag::index<1>,
        tag::index<
            mpl::max< tag::matrix, rank< T > >::type::value
        >
    >::type {};

template< typename T >
struct index_major:
    mpl::if_<
        is_column_major< T >,
        tag::index<
            mpl::max< tag::matrix, rank< T > >::type::value
        >,
        tag::index<1>
    >::type {};


template< typename Index, typename TransTag >
struct index_trans {
    typedef Index type;
};

template<>
struct index_trans< tag::index<1>, tag::transpose > {
    typedef tag::index<2> type;
};

template<>
struct index_trans< tag::index<1>, tag::conjugate > {
    typedef tag::index<2> type;
};

template<>
struct index_trans< tag::index<2>, tag::transpose > {
    typedef tag::index<1> type;
};

template<>
struct index_trans< tag::index<2>, tag::conjugate > {
    typedef tag::index<1> type;
};


} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
