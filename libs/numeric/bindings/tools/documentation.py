#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2008 Thomas Klimpel and Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import bindings
import os, re

routine_value_type = \
    { 'C' : 'complex<float>',
      'Z' : 'complex<double>', 
      'D' : 'double',
      'S' : 'float' }

subroutine_value_type = \
    { 'complex,single' : 'complex<float>',
      'complex,double' : 'complex<double>', 
      'real,single' : 'float',
      'real,double' : 'double',
      'complex+real,single' : 'combined float and complex<float>',
      'complex+real,double' : 'combined double and complex<double>'
    }

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
      'R2' : ' rank-2 update',
      'RK' : ' rank-k update',
      'R2K' : ' rank-2k update',
      'SV'  : ' solve system of equations'
    }

number_to_text = \
    { 1 :    'one',
      2 :    'two',
      3 :    'three',
      4 :    'four',
      5 :    'five',
      6 :    'six',
      7 :    'seven',
      8 :    'eight',
      9 :    'nine',
      10:    'ten',
      11:    'eleven',
      12:    'twelve',
      13:    'thirteen',
      14:    'fourteen',
      15:    'fifteen',
      16:    'sixteen',
      17:    'seventeen',
      18:    'eighteen',
      19:    'nineteen',
      20:    'twenty',
      21:    'twenty-one',
      22:    'twenty-two',
      23:    'twenty-three',
      24:    'twenty-four',
      25:    'twenty-five',
      26:    'twenty-six',
      27:    'twenty-seven',
      28:    'twenty-eight',
      29:    'twenty-nine',
      30:    'thirty',
    }

def readable_join( some_tuple, last_word = "and" ):

    if len( some_tuple ) == 1:
        return some_tuple[0]
    if len( some_tuple ) == 2:
        return some_tuple[0] + " " + last_word + " " + some_tuple[1]
    return ", ".join( some_tuple[:-1] ) + ", " + last_word + " " + some_tuple[-1]


def write_blas_dispatch_table( subroutines, info_map ):
    result = ""
    result += "[  [ Value type of $FIRST_TYPENAME ] [BLAS routine] [CBLAS routine] [CUBLAS routine] ]\n"
    for subroutine in subroutines:
        cblas_routine = ''
        if 'cblas_routine' in info_map[ subroutine ]:
            cblas_routine = info_map[ subroutine ][ 'cblas_routine' ]
        else:
            cblas_routine = 'Unavailable'
        cublas_routine = ''
        if 'cublas_routine' in info_map[ subroutine ]:
            cublas_routine = info_map[ subroutine ][ 'cublas_routine' ]
        else:
            cublas_routine = 'Unavailable'

        result += "[  "
        result += "[`" + subroutine_value_type[ ",".join( [
                info_map[ subroutine ][ 'value_type' ],
                info_map[ subroutine ][ 'precision' ] ] ) ] + "`]"
        result += "[" + subroutine + "]"
        result += "[" + cblas_routine + "]"
        result += "[" + cublas_routine + "]"

        result += " ]\n"
    return result


def write_lapack_dispatch_table( subroutines, info_map ):
    result = ""
    result += "[  [ Value type of $FIRST_TYPENAME ] [LAPACK routine] ]\n"
    for subroutine in subroutines:
        result += "[  "
        result += "[`" + routine_value_type[ subroutine[0] ] + "`]"
        result += "[" + subroutine + "]"
        result += " ]\n"
    return result



def blas_friendly_name( group_name, info_map, template_map ):

    possible_key = group_name.lower() + ".friendly_name"
    if possible_key in template_map:
        return template_map[ possible_key ].strip()

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



def combine_purposes( subroutines, info_map ):

    purposes = []

    for subroutine in subroutines:

        purpose = info_map[ subroutine ][ 'purpose' ]
        purpose = purpose.replace( subroutine, "`$groupname`" )
        purpose = purpose.replace( '  ', ' ' )
        purpose = purpose.replace( '  ', ' ' )
        purpose = purpose.replace( '  ', ' ' )

        #purpose = purpose.replace( ",   or", ", or\n  " )
        #purpose = purpose.replace( "   or   ", ", or\n  " )

        # strip spaces from the purpose
        result = []
        for line in purpose.splitlines():
            result.append( line.strip() )
        purpose = "\n".join( result )

        # only add if there's something new
        if purpose not in purposes:
            purposes.append( purpose )


    if len(purposes)>1:
        print "UNMERGED: ", subroutines

    return purposes[-1]





