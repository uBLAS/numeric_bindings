//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_POD_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_POD_HPP

#include <boost/numeric/bindings/is_numeric.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id >
struct adaptor< T, Id, typename boost::enable_if< is_numeric<T> >::type > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::scalar >
    > property_map;

    static value_type* data( Id& t ) {
        return &t;
    }

};

template< typename T, std::size_t N, typename Id >
struct adaptor< T[N], Id, typename boost::enable_if< is_numeric<T> >::type > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::data_structure, tag::linear_array >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return N;
    }

    static value_type* data( Id& t ) {
        return &t[0];
    }

};

template< typename T, std::size_t N, std::size_t M, typename Id >
struct adaptor< T[N][M], Id, typename boost::enable_if< is_numeric<T> >::type > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::matrix >,
        mpl::pair< tag::matrix_type, tag::general >,
        mpl::pair< tag::data_structure, tag::linear_array >,
        mpl::pair< tag::data_order, tag::row_major >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return N;
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return M;
    }

    static value_type* data( Id& t ) {
        return &t[0][0];
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
