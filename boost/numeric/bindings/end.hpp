//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_END_HPP
#define BOOST_NUMERIC_BINDINGS_END_HPP

#include <boost/numeric/bindings/begin.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace result_of {

template< typename T >
struct end {
    typedef typename begin<T>::type type;
};

} // namespace result_of

template< typename T >
typename result_of::end<T>::type end( T& t ) {
    return typename result_of::end<T>::type( data( t ), stride<1>( t ) ) + size<1>( t );
}

template< typename T >
typename result_of::end<T const>::type end( T const& t ) {
    return typename result_of::end<T const>::type( data( t ), stride<1>( t ) ) + size<1>( t );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
