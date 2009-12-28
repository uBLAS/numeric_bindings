$TEMPLATE[gelsd.includes]
#include <boost/numeric/bindings/lapack/auxiliary/ilaenv.hpp>
$TEMPLATE[gelsd.complex.min_size_rwork.args]
MINMN,SMLSIZ,NLVL,NRHS
$TEMPLATE[gelsd.all.extra_variables]
MINMN,SMLSIZ,NLVL
$TEMPLATE[gelsd.all.MINMN.init]
integer_t minmn = std::min< $INTEGER_TYPE >( size_row(a), size_column(a) );
$TEMPLATE[gelsd.all.SMLSIZ.init]
integer_t smlsiz = ilaenv(9, "GELSD", "");
$TEMPLATE[gelsd.all.NLVL.init]
integer_t nlvl = static_cast<integer_t>(((std::log(static_cast<real_type>(minmn)) / std::log(static_cast<real_type>(2.))) / (smlsiz+1)) + 1);
$TEMPLATE[gelsd.complex.min_size_rwork]
integer_t smlsiz_plus_one = smlsiz + 1;
return std::max< $INTEGER_TYPE >( 1, 10*minmn + 2*minmn*smlsiz + 8*minmn*nlvl + 3*smlsiz*nrhs + smlsiz_plus_one * smlsiz_plus_one );
$TEMPLATE[gelsd.complex.min_size_work.args]
MINMN, NRHS
$TEMPLATE[gelsd.complex.min_size_work]
return std::max< $INTEGER_TYPE >( 1, 2*minmn + minmn*nrhs );
$TEMPLATE[gelsd.all.min_size_iwork.args]
MINMN,NLVL
$TEMPLATE[gelsd.all.min_size_iwork]
return std::max< $INTEGER_TYPE >( 1, 3*minmn*nlvl + 11*minmn );
$TEMPLATE[gelsd.real.min_size_work.args]
MINMN,SMLSIZ, NLVL, NRHS
$TEMPLATE[gelsd.real.min_size_work]
integer_t smlsiz_plus_one = smlsiz + 1;
return std::max< $INTEGER_TYPE >( 1, 12*minmn + 2*minmn*smlsiz + 8*minmn*nlvl + minmn*nrhs + smlsiz_plus_one * smlsiz_plus_one );
$TEMPLATE[end]
