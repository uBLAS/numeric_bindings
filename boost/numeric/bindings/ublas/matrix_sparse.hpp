//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_SPARSE_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_SPARSE_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/ublas/detail/convert_to.hpp>
#include <boost/numeric/bindings/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename F, std::size_t IB, typename IA, typename TA, typename Id, typename Enable >
struct adaptor< ublas::compressed_matrix< T, F, IB, IA, TA >, Id, Enable > {

    typedef typename convert_to< tag::data_order, F >::type data_order;
    typedef mpl::map<
        mpl::pair< tag::value_type, T >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::size_type<2>, std::ptrdiff_t >,
        mpl::pair< tag::data_structure, tag::yale_sparse >,
        mpl::pair< tag::data_order, data_order >
    > property_map;

    static std::ptrdiff_t size1( const Id& t ) {
        return t.size1();
    }

    static std::ptrdiff_t size2( const Id& t ) {
        return t.size2();
    }
/*
    static void index_data( Id& t ) {
        return t.index_data()
    }*/

    static value_type* begin_value( Id& t ) {
        return bindings::begin_value( t.value_data() );
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
