//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_SOLVE_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_SOLVE_HPP

#include <boost/numeric/bindings/lapack/driver/gesv.hpp>
#include <boost/numeric/bindings/lapack/driver/gbsv.hpp>
#include <boost/numeric/bindings/lapack/driver/gtsv.hpp>
#include <boost/numeric/bindings/lapack/driver/hesv.hpp>
#include <boost/numeric/bindings/lapack/driver/hpsv.hpp>
#include <boost/numeric/bindings/lapack/driver/posv.hpp>
#include <boost/numeric/bindings/lapack/driver/ppsv.hpp>
#include <boost/numeric/bindings/lapack/driver/pbsv.hpp>
#include <boost/numeric/bindings/lapack/driver/ptsv.hpp>
#include <boost/numeric/bindings/lapack/driver/sysv.hpp>
#include <boost/numeric/bindings/lapack/driver/spsv.hpp>

#include <boost/mpl/map.hpp>

namespace mpl = boost::mpl;

namespace boost {
namespace numeric {
namespace bindings {

template< typename MatrixA, typename MatrixB, typename Workspace >
inline integer_t solve( MatrixA& a, MatrixB& b, Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    typedef typename traits::matrix_traits< MatrixA >::matrix_structure matrix_structure;

    typedef typename mpl::map<
        mpl::pair< traits::general_t, gesv_impl< value_type > >,
        mpl::pair< traits::symmetric_t, sysv_impl< value_type > >,
        mpl::pair< traits::symmetric_packed_t, spsv_impl< value_type > >,
        mpl::pair< traits::hermitian_t, hesv_impl< value_type > >,
        mpl::pair< traits::hermitian_packed_t, hpsv_impl< value_type > >,
        mpl::pair< traits::banded_t, gbsv_impl< value_type > >,
        mpl::pair< traits::unknown_structure_t, gesv_impl< value_type > > > dispatch_map;

    typedef typename mpl::at< dispatch_map, matrix_structure >::type driver_routine;

    int info(0);
    driver_routine::compute( a, b, info, work );
    return info;
}

}}} // namespace boost::numeric::bindings::lapack

#endif
