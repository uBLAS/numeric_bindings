$TEMPLATE[ormbr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormbr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormlq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormlq.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormqr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormqr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormrq.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormrq.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormtr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormtr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormql.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormql.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[ormhr.all.min_size_work.args]
SIDE,M,N
$TEMPLATE[ormhr.all.min_size_work]
if ( side == 'L' )
    return std::max< $INTEGER_TYPE >( 1, n );
else
    return std::max< $INTEGER_TYPE >( 1, m );
$TEMPLATE[end]
