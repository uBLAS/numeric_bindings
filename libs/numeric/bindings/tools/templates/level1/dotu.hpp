$TEMPLATE[dotu.all.remove_argument_value_type_prepend]
X,Y
$TEMPLATE[dotu.all.arguments]
 N         (input) INTEGER
           The length of array X
 INCX      (input) INTEGER
           The increment of X
 INCY      (input) INTEGER
           The increment of Y
 X         (input) DATATYPE
 Y         (input) DATATYPE
$TEMPLATE[dotu.friendly_name]
TODO
$TEMPLATE[dotu.level0.gsub]
return cblas_cdotu_sub( n, x, incx, y, incy );->std::complex<float> result;
    cblas_cdotu_sub( n, x, incx, y, incy, &result );
    return result;--return cblas_zdotu_sub( n, x, incx, y, incy );->std::complex<double> result;
    cblas_zdotu_sub( n, x, incx, y, incy, &result );
    return result;--
$TEMPLATE[end]
