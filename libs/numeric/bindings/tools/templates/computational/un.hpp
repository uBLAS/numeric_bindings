$TEMPLATE[ungbr.all.min_size_work.args]
M,N
$TEMPLATE[ungbr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, std::min< $INTEGER_TYPE >( m, n ) );
$TEMPLATE[ungql.all.min_size_work.args]
N
$TEMPLATE[ungql.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, n );
$TEMPLATE[ungqr.all.M.trait_of]
A
$TEMPLATE[ungqr.all.N.trait_of]
A
$TEMPLATE[ungqr.all.K.trait]
size,TAU
$TEMPLATE[ungqr.all.min_size_work.args]
N
$TEMPLATE[ungqr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, n );
$TEMPLATE[unglq.all.min_size_work.args]
M
$TEMPLATE[unglq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ungrq.all.min_size_work.args]
M
$TEMPLATE[ungrq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ungtr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ungtr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ungtr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmbr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmbr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmbr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmhr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmhr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmhr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmlq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmlq.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmlq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmqr.all.K.trait]
size,TAU
$TEMPLATE[unmqr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmqr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmqr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmrq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmrq.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmrq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmql.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmql.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmql.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[unmtr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmtr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[unmtr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[end]
