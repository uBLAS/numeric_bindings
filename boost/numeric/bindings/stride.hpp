//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_STRIDE_HPP
#define BOOST_NUMERIC_BINDINGS_STRIDE_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/get.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/mpl/min.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/greater.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Key, typename Enable = void >
struct stride_impl {

    typedef typename result_of_get< T, Key >::type result_type;

    static result_type stride( const T& t ) {
        return get< Key >( t );
    }

};

template< typename T, typename Key >
struct stride_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, rank<T> >,
            is_same_at< T, tag::stride_type<1>, std::ptrdiff_t >
        >::type >::type > {

    typedef std::ptrdiff_t result_type;

    static result_type stride( const T& t ) {
        return 0;
    }

};

template< typename T, typename Key >
struct stride_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, rank<T> >,
            mpl::not_< is_same_at< T, tag::stride_type<1>, std::ptrdiff_t > >
        >::type >::type > {

    typedef typename mpl::int_<0> result_type;

    static result_type stride( const T& t ) {
        return result_type();
    }

};

} // namespace detail

namespace result_of {

template< typename T, int Dimension = 1 >
struct stride {
    typedef typename detail::stride_impl< T, tag::stride_type<Dimension> >::result_type type;
};

} // namespace result_of

template< int Dimension, typename T >
inline typename result_of::stride< const T, Dimension >::type stride( const T& t ) {
    return detail::stride_impl< const T, tag::stride_type<Dimension> >::stride( t );
}

// Overloads for types with rank <= 1 (scalars, vectors)
// In theory, we could provide overloads for matrices here, too, 
// if their minimal_rank is at most 1.

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::stride<T>::type >::type
stride( T& t ) {
    return detail::stride_impl<T, tag::stride_type<1> >::stride( t );
}

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::stride< const T >::type >::type
stride( const T& t ) {
    return detail::stride_impl<const T, tag::stride_type<1> >::stride( t );
}


} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
