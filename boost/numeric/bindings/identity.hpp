//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_IDENTITY_HPP
#define BOOST_NUMERIC_BINDINGS_IDENTITY_HPP

#include <boost/numeric/bindings/detail/adaptable_type.hpp>
#include <boost/ref.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
struct identity_wrapper:
        adaptable_type< identity_wrapper<T> >,
        reference_wrapper<T> {
    identity_wrapper( T& t ): reference_wrapper<T>( t ) {}
};

template< typename T, typename Id, typename Enable >
struct adaptor< identity_wrapper<T>, Id, Enable > {

    typedef adaptor< typename boost::remove_const<T>::type, T > underlying_adaptor;
    typedef typename underlying_adaptor::property_map property_map;

    static std::ptrdiff_t size1( Id const& id ) {
        return underlying_adaptor::size1( id.get() );
    }

    static typename mpl::at< property_map, tag::value_type >::type* data( Id& id ) {
        return underlying_adaptor::data( id.get() );
    }

};

} // namespace detail

namespace result_of {

template< typename T >
struct identity {
    typedef detail::identity_wrapper<T> type;
};

} // namespace result_of

template< typename T >
detail::identity_wrapper<T> identity( T& underlying ) {
    return detail::identity_wrapper<T>( underlying );
}

template< typename T >
detail::identity_wrapper<T const> identity( T const& underlying ) {
    return detail::identity_wrapper<T const>( underlying );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
