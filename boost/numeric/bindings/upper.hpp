//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UPPER_HPP
#define BOOST_NUMERIC_BINDINGS_UPPER_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/basic_unwrapper.hpp>
#include <boost/numeric/bindings/tag.hpp>

namespace boost {
namespace numeric {
namespace bindings {

namespace detail {

template< typename T >
struct upper_wrapper: reference_wrapper<T> {
    upper_wrapper( T& t ): reference_wrapper<T>( t ) {}
};

template< typename T, typename Id, typename Enable >
struct adaptor< upper_wrapper<T>, Id, Enable >:
        basic_unwrapper< T, Id > {

    typedef typename property_insert< T,
        mpl::pair< tag::matrix_type, tag::triangular >,
        mpl::pair< tag::data_side, tag::upper >
    >::type property_map;

};

} // namespace detail

namespace result_of {

template< typename T >
struct upper {
    typedef detail::upper_wrapper<T> type;
};

} // namespace result_of

template< typename T >
detail::upper_wrapper<T> upper( T& underlying ) {
    return detail::upper_wrapper<T>( underlying );
}

template< typename T >
detail::upper_wrapper<const T> upper( const T& underlying ) {
    return detail::upper_wrapper<const T>( underlying );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
