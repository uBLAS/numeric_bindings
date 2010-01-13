//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_OFFSET_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_OFFSET_HPP

#include <boost/utility/enable_if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/has_linear_array.hpp>
#include <boost/numeric/bindings/has_band_array.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename Id, typename Enable = void >
struct offset_impl {};

template< typename Id >
struct offset_impl< Id, typename boost::enable_if< has_linear_array< Id > >::type > {

    static std::ptrdiff_t invoke( const Id& id, std::ptrdiff_t i1, std::ptrdiff_t i2 ) {
        return i1 * bindings::stride1( id ) + 
               i2 * bindings::stride2( id );
    }

};

template< typename Id >
struct offset_impl< Id,
        typename boost::enable_if<
            mpl::and_<
                has_band_array< Id >,
                is_column_major< Id >
            >
        >::type > {

    static std::ptrdiff_t invoke( const Id& id, std::ptrdiff_t i1, std::ptrdiff_t i2 ) {
        return i1 * bindings::stride1( id ) + 
               i2 * (bindings::stride2( id )-1);
    }

};

template< typename Id >
std::ptrdiff_t offset( const Id& id, std::ptrdiff_t i1, std::ptrdiff_t i2 ) {
    return offset_impl< Id >::invoke( id, i1, i2 );
}

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