#
# Write the many (low-level) documentation files
#
def write_documentation( info_map, group, template_map, base_dir ):

    parsermode = template_map[ 'PARSERMODE' ].lower()

    for group_name, subroutines in group.iteritems():
        filename = group_name.lower() + '.qbk'

        result = template_map[ parsermode + '.qbk' ]

        prototypes = []
        first_typename = None
        originating_sources = []
        no_arguments_level0 = []
        no_arguments_level2 = []

        for subroutine in subroutines:
            if parsermode == 'blas':
                originating_sources.append( "[@http://www.netlib.org/blas/" +
                    subroutine.lower() + ".f " + subroutine.lower() + ".f]" )
            if parsermode == 'lapack':
                originating_sources.append( "[@http://www.netlib.org/lapack/explore-html/" +
                    subroutine.lower() + ".f.html " + subroutine.lower() + ".f]" )

            level2_arg_list_pre = []
            for arg in info_map[ subroutine ][ 'arguments' ]:
                if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] != None:
                    level2_arg_list_pre += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] ]

            # Keep track of the numbers of arguments
            if len( info_map[ subroutine ][ 'arguments' ] ) not in no_arguments_level0:
                no_arguments_level0.append( len( info_map[ subroutine ][ 'arguments' ] ) )

            if len( level2_arg_list_pre ) not in no_arguments_level2:
                no_arguments_level2.append( len( level2_arg_list_pre ) )

            level2_arg_list = []
            for arg in level2_arg_list_pre:
                readable_arg = ''
                if '::real_type' in arg:
                    splitted = arg.split( "::real_type" )
                    readable_arg = "Scalar" + splitted[1]
                    if 'const' in arg:
                        readable_arg = 'const ' + readable_arg
                elif '::type' in arg:
                    splitted = arg.split( "::type" )
                    readable_arg = "Scalar" + splitted[1]
                    if 'const' in arg:
                        readable_arg = 'const ' + readable_arg
                else:
                    readable_arg = arg

                if (first_typename == None ) and ('Vector' in arg or 'Matrix' in arg):
                    first_typename = arg.replace( "const ", "" ).replace( "&", "" ).split(" ")[0]

                level2_arg_list.append( readable_arg )


            prototype = template_map[ parsermode + '_prototype.qbk' ]
            prototype = prototype.replace( "$LEVEL2", ", ".join( level2_arg_list ) )

            if prototype not in prototypes:
                prototypes.append( prototype )

        prototype_overloads = ''
        if len(prototypes) == 1:
            prototype_overloads = 'is one prototype of'
        else:
            prototype_overloads = 'are ' + number_to_text[ len(prototypes) ] + ' prototypes of'

        prototypes = bindings.proper_indent( "\n".join( prototypes ) )

        #prototypes.append( prototype )
        result = result.replace( "$PROTOTYPES", prototypes )
        result = result.replace( "$PROTOTYPE_OVERLOADS", prototype_overloads )
        result = result.replace( "$ORIGINATING_SOURCES", readable_join( originating_sources ) )
        result = result.replace( '$PURPOSE', combine_purposes( subroutines, info_map ) )

        result = result.replace( '$SUBROUTINES', readable_join( subroutines ) )
        result = result.replace( '$header', 'boost/numeric/bindings/' + parsermode + '/' + group_name.lower() + '.hpp' )


        if len( no_arguments_level0 ) == 1:
            result = result.replace( '$NO_ARGUMENTS_LEVEL0', number_to_text[ no_arguments_level0[0] ] )
        else:
            result = result.replace( '$NO_ARGUMENTS_LEVEL0', "TODO" )

        if len( no_arguments_level2 ) == 1:
            result = result.replace( '$NO_ARGUMENTS_LEVEL2', number_to_text[ no_arguments_level2[0] ] )
        else:
            result = result.replace( '$NO_ARGUMENTS_LEVEL2', "TODO" )

        if parsermode == 'blas':
            result = result.replace( '$DISPATCH_TABLE', write_blas_dispatch_table( subroutines, info_map ) )
            result = result.replace( '$FRIENDLY_NAME', blas_friendly_name( group_name, info_map, template_map ) )
        if parsermode == 'lapack':
            result = result.replace( '$DISPATCH_TABLE', write_lapack_dispatch_table( subroutines, info_map ) )
            #result = result.replace( '$FRIENDLY_NAME', lapack_friendly_name( group_name, info_map, template_map ) )

        if first_typename != None:
            result = result.replace( "$FIRST_TYPENAME", first_typename )
        result = result.replace( '$GROUPNAME', group_name )
        result = result.replace( '$groupname', group_name.lower() )
        print "Writing " + base_dir + "/" + filename
        open( os.path.join( base_dir, filename ), 'w' ).write( result )


















