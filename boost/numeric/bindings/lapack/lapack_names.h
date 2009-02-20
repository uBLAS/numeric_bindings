//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_NAMES_H
#define BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_NAMES_H

#ifndef BOOST_NUMERIC_BINDINGS_USE_CLAPACK
#  include <boost/numeric/bindings/traits/fortran.h>
#else
#  define FORTRAN_ID( id ) id##_
#endif

//
// LAPACK computational routines
//

// Value-type variants of hbgst
#define LAPACK_CHBGST FORTRAN_ID( chbgst )
#define LAPACK_ZHBGST FORTRAN_ID( zhbgst )

// Value-type variants of hegst
#define LAPACK_CHEGST FORTRAN_ID( chegst )
#define LAPACK_ZHEGST FORTRAN_ID( zhegst )

// Value-type variants of pbstf
#define LAPACK_SPBSTF FORTRAN_ID( spbstf )
#define LAPACK_DPBSTF FORTRAN_ID( dpbstf )
#define LAPACK_CPBSTF FORTRAN_ID( cpbstf )
#define LAPACK_ZPBSTF FORTRAN_ID( zpbstf )

// Value-type variants of sbgst
#define LAPACK_SSBGST FORTRAN_ID( ssbgst )
#define LAPACK_DSBGST FORTRAN_ID( dsbgst )

// Value-type variants of sygst
#define LAPACK_SSYGST FORTRAN_ID( ssygst )
#define LAPACK_DSYGST FORTRAN_ID( dsygst )

// Value-type variants of ggqrf
#define LAPACK_SGGQRF FORTRAN_ID( sggqrf )
#define LAPACK_DGGQRF FORTRAN_ID( dggqrf )
#define LAPACK_CGGQRF FORTRAN_ID( cggqrf )
#define LAPACK_ZGGQRF FORTRAN_ID( zggqrf )

// Value-type variants of ggrqf
#define LAPACK_SGGRQF FORTRAN_ID( sggrqf )
#define LAPACK_DGGRQF FORTRAN_ID( dggrqf )
#define LAPACK_CGGRQF FORTRAN_ID( cggrqf )
#define LAPACK_ZGGRQF FORTRAN_ID( zggrqf )

// Value-type variants of gelqf
#define LAPACK_SGELQF FORTRAN_ID( sgelqf )
#define LAPACK_DGELQF FORTRAN_ID( dgelqf )
#define LAPACK_CGELQF FORTRAN_ID( cgelqf )
#define LAPACK_ZGELQF FORTRAN_ID( zgelqf )

// Value-type variants of geqlf
#define LAPACK_SGEQLF FORTRAN_ID( sgeqlf )
#define LAPACK_DGEQLF FORTRAN_ID( dgeqlf )
#define LAPACK_CGEQLF FORTRAN_ID( cgeqlf )
#define LAPACK_ZGEQLF FORTRAN_ID( zgeqlf )

// Value-type variants of geqp3
#define LAPACK_SGEQP3 FORTRAN_ID( sgeqp3 )
#define LAPACK_DGEQP3 FORTRAN_ID( dgeqp3 )
#define LAPACK_CGEQP3 FORTRAN_ID( cgeqp3 )
#define LAPACK_ZGEQP3 FORTRAN_ID( zgeqp3 )

// Value-type variants of geqrf
#define LAPACK_SGEQRF FORTRAN_ID( sgeqrf )
#define LAPACK_DGEQRF FORTRAN_ID( dgeqrf )
#define LAPACK_CGEQRF FORTRAN_ID( cgeqrf )
#define LAPACK_ZGEQRF FORTRAN_ID( zgeqrf )

// Value-type variants of gerqf
#define LAPACK_SGERQF FORTRAN_ID( sgerqf )
#define LAPACK_DGERQF FORTRAN_ID( dgerqf )
#define LAPACK_CGERQF FORTRAN_ID( cgerqf )
#define LAPACK_ZGERQF FORTRAN_ID( zgerqf )

// Value-type variants of larz
#define LAPACK_SLARZ FORTRAN_ID( slarz )
#define LAPACK_DLARZ FORTRAN_ID( dlarz )
#define LAPACK_CLARZ FORTRAN_ID( clarz )
#define LAPACK_ZLARZ FORTRAN_ID( zlarz )

// Value-type variants of latrz
#define LAPACK_SLATRZ FORTRAN_ID( slatrz )
#define LAPACK_DLATRZ FORTRAN_ID( dlatrz )
#define LAPACK_CLATRZ FORTRAN_ID( clatrz )
#define LAPACK_ZLATRZ FORTRAN_ID( zlatrz )

// Value-type variants of orglq
#define LAPACK_SORGLQ FORTRAN_ID( sorglq )
#define LAPACK_DORGLQ FORTRAN_ID( dorglq )

// Value-type variants of orgql
#define LAPACK_SORGQL FORTRAN_ID( sorgql )
#define LAPACK_DORGQL FORTRAN_ID( dorgql )

// Value-type variants of orgqr
#define LAPACK_SORGQR FORTRAN_ID( sorgqr )
#define LAPACK_DORGQR FORTRAN_ID( dorgqr )

// Value-type variants of orgrq
#define LAPACK_SORGRQ FORTRAN_ID( sorgrq )
#define LAPACK_DORGRQ FORTRAN_ID( dorgrq )

// Value-type variants of ormlq
#define LAPACK_SORMLQ FORTRAN_ID( sormlq )
#define LAPACK_DORMLQ FORTRAN_ID( dormlq )

// Value-type variants of ormql
#define LAPACK_SORMQL FORTRAN_ID( sormql )
#define LAPACK_DORMQL FORTRAN_ID( dormql )

// Value-type variants of ormqr
#define LAPACK_SORMQR FORTRAN_ID( sormqr )
#define LAPACK_DORMQR FORTRAN_ID( dormqr )

// Value-type variants of ormrq
#define LAPACK_SORMRQ FORTRAN_ID( sormrq )
#define LAPACK_DORMRQ FORTRAN_ID( dormrq )

// Value-type variants of ormrz
#define LAPACK_SORMRZ FORTRAN_ID( sormrz )
#define LAPACK_DORMRZ FORTRAN_ID( dormrz )

// Value-type variants of tzrzf
#define LAPACK_STZRZF FORTRAN_ID( stzrzf )
#define LAPACK_DTZRZF FORTRAN_ID( dtzrzf )
#define LAPACK_CTZRZF FORTRAN_ID( ctzrzf )
#define LAPACK_ZTZRZF FORTRAN_ID( ztzrzf )

// Value-type variants of unglq
#define LAPACK_CUNGLQ FORTRAN_ID( cunglq )
#define LAPACK_ZUNGLQ FORTRAN_ID( zunglq )

// Value-type variants of ungql
#define LAPACK_CUNGQL FORTRAN_ID( cungql )
#define LAPACK_ZUNGQL FORTRAN_ID( zungql )

// Value-type variants of ungqr
#define LAPACK_CUNGQR FORTRAN_ID( cungqr )
#define LAPACK_ZUNGQR FORTRAN_ID( zungqr )

// Value-type variants of ungrq
#define LAPACK_CUNGRQ FORTRAN_ID( cungrq )
#define LAPACK_ZUNGRQ FORTRAN_ID( zungrq )

// Value-type variants of unmlq
#define LAPACK_CUNMLQ FORTRAN_ID( cunmlq )
#define LAPACK_ZUNMLQ FORTRAN_ID( zunmlq )

// Value-type variants of unmql
#define LAPACK_CUNMQL FORTRAN_ID( cunmql )
#define LAPACK_ZUNMQL FORTRAN_ID( zunmql )

