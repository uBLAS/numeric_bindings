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

    // Generic information
    typedef T value_type;
    typedef boost::mpl::int_<0> tensor_rank;

};

template< typename T, std::size_t N, typename Id >
struct adaptor< T[N], Id, typename boost::enable_if< is_numeric<T> >::type > {

    // Generic information
    typedef T value_type;
    typedef boost::mpl::int_<1> tensor_rank;

    static std::ptrdiff_t size1( Id const& t ) {
        return N;
    }

};

template< typename T, std::size_t N, std::size_t M, typename Id >
struct adaptor< T[N][M], Id, typename boost::enable_if< is_numeric<T> >::type > {

    // Generic information
    typedef T value_type;
    typedef boost::mpl::int_<2> tensor_rank;

    static std::ptrdiff_t size1( Id const& t ) {
        return N;
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return M;
    }

};

} // detail
} // bindings
} // numeric
} // boost

#endif
