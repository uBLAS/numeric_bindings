$TEMPLATE[tgsen.all.min_size_work.args]
IJOB,N,SELECT
$TEMPLATE[tgsen.real.min_size_work]
$INTEGER_TYPE m = n/2; // FIXME: num_selected( select );
if ( ijob == 1 || ijob == 2 || ijob == 4 )
    return std::max< $INTEGER_TYPE >(4*n+16, 2*m*(n-m));
else // if ( ijob == 3 || ijob == 5 )
    return std::max< $INTEGER_TYPE >(4*n+16, 4*m*(n-m));
$TEMPLATE[tgsen.complex.min_size_work]
$INTEGER_TYPE m = n/2; // FIXME: num_selected( select );
if ( ijob == 1 || ijob == 2 || ijob == 4 )
    return std::max< $INTEGER_TYPE >(1, 2*m*(n-m));
else // if ( ijob == 3 || ijob == 5 )
    return std::max< $INTEGER_TYPE >(1, 4*m*(n-m));
$TEMPLATE[tgsen.all.min_size_iwork.args]
IJOB,N,SELECT
$TEMPLATE[tgsen.real.min_size_iwork]
$INTEGER_TYPE m = n/2; // FIXME: num_selected( select );
if ( ijob == 1 || ijob == 2 || ijob == 4 )
    return std::max< $INTEGER_TYPE >(1, n+6);
else // if ( ijob == 3 || ijob == 5 )
    return std::max< $INTEGER_TYPE >(2*m*(n-m), n+6);
$TEMPLATE[tgsen.complex.min_size_iwork]
$INTEGER_TYPE m = n/2; // FIXME: num_selected( select );
if ( ijob == 1 || ijob == 2 || ijob == 4 )
    return std::max< $INTEGER_TYPE >(1, n+2);
else // if ( ijob == 3 || ijob == 5 )
    return std::max< $INTEGER_TYPE >(2*m*(n-m), n+2);
$TEMPLATE[end]
