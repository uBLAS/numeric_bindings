//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_BANDED_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_BANDED_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/end.hpp>
#include <boost/numeric/bindings/ublas/detail/basic_ublas_adaptor.hpp>
#include <boost/numeric/bindings/ublas/detail/convert_to.hpp>
#include <boost/numeric/bindings/ublas/matrix_expression.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/ublas/banded.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename F, typename A, typename Id, typename Enable >
struct adaptor< ublas::banded_matrix< T, F, A >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::matrix >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::size_type<2>, std::ptrdiff_t >,
        mpl::pair< tag::matrix_type, tag::band >,
        mpl::pair< tag::data_structure, tag::band_array >,
        mpl::pair< tag::data_order, typename convert_to< tag::data_order, F >::type >,
        mpl::pair< tag::bandwidth_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::bandwidth_type<2>, std::ptrdiff_t >
    > property_map;

    static std::ptrdiff_t size1( const Id& id ) {
        return id.size1();
    }

    static std::ptrdiff_t size2( const Id& id ) {
        return id.size2();
    }

    static value_type* begin_value( Id& id ) {
        return bindings::begin_value( id.data() );
    }

    static value_type* end_value( Id& id ) {
        return bindings::end_value( id.data() );
    }

    // A.k.a. left half-bandwidth
    static std::ptrdiff_t bandwidth1( const Id& id ) {
        return id.lower();
    }

    // A.k.a. right half-bandwidth
    static std::ptrdiff_t bandwidth2( const Id& id ) {
        return id.upper();
    }

};


template< typename T, typename Id, typename Enable >
struct adaptor< ublas::banded_adaptor< T >, Id, Enable >:
    basic_ublas_adaptor<
        T,
        Id,
        mpl::pair< tag::matrix_type, tag::band >,
        mpl::pair< tag::bandwidth_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::bandwidth_type<2>, std::ptrdiff_t >
    > {

    // A.k.a. left half-bandwidth
    static std::ptrdiff_t bandwidth1( const Id& id ) {
        return id.lower();
    }

    // A.k.a. right half-bandwidth
    static std::ptrdiff_t bandwidth2( const Id& id ) {
        return id.upper();
    }

};

} // detail
} // bindings
} // numeric
} // boost

#endif
