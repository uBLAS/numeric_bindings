$TEMPLATE[gesvd.real.min_size_work.args]
M,N
$TEMPLATE[gesvd.real.min_size_work]
integer_t minmn = std::min< $INTEGER_TYPE >( m, n );
return std::max< $INTEGER_TYPE >( 1, std::max< $INTEGER_TYPE >( 3*minmn+std::max< $INTEGER_TYPE >(m,n), 5*minmn ) );
$TEMPLATE[gesvd.complex.extra_variables]
MINMN
$TEMPLATE[gesvd.complex.extra_opt_variables]
MINMN
$TEMPLATE[gesvd.complex.MINMN.init]
integer_t minmn = std::min< $INTEGER_TYPE >( size_row(a), size_column(a) );
$TEMPLATE[gesvd.complex.min_size_work.args]
M,N,MINMN
$TEMPLATE[gesvd.complex.min_size_work]
return std::max< $INTEGER_TYPE >( 1, 2*minmn+std::max< $INTEGER_TYPE >(m,n) );
$TEMPLATE[gesvd.complex.min_size_rwork.args]
MINMN
$TEMPLATE[gesvd.complex.min_size_rwork]
return 5*minmn;
$TEMPLATE[end]
