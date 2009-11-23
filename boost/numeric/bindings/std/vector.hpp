//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_STD_VECTOR_HPP
#define BOOST_NUMERIC_BINDINGS_STD_VECTOR_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <vector>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Alloc, typename Id, typename Enable >
struct adaptor< std::vector< T, Alloc >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::data_structure, tag::linear_array >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.size();
    }

    static value_type* data( Id& t ) {
        return &t.front();
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