// Value-type variants of unmqr
#define LAPACK_CUNMQR FORTRAN_ID( cunmqr )
#define LAPACK_ZUNMQR FORTRAN_ID( zunmqr )

// Value-type variants of unmrq
#define LAPACK_CUNMRQ FORTRAN_ID( cunmrq )
#define LAPACK_ZUNMRQ FORTRAN_ID( zunmrq )

// Value-type variants of unmrz
#define LAPACK_CUNMRZ FORTRAN_ID( cunmrz )
#define LAPACK_ZUNMRZ FORTRAN_ID( zunmrz )

// Value-type variants of bdsdc
#define LAPACK_SBDSDC FORTRAN_ID( sbdsdc )
#define LAPACK_DBDSDC FORTRAN_ID( dbdsdc )

// Value-type variants of bdsqr
#define LAPACK_SBDSQR FORTRAN_ID( sbdsqr )
#define LAPACK_DBDSQR FORTRAN_ID( dbdsqr )
#define LAPACK_CBDSQR FORTRAN_ID( cbdsqr )
#define LAPACK_ZBDSQR FORTRAN_ID( zbdsqr )

// Value-type variants of gbbrd
#define LAPACK_SGBBRD FORTRAN_ID( sgbbrd )
#define LAPACK_DGBBRD FORTRAN_ID( dgbbrd )
#define LAPACK_CGBBRD FORTRAN_ID( cgbbrd )
#define LAPACK_ZGBBRD FORTRAN_ID( zgbbrd )

// Value-type variants of gebrd
#define LAPACK_SGEBRD FORTRAN_ID( sgebrd )
#define LAPACK_DGEBRD FORTRAN_ID( dgebrd )
#define LAPACK_CGEBRD FORTRAN_ID( cgebrd )
#define LAPACK_ZGEBRD FORTRAN_ID( zgebrd )

// Value-type variants of labrd
#define LAPACK_SLABRD FORTRAN_ID( slabrd )
#define LAPACK_DLABRD FORTRAN_ID( dlabrd )
#define LAPACK_CLABRD FORTRAN_ID( clabrd )
#define LAPACK_ZLABRD FORTRAN_ID( zlabrd )

// Value-type variants of orgbr
#define LAPACK_SORGBR FORTRAN_ID( sorgbr )
#define LAPACK_DORGBR FORTRAN_ID( dorgbr )

// Value-type variants of ormbr
#define LAPACK_SORMBR FORTRAN_ID( sormbr )
#define LAPACK_DORMBR FORTRAN_ID( dormbr )

// Value-type variants of ungbr
#define LAPACK_CUNGBR FORTRAN_ID( cungbr )
#define LAPACK_ZUNGBR FORTRAN_ID( zungbr )

// Value-type variants of unmbr
#define LAPACK_CUNMBR FORTRAN_ID( cunmbr )
#define LAPACK_ZUNMBR FORTRAN_ID( zunmbr )

// Value-type variants of gebak
#define LAPACK_SGEBAK FORTRAN_ID( sgebak )
#define LAPACK_DGEBAK FORTRAN_ID( dgebak )
#define LAPACK_CGEBAK FORTRAN_ID( cgebak )
#define LAPACK_ZGEBAK FORTRAN_ID( zgebak )

// Value-type variants of gebal
#define LAPACK_SGEBAL FORTRAN_ID( sgebal )
#define LAPACK_DGEBAL FORTRAN_ID( dgebal )
#define LAPACK_CGEBAL FORTRAN_ID( cgebal )
#define LAPACK_ZGEBAL FORTRAN_ID( zgebal )

// Value-type variants of gehrd
#define LAPACK_SGEHRD FORTRAN_ID( sgehrd )
#define LAPACK_DGEHRD FORTRAN_ID( dgehrd )
#define LAPACK_CGEHRD FORTRAN_ID( cgehrd )
#define LAPACK_ZGEHRD FORTRAN_ID( zgehrd )

// Value-type variants of hsein
#define LAPACK_SHSEIN FORTRAN_ID( shsein )
#define LAPACK_DHSEIN FORTRAN_ID( dhsein )
#define LAPACK_CHSEIN FORTRAN_ID( chsein )
#define LAPACK_ZHSEIN FORTRAN_ID( zhsein )

// Value-type variants of hseqr
#define LAPACK_SHSEQR FORTRAN_ID( shseqr )
#define LAPACK_DHSEQR FORTRAN_ID( dhseqr )
#define LAPACK_CHSEQR FORTRAN_ID( chseqr )
#define LAPACK_ZHSEQR FORTRAN_ID( zhseqr )

// Value-type variants of orghr
#define LAPACK_SORGHR FORTRAN_ID( sorghr )
#define LAPACK_DORGHR FORTRAN_ID( dorghr )

// Value-type variants of ormhr
#define LAPACK_SORMHR FORTRAN_ID( sormhr )
#define LAPACK_DORMHR FORTRAN_ID( dormhr )

// Value-type variants of trevc
#define LAPACK_STREVC FORTRAN_ID( strevc )
#define LAPACK_DTREVC FORTRAN_ID( dtrevc )
#define LAPACK_CTREVC FORTRAN_ID( ctrevc )
#define LAPACK_ZTREVC FORTRAN_ID( ztrevc )

// Value-type variants of trexc
#define LAPACK_STREXC FORTRAN_ID( strexc )
#define LAPACK_DTREXC FORTRAN_ID( dtrexc )
#define LAPACK_CTREXC FORTRAN_ID( ctrexc )
#define LAPACK_ZTREXC FORTRAN_ID( ztrexc )

// Value-type variants of trsen
#define LAPACK_CTRSEN FORTRAN_ID( ctrsen )
#define LAPACK_ZTRSEN FORTRAN_ID( ztrsen )

// Value-type variants of trsna
#define LAPACK_STRSNA FORTRAN_ID( strsna )
#define LAPACK_DTRSNA FORTRAN_ID( dtrsna )
#define LAPACK_CTRSNA FORTRAN_ID( ctrsna )
#define LAPACK_ZTRSNA FORTRAN_ID( ztrsna )

// Value-type variants of trsyl
#define LAPACK_STRSYL FORTRAN_ID( strsyl )
#define LAPACK_DTRSYL FORTRAN_ID( dtrsyl )
#define LAPACK_CTRSYL FORTRAN_ID( ctrsyl )
#define LAPACK_ZTRSYL FORTRAN_ID( ztrsyl )

// Value-type variants of unghr
#define LAPACK_CUNGHR FORTRAN_ID( cunghr )
#define LAPACK_ZUNGHR FORTRAN_ID( zunghr )

// Value-type variants of unmhr
#define LAPACK_CUNMHR FORTRAN_ID( cunmhr )
#define LAPACK_ZUNMHR FORTRAN_ID( zunmhr )

// Value-type variants of gbcon
#define LAPACK_SGBCON FORTRAN_ID( sgbcon )
#define LAPACK_DGBCON FORTRAN_ID( dgbcon )
#define LAPACK_CGBCON FORTRAN_ID( cgbcon )
#define LAPACK_ZGBCON FORTRAN_ID( zgbcon )

// Value-type variants of gbequ
#define LAPACK_SGBEQU FORTRAN_ID( sgbequ )
#define LAPACK_DGBEQU FORTRAN_ID( dgbequ )
#define LAPACK_CGBEQU FORTRAN_ID( cgbequ )
#define LAPACK_ZGBEQU FORTRAN_ID( zgbequ )

