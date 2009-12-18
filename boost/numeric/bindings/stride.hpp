//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_STRIDE_HPP
#define BOOST_NUMERIC_BINDINGS_STRIDE_HPP

#include <boost/numeric/bindings/detail/generate_functions.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/get.hpp>
#include <boost/numeric/bindings/index_major.hpp>
#include <boost/numeric/bindings/index_minor.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/mpl/min.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/static_assert.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Index, typename Enable = void >
struct stride_impl {

    typedef tag::stride_type< Index::value > key_type;
    typedef typename result_of_get< T, key_type >::type result_type;

    static result_type invoke( const T& t ) {
        return get< key_type >( t );
    }

};

template< typename T, typename Index >
struct stride_impl< T, Index,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Index, rank<T> >,
            is_same_at< T, tag::stride_type<1>, std::ptrdiff_t >
        >::type >::type > {

    typedef std::ptrdiff_t result_type;

    static result_type invoke( const T& t ) {
        return 0;
    }

};

template< typename T, typename Index >
struct stride_impl< T, Index,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Index, rank<T> >,
            mpl::not_< is_same_at< T, tag::stride_type<1>, std::ptrdiff_t > >
        >::type >::type > {

    typedef typename mpl::int_<0> result_type;

    static result_type invoke( const T& t ) {
        return result_type();
    }

};

} // namespace detail

namespace result_of {

template< typename T, typename Tag = tag::index<1> >
struct stride {
    BOOST_STATIC_ASSERT( (is_tag<Tag>::value) );
    typedef typename detail::stride_impl< T, Tag >::result_type type;
};

} // namespace result_of


//
// Overloads for free template functions stride( x, tag ), 
//
template< typename T, typename Tag >
inline typename result_of::stride< const T, Tag >::type
stride( const T& t, Tag ) {
    return detail::stride_impl< const T, Tag >::invoke( t );
}

// Overloads for free template functions stride( x )
// Valid for types with rank <= 1 (scalars, vectors)
// In theory, we could provide overloads for matrices here, too, 
// if their minimal_rank is at most 1.

template< typename T >
inline typename
boost::enable_if<
    mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::stride< const T, tag::index<1> >::type
>::type
stride( const T& t ) {
    return detail::stride_impl<const T, tag::index<1> >::invoke( t );
}


#define GENERATE_STRIDE_INDEX( z, which, unused ) \
GENERATE_FUNCTIONS( stride, which, tag::index<which> )

BOOST_PP_REPEAT_FROM_TO(1,3,GENERATE_STRIDE_INDEX,~)

GENERATE_FUNCTIONS( stride, _major, typename index_major<T>::type )
GENERATE_FUNCTIONS( stride, _minor, typename index_minor<T>::type )

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
