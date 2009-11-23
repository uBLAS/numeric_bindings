//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_DETAIL_TO_BINDINGS_TAG_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_DETAIL_TO_BINDINGS_TAG_HPP

#include <boost/numeric/bindings/detail/tag.hpp>
#include <boost/numeric/ublas/fwd.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template<>
struct to_bindings_tag< ublas::lower > {
    typedef tag::lower type;
};

template<>
struct to_bindings_tag< ublas::upper > {
    typedef tag::upper type;
};

template<>
struct to_bindings_tag< ublas::unit_lower > {
    typedef tag::unit_lower type;
};

template<>
struct to_bindings_tag< ublas::unit_upper > {
    typedef tag::unit_upper type;
};

template<>
struct to_bindings_tag< ublas::row_major > {
    typedef tag::row_major type;
};

template<>
struct to_bindings_tag< ublas::column_major > {
    typedef tag::column_major type;
};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
