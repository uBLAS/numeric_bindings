$TEMPLATE[gels.all.min_size_work.args]
M,N,NRHS
$TEMPLATE[gels.all.min_size_work]
integer_t minmn = std::min( m, n );
return std::max( 1, minmn + std::max( minmn, nrhs ) );
$TEMPLATE[end]
