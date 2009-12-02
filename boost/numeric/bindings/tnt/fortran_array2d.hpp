//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TNT_FORTRAN_ARRAY2D_HPP
#define BOOST_NUMERIC_BINDINGS_TNT_FORTRAN_ARRAY2D_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <tnt_fortran_array2d.h>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable >
struct adaptor< TNT::Fortran_Array2D< T >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::matrix >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::size_type<2>, std::ptrdiff_t >,
        mpl::pair< tag::data_structure, tag::linear_array >,
        mpl::pair< tag::data_order, tag::column_major >,
        mpl::pair< tag::stride_type<1>, tag::contiguous >,
        mpl::pair< tag::stride_type<2>, std::ptrdiff_t >

    > property_map;

    static std::ptrdiff_t size1( const Id& t ) {
        return t.dim1();
    }

    static std::ptrdiff_t size2( const Id& t ) {
        return t.dim2();
    }

    static value_type* begin_value_array( Id& t ) {
        return &t(1,1);
    }

    static std::ptrdiff_t stride2( const Id& t ) {
        return t.dim1();
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
