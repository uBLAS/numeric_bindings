//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_TAG_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_TAG_HPP

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {
namespace tag {

// key: entity
struct value_type {};
struct entity {};

struct matrix_type {};
struct matrix_side {};

struct data_structure {};
struct data_order {};
struct data_side {};

template< int Rank >
struct tensor: mpl::int_< Rank > {};

struct scalar: tensor<0> {};
struct vector: tensor<1> {};
struct matrix: tensor<2> {};

template< int Dimension >
struct size_type: mpl::int_< Dimension > {};

template< int Dimension >
struct stride_type: mpl::int_< Dimension > {};

struct contiguous: mpl::int_<1> {};

struct linear_array {};
struct triangular_array {};
struct associative_array {};
struct compressed {};
struct coordinate {};

struct structure {};
struct general {};
struct triangular {};
struct symmetric {};

struct num_strides {};

struct row_major {};
struct column_major {};

struct upper {};
struct lower {};
struct unit_upper {};
struct unit_lower {};

} // tag

template< typename T >
struct to_bindings_tag {};

template< typename T >
struct erase_unit {
    typedef T type;
};

template<>
struct erase_unit< tag::unit_upper > {
    typedef tag::upper type;
};

template<>
struct erase_unit< tag::unit_lower > {
    typedef tag::lower type;
};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
