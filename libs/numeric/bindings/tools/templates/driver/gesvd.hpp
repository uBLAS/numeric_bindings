$TEMPLATE[gesvd.real.min_size_work.args]
M,N
$TEMPLATE[gesvd.real.min_size_work]
integer_t minmn = std::min( m, n );
return std::max( 1, std::max( 3*minmn+std::max(m,n), 5*minmn ) );
$TEMPLATE[gesvd.complex.extra_variables]
MINMN
$TEMPLATE[gesvd.complex.extra_opt_variables]
MINMN
$TEMPLATE[gesvd.complex.MINMN.init]
integer_t minmn = std::min( traits::matrix_num_rows(a), traits::matrix_num_columns(a) );
$TEMPLATE[gesvd.complex.min_size_work.args]
M,N,MINMN
$TEMPLATE[gesvd.complex.min_size_work]
return std::max( 1, 2*minmn+std::max(m,n) );
$TEMPLATE[gesvd.complex.min_size_rwork.args]
MINMN
$TEMPLATE[gesvd.complex.min_size_rwork]
return 5*minmn;
$TEMPLATE[end]
