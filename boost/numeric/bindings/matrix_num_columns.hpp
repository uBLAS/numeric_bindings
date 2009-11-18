//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_MATRIX_NUM_COLUMNS_HPP
#define BOOST_NUMERIC_BINDINGS_MATRIX_NUM_COLUMNS_HPP

#include <boost/numeric/bindings/tensor_size.hpp>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
inline std::ptrdiff_t matrix_num_columns( T const& t ) {
    return tensor_size2( t );
}

} // bindings
} // numeric
} // boost

#endif

