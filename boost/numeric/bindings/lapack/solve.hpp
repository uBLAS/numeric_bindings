//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_SOLVE_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_SOLVE_HPP

#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/lapack/driver/gesv.hpp>
//#include <boost/numeric/bindings/lapack/driver/gbsv.hpp>
//#include <boost/numeric/bindings/lapack/driver/gtsv.hpp>
#include <boost/numeric/bindings/lapack/driver/hesv.hpp>
#include <boost/numeric/bindings/lapack/driver/hpsv.hpp>
#include <boost/numeric/bindings/lapack/driver/posv.hpp>
#include <boost/numeric/bindings/lapack/driver/ppsv.hpp>
#include <boost/numeric/bindings/lapack/driver/pbsv.hpp>
#include <boost/numeric/bindings/lapack/driver/ptsv.hpp>
#include <boost/numeric/bindings/lapack/driver/sysv.hpp>
#include <boost/numeric/bindings/lapack/driver/spsv.hpp>

#include <boost/numeric/bindings/lapack/keywords.hpp>

#include <boost/mpl/at.hpp>
#include <boost/mpl/map.hpp>

#include <boost/parameter/preprocessor.hpp>

namespace mpl = boost::mpl;

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

template< typename Matrix >
struct solve_impl {
    typedef typename traits::matrix_traits< Matrix >::value_type value_type;
    typedef typename traits::matrix_traits< Matrix >::matrix_structure matrix_structure;

    struct null_type {};

    typedef typename mpl::map<
        mpl::pair< traits::general_t, gesv_impl< value_type > >,
        mpl::pair< traits::symmetric_t, sysv_impl< value_type > >,
        mpl::pair< traits::symmetric_packed_t, spsv_impl< value_type > >,
        mpl::pair< traits::hermitian_t, hesv_impl< value_type > >,
        mpl::pair< traits::hermitian_packed_t, hpsv_impl< value_type > >,
  //      mpl::pair< traits::banded_t, gbsv_impl< value_type > >,
        mpl::pair< traits::unknown_structure_t, gesv_impl< value_type > > > simple_map;

    typedef typename mpl::at< simple_map, matrix_structure >::type simple;

};

BOOST_PARAMETER_FUNCTION(
    (void),                      // return type
    solve,                       // name of the resulting function template
    keywords::tag,               // tags namespace
    (required
        (in_out(A), *)
        (in_out(B), *)
    )
    (optional
        (pivot, *,
            typename solve_impl< A_type >::null_type() )
    )
    ) {
        typedef typename solve_impl< A_type >::simple routine;
        integer_t info(0);
        routine::solve( A, B, pivot, info );
    }

}}}} // namespace boost::numeric::bindings::lapack

#endif
