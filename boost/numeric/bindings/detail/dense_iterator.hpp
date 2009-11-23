//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_DETAIL_DENSE_ITERATOR_HPP
#define BOOST_NUMERIC_BINDINGS_DETAIL_DENSE_ITERATOR_HPP

#include <boost/iterator/iterator_adaptor.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T >
class dense_iterator: public boost::iterator_adaptor<
        dense_iterator<T>,
        T* > {
public:
    dense_iterator():
        dense_iterator::iterator_adaptor_(0) {}

    explicit dense_iterator( T* p ):
        dense_iterator::iterator_adaptor_(p) {}

 private:
    friend class boost::iterator_core_access;

    void increment() {
        ++(this->base_reference());
    }

};


} // detail
} // bindings
} // numeric
} // boost

#endif