// Value-type variants of gbrfs
#define LAPACK_SGBRFS FORTRAN_ID( sgbrfs )
#define LAPACK_DGBRFS FORTRAN_ID( dgbrfs )
#define LAPACK_CGBRFS FORTRAN_ID( cgbrfs )
#define LAPACK_ZGBRFS FORTRAN_ID( zgbrfs )

// Value-type variants of gbtrf
#define LAPACK_SGBTRF FORTRAN_ID( sgbtrf )
#define LAPACK_DGBTRF FORTRAN_ID( dgbtrf )
#define LAPACK_CGBTRF FORTRAN_ID( cgbtrf )
#define LAPACK_ZGBTRF FORTRAN_ID( zgbtrf )

// Value-type variants of gbtrs
#define LAPACK_SGBTRS FORTRAN_ID( sgbtrs )
#define LAPACK_DGBTRS FORTRAN_ID( dgbtrs )
#define LAPACK_CGBTRS FORTRAN_ID( cgbtrs )
#define LAPACK_ZGBTRS FORTRAN_ID( zgbtrs )

// Value-type variants of gecon
#define LAPACK_SGECON FORTRAN_ID( sgecon )
#define LAPACK_DGECON FORTRAN_ID( dgecon )
#define LAPACK_CGECON FORTRAN_ID( cgecon )
#define LAPACK_ZGECON FORTRAN_ID( zgecon )

// Value-type variants of geequ
#define LAPACK_SGEEQU FORTRAN_ID( sgeequ )
#define LAPACK_DGEEQU FORTRAN_ID( dgeequ )
#define LAPACK_CGEEQU FORTRAN_ID( cgeequ )
#define LAPACK_ZGEEQU FORTRAN_ID( zgeequ )

// Value-type variants of gerfs
#define LAPACK_SGERFS FORTRAN_ID( sgerfs )
#define LAPACK_DGERFS FORTRAN_ID( dgerfs )
#define LAPACK_CGERFS FORTRAN_ID( cgerfs )
#define LAPACK_ZGERFS FORTRAN_ID( zgerfs )

// Value-type variants of getrf
#define LAPACK_SGETRF FORTRAN_ID( sgetrf )
#define LAPACK_DGETRF FORTRAN_ID( dgetrf )
#define LAPACK_CGETRF FORTRAN_ID( cgetrf )
#define LAPACK_ZGETRF FORTRAN_ID( zgetrf )

// Value-type variants of getri
#define LAPACK_SGETRI FORTRAN_ID( sgetri )
#define LAPACK_DGETRI FORTRAN_ID( dgetri )
#define LAPACK_CGETRI FORTRAN_ID( cgetri )
#define LAPACK_ZGETRI FORTRAN_ID( zgetri )

// Value-type variants of getrs
#define LAPACK_SGETRS FORTRAN_ID( sgetrs )
#define LAPACK_DGETRS FORTRAN_ID( dgetrs )
#define LAPACK_CGETRS FORTRAN_ID( cgetrs )
#define LAPACK_ZGETRS FORTRAN_ID( zgetrs )

// Value-type variants of gtrfs
#define LAPACK_SGTRFS FORTRAN_ID( sgtrfs )
#define LAPACK_DGTRFS FORTRAN_ID( dgtrfs )
#define LAPACK_CGTRFS FORTRAN_ID( cgtrfs )
#define LAPACK_ZGTRFS FORTRAN_ID( zgtrfs )

// Value-type variants of gttrs
#define LAPACK_SGTTRS FORTRAN_ID( sgttrs )
#define LAPACK_DGTTRS FORTRAN_ID( dgttrs )
#define LAPACK_CGTTRS FORTRAN_ID( cgttrs )
#define LAPACK_ZGTTRS FORTRAN_ID( zgttrs )

// Value-type variants of hecon
#define LAPACK_CHECON FORTRAN_ID( checon )
#define LAPACK_ZHECON FORTRAN_ID( zhecon )

// Value-type variants of herfs
#define LAPACK_CHERFS FORTRAN_ID( cherfs )
#define LAPACK_ZHERFS FORTRAN_ID( zherfs )

// Value-type variants of hetrf
#define LAPACK_CHETRF FORTRAN_ID( chetrf )
#define LAPACK_ZHETRF FORTRAN_ID( zhetrf )

// Value-type variants of hetri
#define LAPACK_CHETRI FORTRAN_ID( chetri )
#define LAPACK_ZHETRI FORTRAN_ID( zhetri )

// Value-type variants of hetrs
#define LAPACK_CHETRS FORTRAN_ID( chetrs )
#define LAPACK_ZHETRS FORTRAN_ID( zhetrs )

// Value-type variants of hprfs
#define LAPACK_CHPRFS FORTRAN_ID( chprfs )
#define LAPACK_ZHPRFS FORTRAN_ID( zhprfs )

// Value-type variants of hptrs
#define LAPACK_CHPTRS FORTRAN_ID( chptrs )
#define LAPACK_ZHPTRS FORTRAN_ID( zhptrs )

// Value-type variants of lacon
#define LAPACK_SLACON FORTRAN_ID( slacon )
#define LAPACK_DLACON FORTRAN_ID( dlacon )
#define LAPACK_CLACON FORTRAN_ID( clacon )
#define LAPACK_ZLACON FORTRAN_ID( zlacon )

// Value-type variants of latrs
#define LAPACK_SLATRS FORTRAN_ID( slatrs )
#define LAPACK_DLATRS FORTRAN_ID( dlatrs )
#define LAPACK_CLATRS FORTRAN_ID( clatrs )
#define LAPACK_ZLATRS FORTRAN_ID( zlatrs )

// Value-type variants of pbcon
#define LAPACK_SPBCON FORTRAN_ID( spbcon )
#define LAPACK_DPBCON FORTRAN_ID( dpbcon )
#define LAPACK_CPBCON FORTRAN_ID( cpbcon )
#define LAPACK_ZPBCON FORTRAN_ID( zpbcon )

// Value-type variants of pbequ
#define LAPACK_SPBEQU FORTRAN_ID( spbequ )
#define LAPACK_DPBEQU FORTRAN_ID( dpbequ )
#define LAPACK_CPBEQU FORTRAN_ID( cpbequ )
#define LAPACK_ZPBEQU FORTRAN_ID( zpbequ )

// Value-type variants of pbrfs
#define LAPACK_SPBRFS FORTRAN_ID( spbrfs )
#define LAPACK_DPBRFS FORTRAN_ID( dpbrfs )
#define LAPACK_CPBRFS FORTRAN_ID( cpbrfs )
#define LAPACK_ZPBRFS FORTRAN_ID( zpbrfs )

// Value-type variants of pbtrf
#define LAPACK_SPBTRF FORTRAN_ID( spbtrf )
#define LAPACK_DPBTRF FORTRAN_ID( dpbtrf )
#define LAPACK_CPBTRF FORTRAN_ID( cpbtrf )
#define LAPACK_ZPBTRF FORTRAN_ID( zpbtrf )

// Value-type variants of pbtrs
#define LAPACK_SPBTRS FORTRAN_ID( spbtrs )
#define LAPACK_DPBTRS FORTRAN_ID( dpbtrs )
#define LAPACK_CPBTRS FORTRAN_ID( cpbtrs )
#define LAPACK_ZPBTRS FORTRAN_ID( zpbtrs )

// Value-type variants of pocon
#define LAPACK_SPOCON FORTRAN_ID( spocon )
#define LAPACK_DPOCON FORTRAN_ID( dpocon )
#define LAPACK_CPOCON FORTRAN_ID( cpocon )
#define LAPACK_ZPOCON FORTRAN_ID( zpocon )

