$TEMPLATE[ormbr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormbr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormbr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormlq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormlq.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormlq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormqr.all.K.trait]
size,TAU
$TEMPLATE[ormqr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormqr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormqr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormrq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormrq.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormrq.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormtr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormtr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormtr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormql.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormql.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormql.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[ormhr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormhr.includes]
#include <boost/numeric/bindings/detail/if_left.hpp>
$TEMPLATE[ormhr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, bindings::detail::if_left( side, n, m ) );
$TEMPLATE[end]
