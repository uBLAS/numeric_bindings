$TEMPLATE[gesdd.all.extra_variables]
MINMN
$TEMPLATE[gesdd.all.extra_opt_variables]
MINMN
$TEMPLATE[gesdd.all.MINMN.init]
integer_t minmn = std::min( traits::matrix_size1(a), traits::matrix_size2(a) );
$TEMPLATE[gesdd.all.min_size_work.args]
M, N, JOBZ, MINMN
$TEMPLATE[gesdd.real.min_size_work]
if ( n == 0 ) return 1;
if ( jobz == 'N' ) return 3*minmn + std::max( std::max(m,n), 7*minmn );
if ( jobz == 'O' ) return 3*minmn*minmn + std::max( std::max( m,n ), 5*minmn*minmn + 4*minmn );
return 3*minmn*minmn + std::max( std::max( m,n ), 4*minmn*minmn + 4*minmn );
$TEMPLATE[gesdd.complex.min_size_work]
if ( n == 0 ) return 1;
if ( jobz == 'N' ) return 2*minmn + std::max( m,n );
if ( jobz == 'O' ) return 2*(minmn*minmn + minmn) + std::max( m, n );
return minmn*minmn + 2*minmn + std::max( m, n );
$TEMPLATE[gesdd.all.min_size_iwork.args]
MINMN
$TEMPLATE[gesdd.all.min_size_iwork]
    return 8*minmn;
$TEMPLATE[gesdd.complex.min_size_rwork.args]
MINMN, JOBZ
$TEMPLATE[gesdd.complex.min_size_rwork]
if ( jobz == 'N' ) return 5*minmn;
return 5*minmn*minmn + 7*minmn;
$TEMPLATE[end]
