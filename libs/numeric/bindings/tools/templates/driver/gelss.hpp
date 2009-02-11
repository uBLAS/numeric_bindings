$TEMPLATE[gelss.real.min_size_work.args]
M,N,NRHS
$TEMPLATE[gelss.real.min_size_work]
integer_t minmn = std::min( m, n );
return std::max( 1, 3*minmn + std::max( std::max( 2*minmn, std::max(m,n) ), nrhs ) );
$TEMPLATE[gelss.complex.extra_variables]
MINMN
$TEMPLATE[gelss.complex.extra_opt_variables]
MINMN
$TEMPLATE[gelss.complex.MINMN.init]
integer_t minmn = std::min( traits::matrix_size1(a), traits::matrix_size2(a) );
$TEMPLATE[gelss.complex.min_size_work.args]
M,N,NRHS,MINMN
$TEMPLATE[gelss.complex.min_size_work]
return std::max( 1, 2*minmn + std::max( std::max( m,n ), nrhs ) );
$TEMPLATE[gelss.complex.min_size_rwork.args]
MINMN
$TEMPLATE[gelss.complex.min_size_rwork]
return 5*minmn;
$TEMPLATE[end]