// Value-type variants of poequ
#define LAPACK_SPOEQU FORTRAN_ID( spoequ )
#define LAPACK_DPOEQU FORTRAN_ID( dpoequ )
#define LAPACK_CPOEQU FORTRAN_ID( cpoequ )
#define LAPACK_ZPOEQU FORTRAN_ID( zpoequ )

// Value-type variants of porfs
#define LAPACK_SPORFS FORTRAN_ID( sporfs )
#define LAPACK_DPORFS FORTRAN_ID( dporfs )
#define LAPACK_CPORFS FORTRAN_ID( cporfs )
#define LAPACK_ZPORFS FORTRAN_ID( zporfs )

// Value-type variants of potrf
#define LAPACK_SPOTRF FORTRAN_ID( spotrf )
#define LAPACK_DPOTRF FORTRAN_ID( dpotrf )
#define LAPACK_CPOTRF FORTRAN_ID( cpotrf )
#define LAPACK_ZPOTRF FORTRAN_ID( zpotrf )

// Value-type variants of potri
#define LAPACK_SPOTRI FORTRAN_ID( spotri )
#define LAPACK_DPOTRI FORTRAN_ID( dpotri )
#define LAPACK_CPOTRI FORTRAN_ID( cpotri )
#define LAPACK_ZPOTRI FORTRAN_ID( zpotri )

// Value-type variants of potrs
#define LAPACK_SPOTRS FORTRAN_ID( spotrs )
#define LAPACK_DPOTRS FORTRAN_ID( dpotrs )
#define LAPACK_CPOTRS FORTRAN_ID( cpotrs )
#define LAPACK_ZPOTRS FORTRAN_ID( zpotrs )

// Value-type variants of pprfs
#define LAPACK_SPPRFS FORTRAN_ID( spprfs )
#define LAPACK_DPPRFS FORTRAN_ID( dpprfs )
#define LAPACK_CPPRFS FORTRAN_ID( cpprfs )
#define LAPACK_ZPPRFS FORTRAN_ID( zpprfs )

// Value-type variants of pptrs
#define LAPACK_SPPTRS FORTRAN_ID( spptrs )
#define LAPACK_DPPTRS FORTRAN_ID( dpptrs )
#define LAPACK_CPPTRS FORTRAN_ID( cpptrs )
#define LAPACK_ZPPTRS FORTRAN_ID( zpptrs )

// Value-type variants of ptrfs
#define LAPACK_SPTRFS FORTRAN_ID( sptrfs )
#define LAPACK_DPTRFS FORTRAN_ID( dptrfs )
#define LAPACK_CPTRFS FORTRAN_ID( cptrfs )
#define LAPACK_ZPTRFS FORTRAN_ID( zptrfs )

// Value-type variants of pttrs
#define LAPACK_SPTTRS FORTRAN_ID( spttrs )
#define LAPACK_DPTTRS FORTRAN_ID( dpttrs )
#define LAPACK_CPTTRS FORTRAN_ID( cpttrs )
#define LAPACK_ZPTTRS FORTRAN_ID( zpttrs )

// Value-type variants of sprfs
#define LAPACK_SSPRFS FORTRAN_ID( ssprfs )
#define LAPACK_DSPRFS FORTRAN_ID( dsprfs )
#define LAPACK_CSPRFS FORTRAN_ID( csprfs )
#define LAPACK_ZSPRFS FORTRAN_ID( zsprfs )

// Value-type variants of sptrs
#define LAPACK_SSPTRS FORTRAN_ID( ssptrs )
#define LAPACK_DSPTRS FORTRAN_ID( dsptrs )
#define LAPACK_CSPTRS FORTRAN_ID( csptrs )
#define LAPACK_ZSPTRS FORTRAN_ID( zsptrs )

// Value-type variants of sycon
#define LAPACK_SSYCON FORTRAN_ID( ssycon )
#define LAPACK_DSYCON FORTRAN_ID( dsycon )
#define LAPACK_CSYCON FORTRAN_ID( csycon )
#define LAPACK_ZSYCON FORTRAN_ID( zsycon )

// Value-type variants of syrfs
#define LAPACK_SSYRFS FORTRAN_ID( ssyrfs )
#define LAPACK_DSYRFS FORTRAN_ID( dsyrfs )
#define LAPACK_CSYRFS FORTRAN_ID( csyrfs )
#define LAPACK_ZSYRFS FORTRAN_ID( zsyrfs )

// Value-type variants of sytrf
#define LAPACK_SSYTRF FORTRAN_ID( ssytrf )
#define LAPACK_DSYTRF FORTRAN_ID( dsytrf )
#define LAPACK_CSYTRF FORTRAN_ID( csytrf )
#define LAPACK_ZSYTRF FORTRAN_ID( zsytrf )

// Value-type variants of sytri
#define LAPACK_SSYTRI FORTRAN_ID( ssytri )
#define LAPACK_DSYTRI FORTRAN_ID( dsytri )
#define LAPACK_CSYTRI FORTRAN_ID( csytri )
#define LAPACK_ZSYTRI FORTRAN_ID( zsytri )

// Value-type variants of sytrs
#define LAPACK_SSYTRS FORTRAN_ID( ssytrs )
#define LAPACK_DSYTRS FORTRAN_ID( dsytrs )
#define LAPACK_CSYTRS FORTRAN_ID( csytrs )
#define LAPACK_ZSYTRS FORTRAN_ID( zsytrs )

// Value-type variants of tbcon
#define LAPACK_STBCON FORTRAN_ID( stbcon )
#define LAPACK_DTBCON FORTRAN_ID( dtbcon )
#define LAPACK_CTBCON FORTRAN_ID( ctbcon )
#define LAPACK_ZTBCON FORTRAN_ID( ztbcon )

// Value-type variants of tbrfs
#define LAPACK_STBRFS FORTRAN_ID( stbrfs )
#define LAPACK_DTBRFS FORTRAN_ID( dtbrfs )
#define LAPACK_CTBRFS FORTRAN_ID( ctbrfs )
#define LAPACK_ZTBRFS FORTRAN_ID( ztbrfs )

// Value-type variants of tbtrs
#define LAPACK_STBTRS FORTRAN_ID( stbtrs )
#define LAPACK_DTBTRS FORTRAN_ID( dtbtrs )
#define LAPACK_CTBTRS FORTRAN_ID( ctbtrs )
#define LAPACK_ZTBTRS FORTRAN_ID( ztbtrs )

// Value-type variants of tprfs
#define LAPACK_STPRFS FORTRAN_ID( stprfs )
#define LAPACK_DTPRFS FORTRAN_ID( dtprfs )
#define LAPACK_CTPRFS FORTRAN_ID( ctprfs )
#define LAPACK_ZTPRFS FORTRAN_ID( ztprfs )

// Value-type variants of tptrs
#define LAPACK_STPTRS FORTRAN_ID( stptrs )
#define LAPACK_DTPTRS FORTRAN_ID( dtptrs )
#define LAPACK_CTPTRS FORTRAN_ID( ctptrs )
#define LAPACK_ZTPTRS FORTRAN_ID( ztptrs )

// Value-type variants of trcon
#define LAPACK_STRCON FORTRAN_ID( strcon )
#define LAPACK_DTRCON FORTRAN_ID( dtrcon )
#define LAPACK_CTRCON FORTRAN_ID( ctrcon )
#define LAPACK_ZTRCON FORTRAN_ID( ztrcon )

// Value-type variants of trrfs
#define LAPACK_STRRFS FORTRAN_ID( strrfs )
#define LAPACK_DTRRFS FORTRAN_ID( dtrrfs )
#define LAPACK_CTRRFS FORTRAN_ID( ctrrfs )
#define LAPACK_ZTRRFS FORTRAN_ID( ztrrfs )

