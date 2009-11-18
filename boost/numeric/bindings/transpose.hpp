//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TRANSPOSE_HPP
#define BOOST_NUMERIC_BINDINGS_TRANSPOSE_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/mpl/max.hpp>

namespace boost {
namespace numeric {
namespace bindings {

namespace detail {

template< typename T >
struct transpose_wrapper {

    typedef T type;

    transpose_wrapper( T& t ):
        m_ref( t ) {}

    T& get() {
        return m_ref;
    }

    T const& get() const {
        return m_ref;
    }

private:
    T& m_ref;
};

template< typename T, typename Id, typename Enable >
struct adaptor< transpose_wrapper<T>, Id, Enable > {

    typedef typename adaptor_access<T>::value_type value_type;
    typedef typename boost::mpl::max<
            boost::mpl::int_<2>, 
            typename adaptor_access<T>::tensor_rank
        >::type tensor_rank;

    static std::ptrdiff_t size1( Id const& t ) {
        return tensor_size2( t.get() );
    }

    static std::ptrdiff_t size2( Id const& t ) {
        return tensor_size1( t.get() );
    }

};

} // namespace detail


template< typename T >
detail::transpose_wrapper<T> trans( T& underlying ) {
    return detail::transpose_wrapper<T>( underlying );
}

} // bindings
} // numeric
} // boost

#endif

