//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_BEGIN_HPP
#define BOOST_NUMERIC_BINDINGS_BEGIN_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/linear_iterator.hpp>
#include <boost/numeric/bindings/detail/generate_functions.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <iostream>

namespace boost {
namespace numeric {
namespace bindings {

namespace detail {

template< typename T, typename Tag >
struct begin_impl {};

template< typename T >
struct begin_impl< T, tag::value > {
    typedef typename value<T>::type* result_type;

    static result_type invoke( T& t ) {
        return adaptor_access<T>::begin_value( t );
    }

};

template< typename T, int Dimension >
struct begin_impl<T, tag::index<Dimension> > {

    typedef tag::index<Dimension> tag_type;

    typedef linear_iterator<
        typename value<T>::type,
        typename result_of::stride< T, tag_type >::type
    > result_type;

    static result_type invoke( T& t ) {
        return result_type( begin_value( t ), stride(t, tag_type() ) );
    }

};

} // namespace detail

namespace result_of {

template< typename T, typename Tag = tag::index<1> >
struct begin {
    BOOST_STATIC_ASSERT( (is_tag<Tag>::value) );
    BOOST_STATIC_ASSERT( (mpl::not_< is_tag<T> >::value) );
    typedef typename detail::begin_impl<T,Tag>::result_type type;
};

} // namespace result_of

//
// Free Functions
//

//
// Overloads like begin( t, tag )
//
template< typename T, typename Tag >
inline typename result_of::begin<T,Tag>::type
begin( T& t, Tag ) {
    return detail::begin_impl<T,Tag>::invoke( t );
}

template< typename T, typename Tag >
inline typename result_of::begin<const T,Tag>::type
begin( const T& t, Tag ) {
    return detail::begin_impl<const T,Tag>::invoke( t );
}

// Overloads for types with rank <= 1 (scalars, vectors)
// In theory, we could provide overloads for matrices here, too, 
// if their minimal_rank is at most 1.

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::begin< T >::type >::type
begin( T& t ) {
    return detail::begin_impl< T, tag::index<1> >::invoke( t );
}

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::begin< const T >::type >::type
begin( const T& t ) {
    return detail::begin_impl< const T, tag::index<1> >::invoke( t );
}

#define GENERATE_BEGIN_INDEX( z, which, unused ) \
GENERATE_FUNCTIONS( begin, which, tag::index<which> )

BOOST_PP_REPEAT_FROM_TO(1,3,GENERATE_BEGIN_INDEX,~)
GENERATE_FUNCTIONS( begin, _value, tag::value )
GENERATE_FUNCTIONS( begin, _row, tag::index<1> )
GENERATE_FUNCTIONS( begin, _column, tag::index<2> )

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
