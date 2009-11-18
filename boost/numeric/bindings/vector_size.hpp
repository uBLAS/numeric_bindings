//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_VECTOR_SIZE_HPP
#define BOOST_NUMERIC_BINDINGS_VECTOR_SIZE_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/tensor_size.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T, typename Enable = void >
struct vector_size_impl {};

template< typename T >
struct vector_size_impl< T, 
        typename boost::enable_if< boost::mpl::less< tensor_rank<T>, mpl::int_<2> > >::type > {

    static std::ptrdiff_t size( T const& t ) {
        return tensor_size1( t );
    }
};

template< typename T >
struct vector_size_impl< T, 
        typename boost::enable_if< boost::mpl::greater_equal< tensor_rank<T>, mpl::int_<2> > >::type > {

    static std::ptrdiff_t size( T const& t ) {
        BOOST_ASSERT( tensor_size2( t )==1 );
        return tensor_size1( t );
    }

};

template< typename T >
inline std::ptrdiff_t vector_size( T const& t ) {
    return vector_size_impl<T>::size( t );
}

} // bindings
} // numeric
} // boost

#endif

