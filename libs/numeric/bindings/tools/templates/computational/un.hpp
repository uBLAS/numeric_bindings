$TEMPLATE[ungbr.all.min_size_work.args]
M,N
$TEMPLATE[ungbr.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, std::min< $INTEGER_TYPE >( m, n ) );
$TEMPLATE[ungql.all.min_size_work.args]
N
$TEMPLATE[ungql.all.min_size_work]
return std::max< $INTEGER_TYPE >( 1, n );
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
$TEMPLATE[ungtr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmbr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmbr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmhr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmhr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmlq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmlq.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmqr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmqr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmrq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmrq.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmql.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmql.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[unmtr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[unmtr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[end]
