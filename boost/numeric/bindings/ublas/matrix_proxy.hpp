//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_PROXY_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_PROXY_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/property_map.hpp>
#include <boost/numeric/bindings/end.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable >
struct adaptor< ublas::matrix_range< T >, Id, Enable > {

    typedef typename copy_const< Id, typename value<T>::type >::type value_type;
    typedef typename property_insert<
        T,
        mpl::pair< tag::value_type, value_type >
    >::type property_map;

    static std::ptrdiff_t size1( const Id& id ) {
        return id.size1();
    }

    static std::ptrdiff_t size2( const Id& id ) {
        return id.size2();
    }

    static value_type* begin_value( Id& id ) {
        return bindings::begin_value( id.data() ) + 
               id.start1() * stride1( id ) + 
               id.start2() * stride2( id );
    }

    static value_type* end_value( Id& id ) {
        return bindings::end_value( id.data() );
    }

    static std::ptrdiff_t stride1( const Id& id ) {
        return bindings::stride1( id.data() );
    }

    static std::ptrdiff_t stride2( const Id& id ) {
        return bindings::stride2( id.data() );
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
