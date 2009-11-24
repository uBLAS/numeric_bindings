//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_IO_HPP
#define BOOST_NUMERIC_BINDINGS_IO_HPP

#include <iostream>
#include <boost/utility/enable_if.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/end.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/detail/adaptable_type.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename Stream, typename T >
Stream& pretty_print( Stream& os, T const& t ) {
    os << "[" << size<1>(t) << "] ";
    for( typename result_of::begin<T const>::type i = begin(t); i != end(t); ++i ) {
        os << *i << " ";
    }
    return os;
}

} // detail
} // bindings
} // numeric
} // boost


template< typename T >
std::ostream& operator<<( std::ostream& os,
        boost::numeric::bindings::detail::adaptable_type<T> const& object ) {
    return boost::numeric::bindings::detail::pretty_print( os, object.derived() );
}


#endif
