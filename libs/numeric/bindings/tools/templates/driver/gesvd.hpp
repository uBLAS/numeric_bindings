$TEMPLATE[gesvd.real.min_size_work.args]
JOBU,JOBVT,M,N
$TEMPLATE[gesvd.real.min_size_work]
//
// Contributed by Marco Guazzone
//
if ( m >= n ) {
    if ( jobu == 'N' ) {
        return 5*n;
    } else {
	return std::max< $INTEGER_TYPE >(3*n+m,5*n);
    }
} else {
    if (jobvt == 'N') {
        return 5*m;
    } else {
	return std::max< $INTEGER_TYPE >(3*m+n,5*m);
    }
}
$TEMPLATE[gesvd.complex.extra_variables]
MINMN
$TEMPLATE[gesvd.complex.extra_opt_variables]
MINMN
$TEMPLATE[gesvd.complex.MINMN.init]
$INTEGER_TYPE minmn = std::min< $INTEGER_TYPE >( size_row(a), size_column(a) );
$TEMPLATE[gesvd.complex.min_size_work.args]
M,N,MINMN
$TEMPLATE[gesvd.complex.min_size_work]
return std::max< $INTEGER_TYPE >( 1, 2*minmn+std::max< $INTEGER_TYPE >(m,n) );
$TEMPLATE[gesvd.complex.min_size_rwork.args]
MINMN
$TEMPLATE[gesvd.complex.min_size_rwork]
return 5*minmn;
$TEMPLATE[end]