// Value-type variants of trtri
#define LAPACK_STRTRI FORTRAN_ID( strtri )
#define LAPACK_DTRTRI FORTRAN_ID( dtrtri )
#define LAPACK_CTRTRI FORTRAN_ID( ctrtri )
#define LAPACK_ZTRTRI FORTRAN_ID( ztrtri )

// Value-type variants of trtrs
#define LAPACK_STRTRS FORTRAN_ID( strtrs )
#define LAPACK_DTRTRS FORTRAN_ID( dtrtrs )
#define LAPACK_CTRTRS FORTRAN_ID( ctrtrs )
#define LAPACK_ZTRTRS FORTRAN_ID( ztrtrs )

// Value-type variants of hbtrd
#define LAPACK_CHBTRD FORTRAN_ID( chbtrd )
#define LAPACK_ZHBTRD FORTRAN_ID( zhbtrd )

// Value-type variants of hetrd
#define LAPACK_CHETRD FORTRAN_ID( chetrd )
#define LAPACK_ZHETRD FORTRAN_ID( zhetrd )

// Value-type variants of laebz
#define LAPACK_SLAEBZ FORTRAN_ID( slaebz )
#define LAPACK_DLAEBZ FORTRAN_ID( dlaebz )

// Value-type variants of latrd
#define LAPACK_SLATRD FORTRAN_ID( slatrd )
#define LAPACK_DLATRD FORTRAN_ID( dlatrd )
#define LAPACK_CLATRD FORTRAN_ID( clatrd )
#define LAPACK_ZLATRD FORTRAN_ID( zlatrd )

// Value-type variants of opgtr
#define LAPACK_SOPGTR FORTRAN_ID( sopgtr )
#define LAPACK_DOPGTR FORTRAN_ID( dopgtr )

// Value-type variants of opmtr
#define LAPACK_SOPMTR FORTRAN_ID( sopmtr )
#define LAPACK_DOPMTR FORTRAN_ID( dopmtr )

// Value-type variants of orgtr
#define LAPACK_SORGTR FORTRAN_ID( sorgtr )
#define LAPACK_DORGTR FORTRAN_ID( dorgtr )

// Value-type variants of ormtr
#define LAPACK_SORMTR FORTRAN_ID( sormtr )
#define LAPACK_DORMTR FORTRAN_ID( dormtr )

// Value-type variants of pteqr
#define LAPACK_SPTEQR FORTRAN_ID( spteqr )
#define LAPACK_DPTEQR FORTRAN_ID( dpteqr )
#define LAPACK_CPTEQR FORTRAN_ID( cpteqr )
#define LAPACK_ZPTEQR FORTRAN_ID( zpteqr )

// Value-type variants of sbtrd
#define LAPACK_SSBTRD FORTRAN_ID( ssbtrd )
#define LAPACK_DSBTRD FORTRAN_ID( dsbtrd )

// Value-type variants of stebz
#define LAPACK_SSTEBZ FORTRAN_ID( sstebz )
#define LAPACK_DSTEBZ FORTRAN_ID( dstebz )

// Value-type variants of stedc
#define LAPACK_SSTEDC FORTRAN_ID( sstedc )
#define LAPACK_DSTEDC FORTRAN_ID( dstedc )
#define LAPACK_CSTEDC FORTRAN_ID( cstedc )
#define LAPACK_ZSTEDC FORTRAN_ID( zstedc )

// Value-type variants of stegr
#define LAPACK_SSTEGR FORTRAN_ID( sstegr )
#define LAPACK_DSTEGR FORTRAN_ID( dstegr )
#define LAPACK_CSTEGR FORTRAN_ID( cstegr )
#define LAPACK_ZSTEGR FORTRAN_ID( zstegr )

// Value-type variants of stein
#define LAPACK_SSTEIN FORTRAN_ID( sstein )
#define LAPACK_DSTEIN FORTRAN_ID( dstein )
#define LAPACK_CSTEIN FORTRAN_ID( cstein )
#define LAPACK_ZSTEIN FORTRAN_ID( zstein )

// Value-type variants of steqr
#define LAPACK_SSTEQR FORTRAN_ID( ssteqr )
#define LAPACK_DSTEQR FORTRAN_ID( dsteqr )
#define LAPACK_CSTEQR FORTRAN_ID( csteqr )
#define LAPACK_ZSTEQR FORTRAN_ID( zsteqr )

// Value-type variants of sterf
#define LAPACK_SSTERF FORTRAN_ID( ssterf )
#define LAPACK_DSTERF FORTRAN_ID( dsterf )

// Value-type variants of sytrd
#define LAPACK_SSYTRD FORTRAN_ID( ssytrd )
#define LAPACK_DSYTRD FORTRAN_ID( dsytrd )

// Value-type variants of ungtr
#define LAPACK_CUNGTR FORTRAN_ID( cungtr )
#define LAPACK_ZUNGTR FORTRAN_ID( zungtr )

// Value-type variants of unmtr
#define LAPACK_CUNMTR FORTRAN_ID( cunmtr )
#define LAPACK_ZUNMTR FORTRAN_ID( zunmtr )

// Value-type variants of upgtr
#define LAPACK_CUPGTR FORTRAN_ID( cupgtr )
#define LAPACK_ZUPGTR FORTRAN_ID( zupgtr )

// Value-type variants of upmtr
#define LAPACK_CUPMTR FORTRAN_ID( cupmtr )
#define LAPACK_ZUPMTR FORTRAN_ID( zupmtr )

// Value-type variants of ggbak
#define LAPACK_SGGBAK FORTRAN_ID( sggbak )
#define LAPACK_DGGBAK FORTRAN_ID( dggbak )
#define LAPACK_CGGBAK FORTRAN_ID( cggbak )
#define LAPACK_ZGGBAK FORTRAN_ID( zggbak )

// Value-type variants of ggbal
#define LAPACK_SGGBAL FORTRAN_ID( sggbal )
#define LAPACK_DGGBAL FORTRAN_ID( dggbal )
#define LAPACK_CGGBAL FORTRAN_ID( cggbal )
#define LAPACK_ZGGBAL FORTRAN_ID( zggbal )

// Value-type variants of gghrd
#define LAPACK_SGGHRD FORTRAN_ID( sgghrd )
#define LAPACK_DGGHRD FORTRAN_ID( dgghrd )
#define LAPACK_CGGHRD FORTRAN_ID( cgghrd )
#define LAPACK_ZGGHRD FORTRAN_ID( zgghrd )

// Value-type variants of hgeqz
#define LAPACK_SHGEQZ FORTRAN_ID( shgeqz )
#define LAPACK_DHGEQZ FORTRAN_ID( dhgeqz )
#define LAPACK_CHGEQZ FORTRAN_ID( chgeqz )
#define LAPACK_ZHGEQZ FORTRAN_ID( zhgeqz )

// Value-type variants of tgevc
#define LAPACK_STGEVC FORTRAN_ID( stgevc )
#define LAPACK_DTGEVC FORTRAN_ID( dtgevc )
#define LAPACK_CTGEVC FORTRAN_ID( ctgevc )
#define LAPACK_ZTGEVC FORTRAN_ID( ztgevc )

// Value-type variants of tgexc
#define LAPACK_STGEXC FORTRAN_ID( stgexc )
#define LAPACK_DTGEXC FORTRAN_ID( dtgexc )
#define LAPACK_CTGEXC FORTRAN_ID( ctgexc )
#define LAPACK_ZTGEXC FORTRAN_ID( ztgexc )

