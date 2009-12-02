//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_SIZE_HPP
#define BOOST_NUMERIC_BINDINGS_SIZE_HPP

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
struct size_impl {

    typedef typename result_of_get< T, Key >::type result_type;

    static result_type size( const T& t ) {
        return get< Key >( t );
    }

};

template< typename T, typename Key >
struct size_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, rank<T> >,
            is_same_at< T, tag::size_type<1>, std::ptrdiff_t >
        >::type >::type > {

    typedef std::ptrdiff_t result_type;

    static result_type size( const T& t ) {
        return std::min< std::ptrdiff_t >( size_impl<T, tag::size_type<1> >::size(t), 1 );
    }

};

template< typename T, typename Key >
struct size_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, rank<T> >,
            mpl::not_< is_same_at< T, tag::size_type<1>, std::ptrdiff_t > >
        >::type >::type > {

    typedef typename mpl::min<
        typename detail::property_at< T, tag::size_type<1> >::type,
        mpl::int_<1>
    >::type result_type;

    static result_type size( const T& t ) {
        return result_type();
    }

};

} // namespace detail


namespace result_of {

template< typename T, int Dimension >
struct size {
    typedef typename detail::size_impl< T, tag::size_type<Dimension> >::result_type type;
};

} // namespace result_of

template< int Dimension, typename T >
inline typename result_of::size< const T, Dimension >::type size( const T& t ) {
    return detail::size_impl< const T, tag::size_type<Dimension> >::size( t );
}

template< typename T >
inline std::ptrdiff_t size( const T& t, std::size_t dimension ) {
    switch( dimension ) {
        case 1: return size<1>(t);
        case 2: return size<2>(t);
        case 3: return size<3>(t);
        case 4: return size<4>(t);
        default: return 0;
    }
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
