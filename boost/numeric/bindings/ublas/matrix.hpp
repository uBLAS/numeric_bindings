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
#include <boost/numeric/bindings/detail/dense.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Alloc, typename Id, typename Enable >
struct adaptor< boost::numeric::ublas::matrix< T, Alloc >, Id, Enable > {

    // Generic information
    typedef typename Id::value_type value_type;
    typedef boost::mpl::int_<2> tensor_rank;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.size1();
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return t.size2();
    }

};

} // detail
} // bindings
} // numeric
} // boost

#endif
