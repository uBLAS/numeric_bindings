$TEMPLATE[gelss.real.min_size_work.args]
M,N,NRHS
$TEMPLATE[gelss.real.min_size_work]
integer_t minmn = std::min< $INTEGER_TYPE >( m, n );
return std::max< $INTEGER_TYPE >( 1, 3*minmn + std::max< $INTEGER_TYPE >( std::max< $INTEGER_TYPE >( 2*minmn, std::max< $INTEGER_TYPE >(m,n) ), nrhs ) );
$TEMPLATE[gelss.complex.extra_variables]
MINMN
$TEMPLATE[gelss.complex.extra_opt_variables]
MINMN
$TEMPLATE[gelss.complex.MINMN.init]
integer_t minmn = std::min< $INTEGER_TYPE >( traits::matrix_num_rows(a), traits::matrix_num_columns(a) );
$TEMPLATE[gelss.complex.min_size_work.args]
M,N,NRHS,MINMN
$TEMPLATE[gelss.complex.min_size_work]
return std::max< $INTEGER_TYPE >( 1, 2*minmn + std::max< $INTEGER_TYPE >( std::max< $INTEGER_TYPE >( m,n ), nrhs ) );
$TEMPLATE[gelss.complex.min_size_rwork.args]
MINMN
$TEMPLATE[gelss.complex.min_size_rwork]
return 5*minmn;
$TEMPLATE[end]
