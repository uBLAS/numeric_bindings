//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_SIZE_HPP
#define BOOST_NUMERIC_BINDINGS_SIZE_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/tensor_rank.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/min.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/greater.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, int Dimension >
struct is_dynamic_size: is_same<
    typename detail::property_at< T, detail::tag::size_type<Dimension> >::type,
    std::ptrdiff_t > {};

template< int Dimension >
struct get_dynamic_size {};

template<>
struct get_dynamic_size<1> {
    template< typename T >
    static std::ptrdiff_t size( T const& t ) {
        return detail::adaptor_access<T>::size1( t );
    }
};

template<>
struct get_dynamic_size<2> {
    template< typename T >
    static std::ptrdiff_t size( T const& t ) {
        return detail::adaptor_access<T>::size2( t );
    }
};

template<>
struct get_dynamic_size<3> {
    template< typename T >
    static std::ptrdiff_t size( T const& t ) {
        return detail::adaptor_access<T>::size3( t );
    }
};

template<>
struct get_dynamic_size<4> {
    template< typename T >
    static std::ptrdiff_t size( T const& t ) {
        return detail::adaptor_access<T>::size4( t );
    }
};


template< typename T, int Dimension, typename Enable = void >
struct size_impl {};

template< typename T, int Dimension >
struct size_impl< T, Dimension,
        typename boost::enable_if< typename mpl::and_<
            mpl::less_equal< mpl::int_<Dimension>, tensor_rank<T> >,
            is_dynamic_size< T, Dimension > >::type
        >::type > {

    typedef std::ptrdiff_t result_type;

    static std::ptrdiff_t size( T const& t ) {
        return get_dynamic_size<Dimension>::size( t );
    }

};

template< typename T, int Dimension >
struct size_impl< T, Dimension,
        typename boost::enable_if< typename mpl::and_<
            mpl::less_equal< mpl::int_<Dimension>, tensor_rank<T> >,
            mpl::not_< is_dynamic_size< T, Dimension > > >::type
        >::type > {

    typedef typename detail::property_at< T, detail::tag::size_type<Dimension> >::type result_type;

    static result_type size( T const& t ) {
        return result_type();
    }

};

template< typename T, int Dimension >
struct size_impl< T, Dimension,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< mpl::int_<Dimension>, tensor_rank<T> >,
            is_dynamic_size< T, 1 > >::type
        >::type > {

    typedef std::ptrdiff_t result_type;

    static std::ptrdiff_t size( T const& t ) {
        return std::min< std::ptrdiff_t >( size_impl<T,1>::size(t), 1 );
    }

};

template< typename T, int Dimension >
struct size_impl< T, Dimension,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< mpl::int_<Dimension>, tensor_rank<T> >,
            mpl::not_< is_dynamic_size< T, 1 > > >::type
        >::type > {

    typedef typename mpl::min< typename detail::property_at< T, detail::tag::size_type<1> >::type,
        mpl::int_<1> >::type result_type;

    static result_type size( T const& t ) {
        return result_type();
    }

};

} // namespace detail


namespace result_of {

template< typename T, int Dimension >
struct size {
    typedef typename detail::size_impl< T, Dimension >::result_type type;
};

}

template< int Dimension, typename T >
inline typename result_of::size< T const, Dimension >::type size( T const& t ) {
    return detail::size_impl< T const, Dimension >::size( t );
}

template< typename T >
inline std::ptrdiff_t size( T const& t, std::size_t dimension ) {
    switch( dimension ) {
        case 1: return size<1>(t);
        case 2: return size<2>(t);
        case 3: return size<3>(t);
        case 4: return size<4>(t);
        default: return 0;
    }
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

