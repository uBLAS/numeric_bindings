#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2009 Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import netlib

import re, os.path, copy
from types import StringType

# for debugging purposes
import pprint

def parse_file( filename, info_map, template_map ):

    pp = pprint.PrettyPrinter( indent = 2 )
    source = open( filename ).read() 

    for match in re.compile( '(void|float|double) +cblas_([^\(]+)\(([^\)]+)\)', re.M | re.S ).findall( source ):
        print "----"
        return_type  = match[0]
        blas_routine = match[1].split("_sub")[0].upper().strip()
        print "CBLAS routine:", match[1] , "   BLAS equivalent:", blas_routine
        arguments = {}
        for arg in match[2].replace('\n','').split( ',' ):
            arg = arg.strip()
            arg_name = arg.split( " " )[-1].replace( "*", "" ).strip().upper()
            arguments[ arg_name ] = {}
            arguments[ arg_name ][ "original" ] = arg
            arguments[ arg_name ][ "pointer" ] = "*" in arg

        pp.pprint( arguments )

        if blas_routine in info_map:
            print "Found ", blas_routine, " in Fortran info_map."
            info_map[ blas_routine ][ "cblas_routine" ] = 'cblas_' + match[1]

            # read aliases, if they are there
            my_key = blas_routine[ 1: ].lower() + '.all.cblas_alias'
            alias_map = {}
            #print my_key
            if netlib.my_has_key( my_key, template_map ) != None:
                #print "Has key.."
                for line in template_map[ netlib.my_has_key( my_key, template_map ) ].splitlines():
                    #print "Line:", line
                    alias_map[ line.split( "," )[0] ] = line.split(",")[1]

            #print alias_map

            # Try to match and insert arguments
            # argument_map is the data gathered through the Fortran interface
            for arg in info_map[ blas_routine ][ 'argument_map' ]:
                cblas_arg = ''
                if arg in arguments:
                    cblas_arg = arg
                elif arg in alias_map:
                    if alias_map[ arg ] in arguments:
                        cblas_arg = alias_map[ arg ]

                print "Looking for BLAS argument ", arg, " CBLAS equivalent: ", cblas_arg
                if cblas_arg in arguments:
                    print "Found matching argument, inserting call_cblas_header stuff"
                    call_cblas_header = info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_blas_header" ]
                    print "Original: ", call_cblas_header
                    if not arguments[ cblas_arg ][ "pointer" ]:
                        call_cblas_header = call_cblas_header.replace( "&", "" )

                    call_cblas_header = call_cblas_header.replace( "complex_ptr", "void_ptr" );

                    print "Result:   ", call_cblas_header
                    if arg == 'UPLO':
                        info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_cblas_header" ] = \
                            "cblas_option< UpLo >::value"
                    elif arg == 'DIAG':
                        info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_cblas_header" ] = \
                            "cblas_option< Diag >::value"
                    elif arg == 'SIDE':
                        info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_cblas_header" ] = \
                            "cblas_option< Side >::value"
                    elif  arg == 'TRANS' or arg == 'TRANSA' or arg == 'TRANSB':
                        info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_cblas_header" ] = \
                          "cblas_option< " + netlib.level0_types[ arg ] + " >::value"
                    else:
                        info_map[ blas_routine ][ "argument_map" ][ arg ][ "code" ][ "call_cblas_header" ] = call_cblas_header
                else:
                    exit(0)

            if "ORDER" in arguments:
                info_map[ blas_routine ][ "has_cblas_order_arg" ] = True
            else:
                info_map[ blas_routine ][ "has_cblas_order_arg" ] = False


