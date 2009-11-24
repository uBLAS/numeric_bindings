//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/ublas/detail/to_bindings_tag.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename F, typename A, typename Id, typename Enable >
struct adaptor< boost::numeric::ublas::matrix< T, F, A >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::matrix >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::size_type<2>, std::ptrdiff_t >,
        mpl::pair< tag::data_structure, tag::linear_array >,

        // either tag::column_major or tag::row_major
        mpl::pair< tag::data_order, typename detail::to_bindings_tag<F>::type >,

        //
        // is either contiguous in case of column/row major stuff, or it is dynamic, too.
        //
        mpl::pair< tag::stride_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::stride_type<2>, std::ptrdiff_t >,

    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.size1();
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return t.size2();
    }

    static value_type* data( Id& t ) {
        return &t.data()[0];
    }

    static std::ptrdiff_t stride1( Id const& t ) {
        
    }

    static std::ptrdiff_t stride2( Id const& t ) {
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