// Value-type variants of tgsen
#define LAPACK_STGSEN FORTRAN_ID( stgsen )
#define LAPACK_DTGSEN FORTRAN_ID( dtgsen )
#define LAPACK_CTGSEN FORTRAN_ID( ctgsen )
#define LAPACK_ZTGSEN FORTRAN_ID( ztgsen )

// Value-type variants of tgsna
#define LAPACK_STGSNA FORTRAN_ID( stgsna )
#define LAPACK_DTGSNA FORTRAN_ID( dtgsna )
#define LAPACK_CTGSNA FORTRAN_ID( ctgsna )
#define LAPACK_ZTGSNA FORTRAN_ID( ztgsna )

// Value-type variants of tgsyl
#define LAPACK_STGSYL FORTRAN_ID( stgsyl )
#define LAPACK_DTGSYL FORTRAN_ID( dtgsyl )
#define LAPACK_CTGSYL FORTRAN_ID( ctgsyl )
#define LAPACK_ZTGSYL FORTRAN_ID( ztgsyl )

// Value-type variants of ggsvp
#define LAPACK_SGGSVP FORTRAN_ID( sggsvp )
#define LAPACK_DGGSVP FORTRAN_ID( dggsvp )
#define LAPACK_CGGSVP FORTRAN_ID( cggsvp )
#define LAPACK_ZGGSVP FORTRAN_ID( zggsvp )

// Value-type variants of tgsja
#define LAPACK_STGSJA FORTRAN_ID( stgsja )
#define LAPACK_DTGSJA FORTRAN_ID( dtgsja )
#define LAPACK_CTGSJA FORTRAN_ID( ctgsja )
#define LAPACK_ZTGSJA FORTRAN_ID( ztgsja )

//
// LAPACK driver routines
//

// Value-type variants of gegv
#define LAPACK_SGEGV FORTRAN_ID( sgegv )
#define LAPACK_DGEGV FORTRAN_ID( dgegv )
#define LAPACK_CGEGV FORTRAN_ID( cgegv )
#define LAPACK_ZGEGV FORTRAN_ID( zgegv )

// Value-type variants of gges
#define LAPACK_SGGES FORTRAN_ID( sgges )
#define LAPACK_DGGES FORTRAN_ID( dgges )
#define LAPACK_CGGES FORTRAN_ID( cgges )
#define LAPACK_ZGGES FORTRAN_ID( zgges )

// Value-type variants of ggesx
#define LAPACK_SGGESX FORTRAN_ID( sggesx )
#define LAPACK_DGGESX FORTRAN_ID( dggesx )
#define LAPACK_CGGESX FORTRAN_ID( cggesx )
#define LAPACK_ZGGESX FORTRAN_ID( zggesx )

// Value-type variants of ggev
#define LAPACK_SGGEV FORTRAN_ID( sggev )
#define LAPACK_DGGEV FORTRAN_ID( dggev )
#define LAPACK_CGGEV FORTRAN_ID( cggev )
#define LAPACK_ZGGEV FORTRAN_ID( zggev )

// Value-type variants of ggevx
#define LAPACK_SGGEVX FORTRAN_ID( sggevx )
#define LAPACK_DGGEVX FORTRAN_ID( dggevx )
#define LAPACK_CGGEVX FORTRAN_ID( cggevx )
#define LAPACK_ZGGEVX FORTRAN_ID( zggevx )

// Value-type variants of ggsvd
#define LAPACK_SGGSVD FORTRAN_ID( sggsvd )
#define LAPACK_DGGSVD FORTRAN_ID( dggsvd )
#define LAPACK_CGGSVD FORTRAN_ID( cggsvd )
#define LAPACK_ZGGSVD FORTRAN_ID( zggsvd )

// Value-type variants of hbgv
#define LAPACK_CHBGV FORTRAN_ID( chbgv )
#define LAPACK_ZHBGV FORTRAN_ID( zhbgv )

// Value-type variants of hbgvd
#define LAPACK_CHBGVD FORTRAN_ID( chbgvd )
#define LAPACK_ZHBGVD FORTRAN_ID( zhbgvd )

// Value-type variants of hbgvx
#define LAPACK_CHBGVX FORTRAN_ID( chbgvx )
#define LAPACK_ZHBGVX FORTRAN_ID( zhbgvx )

// Value-type variants of hegv
#define LAPACK_CHEGV FORTRAN_ID( chegv )
#define LAPACK_ZHEGV FORTRAN_ID( zhegv )

// Value-type variants of hegvd
#define LAPACK_CHEGVD FORTRAN_ID( chegvd )
#define LAPACK_ZHEGVD FORTRAN_ID( zhegvd )

// Value-type variants of hegvx
#define LAPACK_CHEGVX FORTRAN_ID( chegvx )
#define LAPACK_ZHEGVX FORTRAN_ID( zhegvx )

// Value-type variants of hpgv
#define LAPACK_CHPGV FORTRAN_ID( chpgv )
#define LAPACK_ZHPGV FORTRAN_ID( zhpgv )

// Value-type variants of hpgvd
#define LAPACK_CHPGVD FORTRAN_ID( chpgvd )
#define LAPACK_ZHPGVD FORTRAN_ID( zhpgvd )

// Value-type variants of hpgvx
#define LAPACK_CHPGVX FORTRAN_ID( chpgvx )
#define LAPACK_ZHPGVX FORTRAN_ID( zhpgvx )

// Value-type variants of lacgv
#define LAPACK_CLACGV FORTRAN_ID( clacgv )
#define LAPACK_ZLACGV FORTRAN_ID( zlacgv )

// Value-type variants of largv
#define LAPACK_SLARGV FORTRAN_ID( slargv )
#define LAPACK_DLARGV FORTRAN_ID( dlargv )
#define LAPACK_CLARGV FORTRAN_ID( clargv )
#define LAPACK_ZLARGV FORTRAN_ID( zlargv )

// Value-type variants of sbgv
#define LAPACK_SSBGV FORTRAN_ID( ssbgv )
#define LAPACK_DSBGV FORTRAN_ID( dsbgv )

// Value-type variants of sbgvd
#define LAPACK_SSBGVD FORTRAN_ID( ssbgvd )
#define LAPACK_DSBGVD FORTRAN_ID( dsbgvd )

// Value-type variants of sbgvx
#define LAPACK_SSBGVX FORTRAN_ID( ssbgvx )
#define LAPACK_DSBGVX FORTRAN_ID( dsbgvx )

// Value-type variants of spgv
#define LAPACK_SSPGV FORTRAN_ID( sspgv )
#define LAPACK_DSPGV FORTRAN_ID( dspgv )

// Value-type variants of spgvd
#define LAPACK_SSPGVD FORTRAN_ID( sspgvd )
#define LAPACK_DSPGVD FORTRAN_ID( dspgvd )

// Value-type variants of spgvx
#define LAPACK_SSPGVX FORTRAN_ID( sspgvx )
#define LAPACK_DSPGVX FORTRAN_ID( dspgvx )

// Value-type variants of sygv
#define LAPACK_SSYGV FORTRAN_ID( ssygv )
#define LAPACK_DSYGV FORTRAN_ID( dsygv )

// Value-type variants of sygvd
#define LAPACK_SSYGVD FORTRAN_ID( ssygvd )
#define LAPACK_DSYGVD FORTRAN_ID( dsygvd )

// Value-type variants of sygvx
#define LAPACK_SSYGVX FORTRAN_ID( ssygvx )
#define LAPACK_DSYGVX FORTRAN_ID( dsygvx )

// Value-type variants of ggglm
#define LAPACK_SGGGLM FORTRAN_ID( sggglm )
#define LAPACK_DGGGLM FORTRAN_ID( dggglm )
#define LAPACK_CGGGLM FORTRAN_ID( cggglm )
#define LAPACK_ZGGGLM FORTRAN_ID( zggglm )

