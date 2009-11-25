//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DATA_HPP
#define BOOST_NUMERIC_BINDINGS_DATA_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
struct data_impl {

    typedef typename property_at< T, tag::value_type >::type* result_type;

    static result_type data( T& t ) {
        return adaptor_access<T>::data( t );
    }

};

} // namespace detail

namespace result_of {

template< typename T >
struct data {
    typedef typename detail::data_impl<T>::result_type type;
};

} // namespace result_of

template< typename T >
typename result_of::data<T>::type data( T& t ) {
    return detail::data_impl<T>::data( t );
}

template< typename T >
typename result_of::data<T const>::type data( T const& t ) {
    return detail::data_impl<T const>::data( t );
}

} // bindings
} // numeric
} // boost

#endif
