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

namespace detail {

template< typename T, typename Tag = tag::value >
struct end_impl {
};

template< typename T >
struct end_impl< T, tag::value > {
    typedef typename value<T>::type* result_type;

    static result_type invoke( T& t ) {
        return adaptor_access<T>::begin_value( t );
    }

};

} // namespace detail

namespace result_of {

template< typename T, typename Tag = tag::value >
struct end {
    typedef typename detail::begin_impl<T,Tag>::result_type type;
};

} // namespace result_of

template< typename Tag, typename T >
typename result_of::end<T,Tag>::type end( T& t ) {
    return detail::end_impl<T,Tag>::invoke( t );
}

template< typename Tag, typename T >
typename result_of::end<const T,Tag>::type end( const T& t ) {
    return detail::end_impl<const T,Tag>::invoke( t );
}

template< typename T >
typename result_of::end<T>::type end( T& t ) {
    return detail::end_impl<T>::invoke( t );
}

template< typename T >
typename result_of::end<const T>::type end( const T& t ) {
    return detail::end_impl<const T>::invoke( t );
}


} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
