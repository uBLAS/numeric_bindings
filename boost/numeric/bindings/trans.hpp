//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRANSP_HPP
#define BOOST_NUMERIC_BINDINGS_TRANSP_HPP

#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/mpl/max.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
struct trans_wrapper: reference_wrapper<T> {};

template< typename T, typename Id, typename Enable >
struct adaptor< trans_wrapper<T>, Id, Enable > {

    typedef typename value<T>::type value_type;
    typedef typename boost::mpl::max<
            boost::mpl::int_<2>,
            typename entity<T>::type >::type entity;

    // Flip the data order
    typedef typename flip_data_order< key_at::data_order >::type data_order;

    // Flip size1/size2
    static std::ptrdiff_t size1( const Id& t ) {
        return bindings::size2( t.get() );
    }

    static std::ptrdiff_t size2( const Id& t ) {
        return bindings::size1( t.get() );
    }

    static typename result_of::begin_value< T >::type begin_value( Id& id ) {
        return bindings::begin_value( id.get() );
    }

    static typename result_of::end_value< T >::type end_value( Id& id ) {
        return bindings::end_value( id.get() );
    }

};

} // namespace detail


template< typename T >
detail::trans_wrapper<T> trans( T& underlying ) {
    return detail::trans_wrapper<T>( underlying );
}

template< typename T >
detail::trans_wrapper<const T> trans( const T& underlying ) {
    return detail::trans_wrapper<const T>( underlying );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
