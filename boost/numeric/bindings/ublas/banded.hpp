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
#include <boost/numeric/bindings/ublas/detail/convert_to.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/numeric/bindings/ublas/matrix_expression.hpp>
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
        mpl::pair< tag::matrix_type, tag::banded >,
        mpl::pair< tag::data_structure, tag::banded_array >,
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

    static std::ptrdiff_t bandwidth1( const Id& id ) {
        return id.upper();
    }

    static std::ptrdiff_t bandwidth2( const Id& id ) {
        return id.lower();
    }

};


template< typename T, typename Id, typename Enable >
struct adaptor< ublas::banded_adaptor< T >, Id, Enable > {

    typedef typename copy_const< Id, typename value< T >::type >::type value_type;
    typedef typename property_insert< T,
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::matrix_type, tag::banded >,
        mpl::pair< tag::bandwidth_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::bandwidth_type<2>, std::ptrdiff_t >
    >::type property_map;

    static std::ptrdiff_t size1( const Id& id ) {
        return bindings::size1( id.data() );
    }

    static std::ptrdiff_t size2( const Id& id ) {
        return bindings::size2( id.data() );
    }

    static value_type* begin_value( Id& id ) {
        return bindings::begin_value( id.data() );
    }

    static value_type* end_value( Id& id ) {
        return bindings::end_value( id.data() );
    }

    static std::ptrdiff_t stride1( const Id& id ) {
        return bindings::stride1( id.data() );
    }

    static std::ptrdiff_t stride2( const Id& id ) {
        return bindings::stride2( id.data() );
    }

    static std::ptrdiff_t bandwidth1( const Id& id ) {
        return id.upper();
    }

    static std::ptrdiff_t bandwidth2( const Id& id ) {
        return id.lower();
    }

};

} // detail
} // bindings
} // numeric
} // boost

#endif
