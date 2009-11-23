//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TNT_ARRAY1D_HPP
#define BOOST_NUMERIC_BINDINGS_TNT_ARRAY1D_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <tnt_array1d.h>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable >
struct adaptor< TNT::Array1D< T >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::data_structure, tag::linear_array >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.dim();
    }

    static value_type* data( Id& t ) {
        return &t[0];
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
