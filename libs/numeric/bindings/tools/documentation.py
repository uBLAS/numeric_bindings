#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2008 Thomas Klimpel and Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import re

routine_value_type = \
    { 'C' : 'complex<float>',
      'Z' : 'complex<double>', 
      'D' : 'double',
      'S' : 'float' }

matrix_structure = \
    { 'G' : 'generic',
      'H' : 'hermitian',
      'S' : 'symmetric',
      'T' : 'triangular' }

matrix_layout = \
    { 'B' : ', banded, ',
      'E' : '',
      'P' : ', packed, ',
      'Y' : '',
      'R' : '' }

blas_op = \
    { 'MV' : ' matrix-vector operation',
      'MM' : ' matrix-matrix operation',
      'R' :  ' rank-1 update',
      'R2' : ' rank-2 update'
    }

def readable_join( some_tuple, last_word = "and" ):

    if len( some_tuple ) == 1:
        return some_tuple[0]
    if len( some_tuple ) == 2:
        return some_tuple[0] + " " + last_word + " " + some_tuple[1]
    return ", ".join( some_tuple[:-1] ) + ", " + last_word + " " + some_tuple[-1]


def write_dispatch_table( subroutines, info_map ):
    result = ""
    result += "[  [ Value type ] [BLAS routine] [CBLAS routine] [CUBLAS routine] ]\n"
    for subroutine in subroutines:
        cblas_routine = ''
        if 'cblas_routine' in info_map[ subroutine ]:
            cblas_routine = info_map[ subroutine ][ 'cblas_routine' ]
        else:
            cblas_routine = 'Not available'
        cublas_routine = ''
        if 'cublas_routine' in info_map[ subroutine ]:
            cublas_routine = info_map[ subroutine ][ 'cublas_routine' ]
        else:
            cublas_routine = 'Not available'

        result += "[  "
        result += "[`" + routine_value_type[ subroutine[0] ] + "`]"
        result += "[" + subroutine + "]"
        result += "[" + cblas_routine + "]"
        result += "[" + cublas_routine + "]"

        result += " ]\n"
    return result




def blas_friendly_name( group_name, info_map, template_map ):

    possible_key = group_name.lower() + ".friendly_name"
    if possible_key in template_map:
        return template_map[ possible_key ]

    result = ""

    if group_name[0] in matrix_structure and \
       group_name[1] in matrix_layout and \
       group_name[2:] in blas_op:
        result += matrix_structure[ group_name[0] ]
        result += matrix_layout[ group_name[1] ]
        result += blas_op[ group_name[2:] ]
    else:
        result += "TODO"

    return result

