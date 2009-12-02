//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_BEGIN_HPP
#define BOOST_NUMERIC_BINDINGS_BEGIN_HPP

#include <boost/numeric/bindings/rank.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/linear_iterator.hpp>


#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/cat.hpp>

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
struct begin_impl<T, mpl::int_<Dimension> > {

    typedef mpl::int_<Dimension> dim_type;

    typedef linear_iterator<
        typename value<T>::type,
        typename result_of::stride<T,Dimension>::type
    > result_type;

    static result_type invoke( T& t ) {
        return result_type( begin_value( t ), stride<Dimension>(t) );
    }

};

} // namespace detail

namespace result_of {

template< typename T, typename Tag = mpl::int_<1> >
struct begin {
    typedef typename detail::begin_impl<T,Tag>::result_type type;
};

} // namespace result_of

//
// Free Functions
//

// Overloads like begin< tag::value, etc. >

template< typename Tag, typename T >
typename result_of::begin<T,Tag>::type begin( T& t ) {
    return detail::begin_impl<T,Tag>::invoke( t );
}

template< typename Tag, typename T >
typename result_of::begin<const T,Tag>::type begin( const T& t ) {
    return detail::begin_impl<const T,Tag>::invoke( t );
}

// Overloads like begin<1>, begin<2>, etc..

template< int Dimension, typename T >
typename result_of::begin<T, mpl::int_<Dimension> >::type begin( T& t ) {
    return detail::begin_impl<T, mpl::int_<Dimension> >( t );
}

template< int Dimension, typename T >
typename result_of::begin<const T, mpl::int_<Dimension> >::type begin( const T& t ) {
    return detail::begin_impl<const T, mpl::int_<Dimension> >( t );
}

// Overloads for types with rank <= 1 (scalars, vectors)
// In theory, we could provide overloads for matrices here, too, 
// if their minimal_rank is at most 1.

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::begin< T, mpl::int_<1> >::type >::type
begin( T& t ) {
    return detail::begin_impl<T,mpl::int_<1> >::invoke( t );
}

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::begin< const T >::type >::type
begin( const T& t ) {
    return detail::begin_impl<const T,mpl::int_<1> >::invoke( t );
}

//
// Convenience functions
//

#define GENERATE_BEGIN( suffix, tag ) \
\
namespace result_of {\
\
template< typename T > \
struct BOOST_PP_CAT( begin, suffix ) { \
    typedef typename detail::begin_impl<T,tag>::result_type type;\
}; \
\
}\
\
template< typename T >\
typename BOOST_PP_CAT( result_of::begin, suffix )<T>::type \
BOOST_PP_CAT( begin, suffix )( T& t ) {\
    return detail::begin_impl<T, tag >::\
        invoke( t );\
}\
\
template< typename T >\
typename BOOST_PP_CAT( result_of::begin, suffix )<const T>::type \
BOOST_PP_CAT( begin, suffix )( const T& t ) {\
    return detail::begin_impl<const T, tag >::\
        invoke( t );\
}

#define GENERATE_BEGIN_INDEX( z, which, unused ) \
GENERATE_BEGIN( which, mpl::int_<which> )


BOOST_PP_REPEAT_FROM_TO(1,2,GENERATE_BEGIN_INDEX,~)
GENERATE_BEGIN( _value, tag::value )
GENERATE_BEGIN( _row, mpl::int_<1> )
GENERATE_BEGIN( _column, mpl::int_<2> )

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