// Value-type variants of gglse
#define LAPACK_SGGLSE FORTRAN_ID( sgglse )
#define LAPACK_DGGLSE FORTRAN_ID( dgglse )
#define LAPACK_CGGLSE FORTRAN_ID( cgglse )
#define LAPACK_ZGGLSE FORTRAN_ID( zgglse )

// Value-type variants of cgesv
#define LAPACK_ZCGESV FORTRAN_ID( zcgesv )

// Value-type variants of gbsv
#define LAPACK_SGBSV FORTRAN_ID( sgbsv )
#define LAPACK_DGBSV FORTRAN_ID( dgbsv )
#define LAPACK_CGBSV FORTRAN_ID( cgbsv )
#define LAPACK_ZGBSV FORTRAN_ID( zgbsv )

// Value-type variants of gbsvx
#define LAPACK_SGBSVX FORTRAN_ID( sgbsvx )
#define LAPACK_DGBSVX FORTRAN_ID( dgbsvx )
#define LAPACK_CGBSVX FORTRAN_ID( cgbsvx )
#define LAPACK_ZGBSVX FORTRAN_ID( zgbsvx )

// Value-type variants of gesv
#define LAPACK_SGESV FORTRAN_ID( sgesv )
#define LAPACK_DGESV FORTRAN_ID( dgesv )
#define LAPACK_CGESV FORTRAN_ID( cgesv )
#define LAPACK_ZGESV FORTRAN_ID( zgesv )

// Value-type variants of gesvx
#define LAPACK_SGESVX FORTRAN_ID( sgesvx )
#define LAPACK_DGESVX FORTRAN_ID( dgesvx )
#define LAPACK_CGESVX FORTRAN_ID( cgesvx )
#define LAPACK_ZGESVX FORTRAN_ID( zgesvx )

// Value-type variants of gtsv
#define LAPACK_SGTSV FORTRAN_ID( sgtsv )
#define LAPACK_DGTSV FORTRAN_ID( dgtsv )
#define LAPACK_CGTSV FORTRAN_ID( cgtsv )
#define LAPACK_ZGTSV FORTRAN_ID( zgtsv )

// Value-type variants of gtsvx
#define LAPACK_SGTSVX FORTRAN_ID( sgtsvx )
#define LAPACK_DGTSVX FORTRAN_ID( dgtsvx )
#define LAPACK_CGTSVX FORTRAN_ID( cgtsvx )
#define LAPACK_ZGTSVX FORTRAN_ID( zgtsvx )

// Value-type variants of hesv
#define LAPACK_CHESV FORTRAN_ID( chesv )
#define LAPACK_ZHESV FORTRAN_ID( zhesv )

// Value-type variants of hesvx
#define LAPACK_CHESVX FORTRAN_ID( chesvx )
#define LAPACK_ZHESVX FORTRAN_ID( zhesvx )

// Value-type variants of hpsv
#define LAPACK_CHPSV FORTRAN_ID( chpsv )
#define LAPACK_ZHPSV FORTRAN_ID( zhpsv )

// Value-type variants of hpsvx
#define LAPACK_CHPSVX FORTRAN_ID( chpsvx )
#define LAPACK_ZHPSVX FORTRAN_ID( zhpsvx )

// Value-type variants of pbsv
#define LAPACK_SPBSV FORTRAN_ID( spbsv )
#define LAPACK_DPBSV FORTRAN_ID( dpbsv )
#define LAPACK_CPBSV FORTRAN_ID( cpbsv )
#define LAPACK_ZPBSV FORTRAN_ID( zpbsv )

// Value-type variants of pbsvx
#define LAPACK_SPBSVX FORTRAN_ID( spbsvx )
#define LAPACK_DPBSVX FORTRAN_ID( dpbsvx )
#define LAPACK_CPBSVX FORTRAN_ID( cpbsvx )
#define LAPACK_ZPBSVX FORTRAN_ID( zpbsvx )

// Value-type variants of posv
#define LAPACK_SPOSV FORTRAN_ID( sposv )
#define LAPACK_DPOSV FORTRAN_ID( dposv )
#define LAPACK_CPOSV FORTRAN_ID( cposv )
#define LAPACK_ZPOSV FORTRAN_ID( zposv )

// Value-type variants of posvx
#define LAPACK_SPOSVX FORTRAN_ID( sposvx )
#define LAPACK_DPOSVX FORTRAN_ID( dposvx )
#define LAPACK_CPOSVX FORTRAN_ID( cposvx )
#define LAPACK_ZPOSVX FORTRAN_ID( zposvx )

// Value-type variants of ppsv
#define LAPACK_SPPSV FORTRAN_ID( sppsv )
#define LAPACK_DPPSV FORTRAN_ID( dppsv )
#define LAPACK_CPPSV FORTRAN_ID( cppsv )
#define LAPACK_ZPPSV FORTRAN_ID( zppsv )

// Value-type variants of ppsvx
#define LAPACK_SPPSVX FORTRAN_ID( sppsvx )
#define LAPACK_DPPSVX FORTRAN_ID( dppsvx )
#define LAPACK_CPPSVX FORTRAN_ID( cppsvx )
#define LAPACK_ZPPSVX FORTRAN_ID( zppsvx )

// Value-type variants of ptsv
#define LAPACK_SPTSV FORTRAN_ID( sptsv )
#define LAPACK_DPTSV FORTRAN_ID( dptsv )
#define LAPACK_CPTSV FORTRAN_ID( cptsv )
#define LAPACK_ZPTSV FORTRAN_ID( zptsv )

// Value-type variants of ptsvx
#define LAPACK_SPTSVX FORTRAN_ID( sptsvx )
#define LAPACK_DPTSVX FORTRAN_ID( dptsvx )
#define LAPACK_CPTSVX FORTRAN_ID( cptsvx )
#define LAPACK_ZPTSVX FORTRAN_ID( zptsvx )

// Value-type variants of sgesv
#define LAPACK_DSGESV FORTRAN_ID( dsgesv )

// Value-type variants of spsv
#define LAPACK_SSPSV FORTRAN_ID( sspsv )
#define LAPACK_DSPSV FORTRAN_ID( dspsv )
#define LAPACK_CSPSV FORTRAN_ID( cspsv )
#define LAPACK_ZSPSV FORTRAN_ID( zspsv )

// Value-type variants of spsvx
#define LAPACK_SSPSVX FORTRAN_ID( sspsvx )
#define LAPACK_DSPSVX FORTRAN_ID( dspsvx )
#define LAPACK_CSPSVX FORTRAN_ID( cspsvx )
#define LAPACK_ZSPSVX FORTRAN_ID( zspsvx )

// Value-type variants of sysv
#define LAPACK_SSYSV FORTRAN_ID( ssysv )
#define LAPACK_DSYSV FORTRAN_ID( dsysv )
#define LAPACK_CSYSV FORTRAN_ID( csysv )
#define LAPACK_ZSYSV FORTRAN_ID( zsysv )

// Value-type variants of sysvx
#define LAPACK_SSYSVX FORTRAN_ID( ssysvx )
#define LAPACK_DSYSVX FORTRAN_ID( dsysvx )
#define LAPACK_CSYSVX FORTRAN_ID( csysvx )
#define LAPACK_ZSYSVX FORTRAN_ID( zsysvx )

// Value-type variants of gees
#define LAPACK_SGEES FORTRAN_ID( sgees )
#define LAPACK_DGEES FORTRAN_ID( dgees )
#define LAPACK_CGEES FORTRAN_ID( cgees )
#define LAPACK_ZGEES FORTRAN_ID( zgees )

