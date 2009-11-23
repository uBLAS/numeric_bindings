//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRANSPOSE_HPP
#define BOOST_NUMERIC_BINDINGS_TRANSPOSE_HPP

#include <boost/numeric/bindings/value_type.hpp>
#include <boost/numeric/bindings/entity.hpp>
#include <boost/mpl/max.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
struct transpose_wrapper: reference_wrapper<T> {}

template< typename T, typename Id, typename Enable >
struct adaptor< transpose_wrapper<T>, Id, Enable > {

    typedef typename value_type<T>::type value_type;
    typedef typename boost::mpl::max<
            boost::mpl::int_<2>,
            typename entity<T>::type >::type entity;

    static std::ptrdiff_t size1( Id const& t ) {
        return bindings::tensor_size2( t.get() );
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return bindings::tensor_size1( t.get() );
    }

};

} // namespace detail


template< typename T >
detail::transpose_wrapper<T> trans( T& underlying ) {
    return detail::transpose_wrapper<T>( underlying );
}

template< typename T >
detail::transpose_wrapper<T const> trans( T const& underlying ) {
    return detail::transpose_wrapper<T const>( underlying );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
