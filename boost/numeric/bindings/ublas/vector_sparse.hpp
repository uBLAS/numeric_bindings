//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_VECTOR_SPARSE_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_VECTOR_SPARSE_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename A, typename Id, typename Enable >
struct adaptor< ublas::mapped_vector< T, A >, Id, Enable > {

    typedef mpl::map<
        mpl::pair< tag::value_type, T >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::data_structure, tag::associative_array >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.size();
    }

};

} // detail
} // bindings
} // numeric
} // boost

#endif

