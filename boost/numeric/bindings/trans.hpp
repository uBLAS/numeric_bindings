//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRANS_HPP
#define BOOST_NUMERIC_BINDINGS_TRANS_HPP

#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/mpl/max.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
struct trans_wrapper: reference_wrapper<T> {
    trans_wrapper( T& t ): reference_wrapper<T>( t ) {}
};

template< typename T, typename Id, typename Enable >
struct adaptor< trans_wrapper<T>, Id, Enable > {

    typedef typename property_insert< T,
        mpl::pair< tag::entity, 
                   typename mpl::max< tag::matrix, rank< T > >::type >,
        mpl::pair< tag::data_order,
                   typename mpl::if_< is_row_major< T >, 
                                      tag::column_major,
                                      tag::row_major >::type >,
        mpl::pair< tag::size_type<1>, typename result_of::size2< T >::type >,
        mpl::pair< tag::size_type<2>, typename result_of::size1< T >::type >,
        mpl::pair< tag::stride_type<1>, typename result_of::stride2< T >::type >,
        mpl::pair< tag::stride_type<2>, typename result_of::stride1< T >::type >
    >::type property_map;

    // Flip size1/size2
    static typename result_of::size2< T >::type size1( const Id& t ) {
        return bindings::size2( t.get() );
    }

    static typename result_of::size1< T >::type size2( const Id& t ) {
        return bindings::size1( t.get() );
    }

    // Flip stride1/stride2
    static typename result_of::stride2< T >::type stride1( const Id& t ) {
        return bindings::stride2( t.get() );
    }

    static typename result_of::stride1< T >::type stride2( const Id& t ) {
        return bindings::stride1( t.get() );
    }

    static typename result_of::begin_value< T >::type begin_value( Id& id ) {
        return bindings::begin_value( id.get() );
    }

    static typename result_of::end_value< T >::type end_value( Id& id ) {
        return bindings::end_value( id.get() );
    }

};

} // namespace detail

namespace result_of {

template< typename T >
struct trans {
    typedef detail::trans_wrapper<T> type;
};

}

template< typename T >
typename result_of::trans<T>::type trans( T& underlying ) {
    return detail::trans_wrapper<T>( underlying );
}

template< typename T >
typename result_of::trans<const T>::type trans( const T& underlying ) {
    return detail::trans_wrapper<const T>( underlying );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
