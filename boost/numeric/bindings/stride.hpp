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
#include <boost/numeric/bindings/tensor_rank.hpp>
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

    static result_type stride( T const& t ) {
        return get< Key >( t );
    }

};

template< typename T, typename Key >
struct stride_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, tensor_rank<T> >,
            is_same_at< T, tag::stride_type<1>, std::ptrdiff_t >
        >::type >::type > {

    typedef std::ptrdiff_t result_type;

    static result_type stride( T const& t ) {
        return 0;
    }

};

template< typename T, typename Key >
struct stride_impl< T, Key,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Key, tensor_rank<T> >,
            mpl::not_< is_same_at< T, tag::stride_type<1>, std::ptrdiff_t > >
        >::type >::type > {

    typedef typename mpl::int_<0> result_type;

    static result_type stride( T const& t ) {
        return result_type();
    }

};

} // namespace detail

namespace result_of {

template< typename T, int Dimension >
struct stride {
    typedef typename detail::stride_impl< T, tag::stride_type<Dimension> >::result_type type;
};

} // namespace result_of

template< int Dimension, typename T >
inline typename result_of::stride< T const, Dimension >::type stride( T const& t ) {
    return detail::stride_impl< T const, tag::stride_type<Dimension> >::stride( t );
}

template< typename T >
inline std::ptrdiff_t stride( T const& t, std::size_t dimension ) {
    switch( dimension ) {
        case 1: return stride<1>(t);
        case 2: return stride<2>(t);
        case 3: return stride<3>(t);
        case 4: return stride<4>(t);
        default: return 0;
    }
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