// Value-type variants of geesx
#define LAPACK_SGEESX FORTRAN_ID( sgeesx )
#define LAPACK_DGEESX FORTRAN_ID( dgeesx )
#define LAPACK_CGEESX FORTRAN_ID( cgeesx )
#define LAPACK_ZGEESX FORTRAN_ID( zgeesx )

// Value-type variants of geev
#define LAPACK_SGEEV FORTRAN_ID( sgeev )
#define LAPACK_DGEEV FORTRAN_ID( dgeev )
#define LAPACK_CGEEV FORTRAN_ID( cgeev )
#define LAPACK_ZGEEV FORTRAN_ID( zgeev )

// Value-type variants of geevx
#define LAPACK_SGEEVX FORTRAN_ID( sgeevx )
#define LAPACK_DGEEVX FORTRAN_ID( dgeevx )
#define LAPACK_CGEEVX FORTRAN_ID( cgeevx )
#define LAPACK_ZGEEVX FORTRAN_ID( zgeevx )

// Value-type variants of gesdd
#define LAPACK_SGESDD FORTRAN_ID( sgesdd )
#define LAPACK_DGESDD FORTRAN_ID( dgesdd )
#define LAPACK_CGESDD FORTRAN_ID( cgesdd )
#define LAPACK_ZGESDD FORTRAN_ID( zgesdd )

// Value-type variants of gesvd
#define LAPACK_SGESVD FORTRAN_ID( sgesvd )
#define LAPACK_DGESVD FORTRAN_ID( dgesvd )
#define LAPACK_CGESVD FORTRAN_ID( cgesvd )
#define LAPACK_ZGESVD FORTRAN_ID( zgesvd )

// Value-type variants of hbev
#define LAPACK_CHBEV FORTRAN_ID( chbev )
#define LAPACK_ZHBEV FORTRAN_ID( zhbev )

// Value-type variants of hbevd
#define LAPACK_CHBEVD FORTRAN_ID( chbevd )
#define LAPACK_ZHBEVD FORTRAN_ID( zhbevd )

// Value-type variants of hbevx
#define LAPACK_CHBEVX FORTRAN_ID( chbevx )
#define LAPACK_ZHBEVX FORTRAN_ID( zhbevx )

// Value-type variants of heev
#define LAPACK_CHEEV FORTRAN_ID( cheev )
#define LAPACK_ZHEEV FORTRAN_ID( zheev )

// Value-type variants of heevd
#define LAPACK_CHEEVD FORTRAN_ID( cheevd )
#define LAPACK_ZHEEVD FORTRAN_ID( zheevd )

// Value-type variants of heevr
#define LAPACK_CHEEVR FORTRAN_ID( cheevr )
#define LAPACK_ZHEEVR FORTRAN_ID( zheevr )

// Value-type variants of heevx
#define LAPACK_CHEEVX FORTRAN_ID( cheevx )
#define LAPACK_ZHEEVX FORTRAN_ID( zheevx )

// Value-type variants of hpev
#define LAPACK_CHPEV FORTRAN_ID( chpev )
#define LAPACK_ZHPEV FORTRAN_ID( zhpev )

// Value-type variants of hpevd
#define LAPACK_CHPEVD FORTRAN_ID( chpevd )
#define LAPACK_ZHPEVD FORTRAN_ID( zhpevd )

// Value-type variants of hpevx
#define LAPACK_CHPEVX FORTRAN_ID( chpevx )
#define LAPACK_ZHPEVX FORTRAN_ID( zhpevx )

// Value-type variants of sbev
#define LAPACK_SSBEV FORTRAN_ID( ssbev )
#define LAPACK_DSBEV FORTRAN_ID( dsbev )

// Value-type variants of sbevd
#define LAPACK_SSBEVD FORTRAN_ID( ssbevd )
#define LAPACK_DSBEVD FORTRAN_ID( dsbevd )

// Value-type variants of sbevx
#define LAPACK_SSBEVX FORTRAN_ID( ssbevx )
#define LAPACK_DSBEVX FORTRAN_ID( dsbevx )

// Value-type variants of spev
#define LAPACK_SSPEV FORTRAN_ID( sspev )
#define LAPACK_DSPEV FORTRAN_ID( dspev )

// Value-type variants of spevd
#define LAPACK_SSPEVD FORTRAN_ID( sspevd )
#define LAPACK_DSPEVD FORTRAN_ID( dspevd )

// Value-type variants of spevx
#define LAPACK_SSPEVX FORTRAN_ID( sspevx )
#define LAPACK_DSPEVX FORTRAN_ID( dspevx )

// Value-type variants of stev
#define LAPACK_SSTEV FORTRAN_ID( sstev )
#define LAPACK_DSTEV FORTRAN_ID( dstev )

// Value-type variants of stevd
#define LAPACK_SSTEVD FORTRAN_ID( sstevd )
#define LAPACK_DSTEVD FORTRAN_ID( dstevd )

// Value-type variants of stevr
#define LAPACK_SSTEVR FORTRAN_ID( sstevr )
#define LAPACK_DSTEVR FORTRAN_ID( dstevr )

// Value-type variants of stevx
#define LAPACK_SSTEVX FORTRAN_ID( sstevx )
#define LAPACK_DSTEVX FORTRAN_ID( dstevx )

// Value-type variants of syev
#define LAPACK_SSYEV FORTRAN_ID( ssyev )
#define LAPACK_DSYEV FORTRAN_ID( dsyev )

// Value-type variants of syevd
#define LAPACK_SSYEVD FORTRAN_ID( ssyevd )
#define LAPACK_DSYEVD FORTRAN_ID( dsyevd )

// Value-type variants of syevr
#define LAPACK_SSYEVR FORTRAN_ID( ssyevr )
#define LAPACK_DSYEVR FORTRAN_ID( dsyevr )

// Value-type variants of syevx
#define LAPACK_SSYEVX FORTRAN_ID( ssyevx )
#define LAPACK_DSYEVX FORTRAN_ID( dsyevx )

// Value-type variants of gels
#define LAPACK_SGELS FORTRAN_ID( sgels )
#define LAPACK_DGELS FORTRAN_ID( dgels )
#define LAPACK_CGELS FORTRAN_ID( cgels )
#define LAPACK_ZGELS FORTRAN_ID( zgels )

// Value-type variants of gelsd
#define LAPACK_SGELSD FORTRAN_ID( sgelsd )
#define LAPACK_DGELSD FORTRAN_ID( dgelsd )
#define LAPACK_CGELSD FORTRAN_ID( cgelsd )
#define LAPACK_ZGELSD FORTRAN_ID( zgelsd )

// Value-type variants of gelss
#define LAPACK_SGELSS FORTRAN_ID( sgelss )
#define LAPACK_DGELSS FORTRAN_ID( dgelss )
#define LAPACK_CGELSS FORTRAN_ID( cgelss )
#define LAPACK_ZGELSS FORTRAN_ID( zgelss )

// Value-type variants of gelsy
#define LAPACK_SGELSY FORTRAN_ID( sgelsy )
#define LAPACK_DGELSY FORTRAN_ID( dgelsy )
#define LAPACK_CGELSY FORTRAN_ID( cgelsy )
#define LAPACK_ZGELSY FORTRAN_ID( zgelsy )

// Value-type variants of lalsd
#define LAPACK_SLALSD FORTRAN_ID( slalsd )
#define LAPACK_DLALSD FORTRAN_ID( dlalsd )
#define LAPACK_CLALSD FORTRAN_ID( clalsd )
#define LAPACK_ZLALSD FORTRAN_ID( zlalsd )

#endif

