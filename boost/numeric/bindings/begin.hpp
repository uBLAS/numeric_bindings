//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_BEGIN_HPP
#define BOOST_NUMERIC_BINDINGS_BEGIN_HPP

#include <boost/numeric/bindings/data.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/linear_iterator.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace result_of {

template< typename T >
struct begin {
    typedef detail::linear_iterator<
        typename value_type<T>::type,
        typename stride<T,1>::type
    > type;
};

} // namespace result_of

template< typename T >
typename result_of::begin<T>::type begin( T& t ) {
    return typename result_of::begin<T>::type( data( t ), stride<1>( t ) );
}

template< typename T >
typename result_of::begin<T const>::type begin( T const& t ) {
    return typename result_of::begin<T const>::type( data( t ), stride<1>( t ) );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
