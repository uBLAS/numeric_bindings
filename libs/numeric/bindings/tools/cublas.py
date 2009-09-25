#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2009 Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import re, os.path, copy
from types import StringType

# for debugging purposes
import pprint

def parse_file( filename, info_map, template_map ):
    pp = pprint.PrettyPrinter( indent = 2 )
    source = open( filename ).read() 

    for match in re.compile( '(float|double|void) ?CUBLASAPI ?cublas([SDCZ][a-z0-9]+) ?\(([^\(]+)\(([^\)]+)\)', re.M | re.S ).findall( source ):
        blas_routine = match[1].upper()

        if blas_routine in info_map:
            print "FOUND!"
            info_map[ blas_routine ][ "cublas_routine" ] = 'cublas' + match[1]
            pp.pprint( info_map[ blas_routine ] )
       
        #print blas_routine
        #print match[0], match[1]

        #print match

        




    #print info_map.keys


    #print source














#parse_file( "./cublas.h", dict() )



















