//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_VOID_PTR_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_VOID_PTR_HPP

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
inline void* void_ptr( T* p) {
    return static_cast< void*>( p );
}

template< typename T >
inline const void* void_ptr( const T* p ) {
    return static_cast< const void* >( p );
}

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
