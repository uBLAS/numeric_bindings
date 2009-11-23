//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TENSOR_SIZE_HPP
#define BOOST_NUMERIC_BINDINGS_TENSOR_SIZE_HPP

#include <boost/mpl/less.hpp>
#include <boost/mpl/greater_equal.hpp>

#include <boost/numeric/bindings/tensor_rank.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T, int Dimension, typename Enable = void >
struct tensor_size_impl {};


template< typename T, int Dimension >
struct tensor_size_impl< T, Dimension,
        typename boost::enable_if< boost::mpl::greater_equal< tensor_rank<T>, mpl::int_<Dimension> > >::type > {

    static std::ptrdiff_t size1( T const& t ) {
        return detail::adaptor_access<T>::size1( t );
    }

    static std::ptrdiff_t size2( T const& t ) {
        return detail::adaptor_access<T>::size2( t );
    }

};

template< typename T, int Dimension >
struct tensor_size_impl< T, Dimension,
        typename boost::enable_if< boost::mpl::less< tensor_rank<T>, mpl::int_<Dimension> > >::type > {

    static std::ptrdiff_t size1( T const& t ) {
        return 1;
    }

    static std::ptrdiff_t size2( T const& t ) {
        return std::min< std::ptrdiff_t >( tensor_size_impl<T,1>::size1(t), 1 );
    }

};

template< typename T >
inline std::ptrdiff_t tensor_size1( T const& t ) {
    return tensor_size_impl<T,1>::size1( t );
}

template< typename T >
inline std::ptrdiff_t tensor_size2( T const& t ) {
    return tensor_size_impl<T,2>::size2( t );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

