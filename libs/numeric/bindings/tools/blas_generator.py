#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2008 Thomas Klimpel and Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import netlib, bindings, cblas, cublas, documentation

import re, os.path, copy
from types import StringType

# for debugging purposes
import pprint


#
# Group subroutines on their name, with the first character removed. This will 
# group them in the same .hpp file as well. Sort these subroutines based on 
# routine_cmp above.
#
def group_by_value_type( global_info_map ):
  group_map = {}
  for i in global_info_map.keys():
    short_name = i[ 1: ]
    if not group_map.has_key( short_name ):
      group_map[ short_name ] = []
    group_map[ short_name ] += [ i ]
  for value in group_map.values():
    value.sort( bindings.routine_cmp )
  return group_map
  



 
#
# Write the (many) routine file(s).
#
def write_functions( info_map, group, template_map, base_dir ):
  #
  # group.keys() is a vector of different grouped function names
  # like gees, dgesv, etc.
  #
  for group_name, subroutines in group.iteritems():

    filename = group_name.lower() + '.hpp'
    includes = [
      #'#include <boost/numeric/bindings/detail/void_ptr.hpp>',
      #'#include <boost/numeric/bindings/traits/traits.hpp>',
      #'#include <boost/numeric/bindings/traits/type_traits.hpp>', 
      '#include <boost/numeric/bindings/remove_imaginary.hpp>', 
      '#include <boost/numeric/bindings/is_mutable.hpp>', 
      '#include <boost/numeric/bindings/value.hpp>', 
      '#include <boost/numeric/bindings/stride.hpp>',
      '#include <boost/numeric/bindings/size.hpp>',
      #'#include <boost/mpl/bool.hpp>',
      '#include <boost/type_traits/is_same.hpp>',
      '#include <boost/type_traits/remove_const.hpp>',
      '#include <boost/static_assert.hpp>',
      '#include <boost/assert.hpp>',
    ]
      
    if template_map.has_key( group_name.lower() + '.includes' ):
      includes += template_map[ group_name.lower() + '.includes' ].splitlines()

    #
    # LEVEL 0 HANDLING
    #
    overloads = template_map[ 'backend_blas_overloads' ]
    for select_backend in [ 'blas_overloads', 'cblas_overloads', 'cublas_overloads' ]:
      sub_overloads = ''
      for subroutine in subroutines:
        sub_template = template_map[ select_backend ]
        # add the argument list here
        arg_list = []
        typename_list = []
        blas_arg_list = []
        cblas_arg_list = []
        cublas_arg_list = []
        level0_static_asserts = []

        for arg in info_map[ subroutine ][ 'arguments' ]:
            print "Subroutine ", subroutine, " arg ", arg
            arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0' ] ]
            blas_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_blas_header' ] ]
            cblas_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_cblas_header' ] ]

            if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0_typename' ] != None:
                typename_list +=  [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0_typename' ] ]

        if "has_cblas_order_arg" in info_map[ subroutine ]:
            if info_map[ subroutine ][ "has_cblas_order_arg" ] == True:
                arg_list.insert( 0, "Order" )
                cblas_arg_list.insert( 0, "cblas_option< Order >::value" )
                typename_list.insert( 0, "typename Order" )
                level0_static_asserts.append( "BOOST_STATIC_ASSERT( (is_column_major<Order>::value) );" )
                includes += [ "#include <boost/numeric/bindings/is_column_major.hpp>" ]

        sub_template = sub_template.replace( "$TYPES", ", ".join( typename_list ) )
        sub_template = sub_template.replace( "template<  >\n", "" )
        sub_template = sub_template.replace( "$LEVEL0", ", ".join( arg_list ) )
        sub_template = sub_template.replace( "$CALL_BLAS_HEADER", ", ".join( blas_arg_list ) )
        sub_template = sub_template.replace( "$CALL_CBLAS_HEADER", ", ".join( cblas_arg_list ) )
        sub_template = sub_template.replace( "$SUBROUTINE", subroutine )
        sub_template = sub_template.replace( "$SPECIALIZATION", documentation.routine_value_type[ subroutine[0] ] )
        sub_template = sub_template.replace( '$STATIC_ASSERTS', "\n    ".join( level0_static_asserts ) )

        # CBLAS stuff
        if 'cblas_routine' in info_map[ subroutine ]:
            cblas_routine = info_map[ subroutine ][ 'cblas_routine' ]
        else:
            cblas_routine = '// NOT FOUND'
        sub_template = sub_template.replace( "$CBLAS_ROUTINE", cblas_routine )

        # CUBLAS stuff
        if 'cublas_routine' in info_map[ subroutine ]:
            cublas_routine = info_map[ subroutine ][ 'cublas_routine' ]
            for arg in info_map[ subroutine ][ 'arguments' ]:
                cublas_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_cublas_header' ] ]
        else:
            cublas_routine = '// NOT FOUND'

        sub_template = sub_template.replace( "$CALL_CUBLAS_HEADER", ", ".join( cublas_arg_list ) )
        sub_template = sub_template.replace( "$CUBLAS_ROUTINE", cublas_routine )

        sub_template = sub_template.replace( '$groupname', group_name.lower() )
        sub_template = sub_template.replace( '$RETURN_TYPE', info_map[ subroutine ][ 'return_value_type' ] )
        sub_template = sub_template.replace( '$RETURN_STATEMENT', info_map[ subroutine ][ 'return_statement' ] )

        sub_overloads += bindings.proper_indent( sub_template )

      overloads = overloads.replace( '$' + select_backend.upper(),
            sub_overloads )

    #
    # Prepare for levels 1 and 2
    #
    cases = {}
    # first, see what kind of functions we have
    # needed for argument check etc.
    for subroutine in subroutines:
      if subroutine[0] == 'S' or subroutine[0] == 'D':
        if not cases.has_key( 'real' ):
          cases[ 'real' ] = {}
          cases[ 'real' ][ 'subroutines' ] = []
        cases[ 'real' ][ 'subroutines' ] += [ subroutine ]
      if subroutine[0] == 'C' or subroutine[0] == 'Z':
        if not cases.has_key( 'complex' ):
          cases[ 'complex' ] = {}
          cases[ 'complex' ][ 'subroutines' ] = []
        cases[ 'complex' ][ 'subroutines' ] += [ subroutine ]


    #
    # LEVEL 1 and 2 HANDLING
    #
    level1_map = {}
    level2_map = {}
    for value_type, case_map in cases.iteritems():
      level1_template = ''
      level2_template = ''
      level1_template = template_map[ 'blas_level1' ]
      level2_template = template_map[ 'blas_level2' ]

      # include templates come before anything else; they can hold any
      # $ID
      my_include_key = group_name.lower() + '.' + value_type + '.include_templates'
      if netlib.my_has_key( my_include_key, template_map ):
        include_template_list = template_map[ netlib.my_has_key( my_include_key, template_map ) ].strip().replace(' ','').split(",")
        include_templates = ''
        for template in include_template_list:
          include_templates += template_map[ 'template_' + template ]
        level1_template = level1_template.replace( '$INCLUDE_TEMPLATES', bindings.proper_indent(include_templates) )
        level2_template = level2_template.replace( '$INCLUDE_TEMPLATES', bindings.proper_indent(include_templates) )
      else:
        level1_template = level1_template.replace( '\n$INCLUDE_TEMPLATES', '' )
        level2_template = level2_template.replace( '\n$INCLUDE_TEMPLATES', '' )

      level0_arg_list = []
      level1_arg_list = []
      level2_arg_list = []
      call_level1_arg_list = []
      level1_type_arg_list = []
      level1_assert_list = []
      level1_static_assert_list = []
      keyword_type_list = []
      typedef_list = []

      #
      # Are we dealing with a transpose option here?
      # Because CBLAS allows to pass the order of the matrices, here we
      # inject code that determines the default data order.
      #
      if 'matrix' in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_type' ]:
        has_trans = False
        matrix_wo_trans = []
        matrix_with_trans = []
        for matrix_arg in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_type' ][ 'matrix' ]:
            if 'ref_trans' in info_map[ subroutine ][ 'argument_map' ][ matrix_arg ]:
                has_trans = True
                matrix_type = info_map[ subroutine ][ 'argument_map' ][ matrix_arg ][ 'code' ][ 'level_1_static_assert' ]
                matrix_with_trans += [ matrix_type ]
            else:
                matrix_wo_trans.append( info_map[ subroutine ][ 'argument_map' ][ matrix_arg ][ 'code' ][ 'level_1_static_assert' ] )

        #
        # Matrices have trans options in this case. If there is one without,
        # that one will determine the order of the call
        #
        if has_trans:
          includes += [ '#include <boost/numeric/bindings/trans_tag.hpp>' ]
          if len( matrix_wo_trans )>0:
            typedef_list.insert( 0, 'typedef typename result_of::data_order< ' + matrix_wo_trans[0] + \
                ' >::type order;' )
            includes += [ '#include <boost/numeric/bindings/data_order.hpp>' ]
          else:
            typedef_list.insert( 0, 'typedef typename detail::default_order< ' + matrix_with_trans[0] + \
                ' >::type order;' )
            includes += [ '#include <boost/numeric/bindings/blas/detail/default_order.hpp>' ]
        else:
            # so, there's no trans option
            # but, what if there's an order? (e.g., syr) -- then use `
            if "has_cblas_order_arg" in info_map[ subroutine ]:
              typedef_list.insert( 0, 'typedef typename result_of::data_order< ' + matrix_wo_trans[0] + \
                ' >::type order;' )
              includes += [ '#include <boost/numeric/bindings/data_order.hpp>' ]

      #
      # Add an include in case of the uplo or diag options
      #
      if 'UPLO' in info_map[ subroutine ][ 'arguments' ]:
        includes += [ '#include <boost/numeric/bindings/data_side.hpp>' ]
      if 'DIAG' in info_map[ subroutine ][ 'arguments' ]:
        includes += [ '#include <boost/numeric/bindings/diag_tag.hpp>' ]

      #
      # Create static assertions, first by value type
      #
      has_comment = False
      for value_type_tmp_key in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_value_type' ].keys():
        # look up whether they are template params
        static_asserts = []
        for arg in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_value_type' ][ value_type_tmp_key ]:
          if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None:
            static_asserts.append( arg )
        if len(static_asserts)>1:
          arg_A = static_asserts[0]
          for arg_B in static_asserts[1:]:
            print "Adding static assert for argA", arg_A, " argb", arg_B
            assert_line = 'BOOST_STATIC_ASSERT( (is_same< ' + \
                'typename remove_const< typename value< ' + info_map[ subroutine ][ 'argument_map' ][ arg_A ][ 'code' ][ 'level_1_static_assert' ] + ' >::type >::type, ' + \
                'typename remove_const< typename value< ' + info_map[ subroutine ][ 'argument_map' ][ arg_B ][ 'code' ][ 'level_1_static_assert' ] + ' >::type >::type' \
                ' >::value) );'
            if not has_comment:
                #level1_static_assert_list += [ '// Here, we assert... ' ]
                has_comment = True
            level1_static_assert_list += [ assert_line ]

      # Make sure the mutable stuff is mutable
      if 'output' in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ]:
        for arg in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'output' ]:
          if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None:
            assert_line = 'BOOST_STATIC_ASSERT( (is_mutable< ' + \
                info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_static_assert' ] + ' >::value ) );'
            level1_static_assert_list += [ assert_line ]

      # import the code by argument
      for arg in info_map[ subroutine ][ 'arguments' ]:
        level0_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_0' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1' ] != None:
          level1_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_1' ] != None:
          call_level1_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_1' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None and \
          info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] not in level1_type_arg_list:
          level1_type_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_assert' ] != None:
          level1_assert_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_assert' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'typedef' ] != None:
          typedef_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'typedef' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] != None:
          level2_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] ]

      # Insert the order_type() if appropriate
      if info_map[ subroutine ][ "has_cblas_order_arg" ]:
          level0_arg_list.insert( 0, "order()" )

      # Level 1 replacements
      level1_template = level1_template.replace( "$TYPEDEFS", "\n        ".join( typedef_list ) )
      level1_template = level1_template.replace( "$CALL_LEVEL0", ", ".join( level0_arg_list ) )
      level1_template = level1_template.replace( "$CALL_LEVEL1", ", ".join( call_level1_arg_list ) )
      level1_template = level1_template.replace( "$LEVEL1", ", ".join( level1_arg_list ) )
      level1_template = level1_template.replace( "$TYPES", ", ".join( level1_type_arg_list ) )
      level1_template = level1_template.replace( "$ASSERTS", "\n        ".join( level1_assert_list ) )
      level1_template = level1_template.replace( '$RETURN_TYPE', info_map[ subroutine ][ 'level1_return_type' ] )
      level1_template = level1_template.replace( '$RETURN_STATEMENT', info_map[ subroutine ][ 'return_statement' ] )
      level1_template = level1_template.replace( "$KEYWORDS", ", ".join( keyword_type_list ) )

      if len( level1_static_assert_list ) > 0:
        level1_template = level1_template.replace( "$STATIC_ASSERTS", "\n        ".join( level1_static_assert_list ) )
      else:
        level1_template = level1_template.replace( "\n        $STATIC_ASSERTS", "" )

      # Level 2 replacements
      # some special stuff is done here, such as replacing real_type with a 
      # type-traits deduction, etc..
      # more important: all non-const and const variants of functions are written here
      level2_functions = []
      level2_arg_lists, level2_comments = bindings.generate_const_variants( level2_arg_list )
      for level2_idx in range( 0, len( level2_arg_lists ) ):
        level2_function = level2_template.replace( "$LEVEL2", \
                ", ".join( level2_arg_lists[ level2_idx ] ) )
        if len( "".join(level2_comments[ level2_idx ] ) ) > 0:
          level2_function = level2_function.replace( "$COMMENTS", \
                "\n".join( level2_comments[ level2_idx ] ) )
        level2_functions.append( level2_function )

      level2_template = "\n".join( level2_functions )
      level2_template = level2_template.replace( "$COMMENTS\n", "" )

      #level2_template = level2_template.replace( "$LEVEL2", ", ".join( level2_arg_list ) )

      if len(level1_type_arg_list)>0:
        first_typename = level1_type_arg_list[0].split(" ")[-1]
        first_typename_datatype = first_typename[0:6].lower() # 'matrix' or 'vector'
      else:
        level1_type_arg_list.insert( 0, 'typename Value' )
        first_typename = 'Value'
        first_typename_datatype = 'typename Value'


      level2_template = level2_template.replace( "$FIRST_TYPENAME", first_typename )
      level2_template = level2_template.replace( "$TYPEOF_FIRST_TYPENAME", first_typename_datatype )
      level2_template = level2_template.replace( "$CALL_LEVEL1", ", ".join( call_level1_arg_list ) )
      level2_template = level2_template.replace( "$TYPES", ", ".join( level1_type_arg_list ) )
      level2_template = level2_template.replace( '$RETURN_STATEMENT', info_map[ subroutine ][ 'return_statement' ] )
      level2_template = level2_template.replace( '    $STATIC_ASSERTS\n', '' )

      if first_typename == 'Value':
          level2_template = level2_template.replace( 'typename value< Value >::type', 'Value' )
          level2_template = level2_template.replace( 'typename remove_imaginary< Value >::type', 'Value' )

      level1_map[ value_type ] = bindings.proper_indent( level1_template )
      level2_map[ value_type ] = bindings.proper_indent( level2_template )


    #
    # LEVEL 1 and 2 FINALIZATION
    #
    for mapping in [ level1_map, level2_map ]:
      if len(mapping) > 1:
        # compare real and complex cases
        all_keys = mapping.keys()
        if mapping[ all_keys[0] ] == mapping[ all_keys[1] ]:
          print "literally everything is the same!!, falling back to 1 case"
          del mapping[ all_keys[ 1 ] ]

    level1 = ''
    for value_type in level1_map.keys():
      level1 += level1_map[ value_type ]

    level2 = ''
    for value_type in level2_map.keys():
      level2 += level2_map[ value_type ]

    #
    # handle addition of includes
    #
    includes_code = ''
    unique_includes = []
    for include in includes:
      if include not in unique_includes:
        unique_includes += [ include ]
    sorted_includes = sorted( unique_includes, lambda x, y: cmp( x.lower(), y.lower() ) )
    if len( sorted_includes ) > 0:
      includes_code = "\n".join( sorted_includes )

    result = template_map[ 'blas.hpp' ]
    result = result.replace( '$INCLUDES', includes_code )
    result = result.replace( '$OVERLOADS', overloads )
    result = result.replace( '$LEVEL1', level1 )
    result = result.replace( '$LEVEL2', level2 )
    result = result.replace( '$GROUPNAME', group_name )
    result = result.replace( '$groupname', group_name.lower() )
    result = result.replace( '$DIRNAME', base_dir.split("/")[-1].upper() )
    result = result.replace( '$dirname', base_dir.split("/")[-1].lower() )
    result = result.replace( '$INTEGER_TYPE', netlib.fortran_integer_type )
    result = result.replace( 'template<  >', '' )
    result = result.replace( '\n\n\n', '\n\n' )
    result = result.replace( "\n    \n", "\n" )
    result = result.replace( '\n        \n', '\n' )
    result = result.replace( '\n        \n', '\n' )

    # replace the global variables as last (this is convenient)
    #result = result.replace( '$INDENT', '    ' )
    #result = result.replace( '$groupname', group_name.lower() )
    #result = result.replace( '$DESCRIPTION', info_map[ group[g][0] ][ 'description' ] )

    open( os.path.join( base_dir, filename ), 'wb' ).write( result )


#
# Write the (many) driver routine test cases to cpp files.
#
def write_test_case( info_map, group, template_map, base_dir, level_name ):

  for group_name, subroutines in group.iteritems():

    filename = group_name.lower() + '.cpp'
    result = template_map[ 'test_case.cpp' ]
    result = result.replace( '$groupname', group_name.lower() )
    result = result.replace( '$levelname', level_name.lower() )
    result = result.replace( '$library', 'blas' )

    open( os.path.join( base_dir, filename ), 'wb' ).write( result )

def write_cmakefile( level_properties, template_map, base_dir ):
  
  entries = '' 
  if level_properties.has_key( 'routines_by_value_type' ):
      group = level_properties[ 'routines_by_value_type' ]
      for group_name, subroutines in group.iteritems():
        sub_result = template_map[ 'CMakeLists.entry' ]
        sub_result = sub_result.replace( '$groupname', group_name.lower() )
        entries += sub_result

  filename = 'CMakeLists.txt'
  result = template_map[ 'CMakeLists.txt' ]
  result = result.replace( '$ENTRIES', entries )
  open( os.path.join( base_dir, filename ), 'wb' ).write( result )



def read_templates( template_file ):
  file_contents = open( template_file ).read()
  split_regex = re.compile( '^\$TEMPLATE\[([^\]]+)\]\s', re.M | re.S )
  split_templates = split_regex.split( file_contents )[ 1:-1 ]
  result = {}
  for index in range(len(split_templates)/2):
    print "Adding template", split_templates[ index*2 ]
    result[ split_templates[ index*2 ] ] = split_templates[ index*2 + 1 ]
  return result

lapack_src_path = './blas-1.2/src'
cblas_h_path = './blas-1.2/cblas/src/cblas.h'
cublas_h_path = './cublas.h'
template_src_path = './templates'
bindings_impl_target_path = '../../../../boost/numeric/bindings/blas/'
test_target_path = '../test/blas/'
bindings_doc_target_path = '../doc/blas/'

# Unable to find zdrot in cblas.h and cublas.h
# Unable to find crotg, csrot, in cblas.h
skip_blas_files = [ 'zdrot.f', 'crotg.f', 'zrotg.f', 'csrot.f' ]

templates = {}
templates[ 'PARSERMODE' ] = 'BLAS'
for root, dirs, files in os.walk( template_src_path ):
  right_file = re.compile( '^.+\.(cpp|h|hpp|txt|qbk)$' )
  for template_file in files:
    if right_file.match( template_file ) != None:
      path_to_template_file = os.path.join( root, template_file )
      print "Reading template file", path_to_template_file
      templates.update( read_templates( path_to_template_file ) )

function_info_map = {}
for lapack_file in os.listdir( lapack_src_path ):
  right_file = re.compile( '^[cdsz].+\.f$' )
  if right_file.match( lapack_file ) != None and lapack_file not in skip_blas_files:
    print "Parsing", lapack_file, "..."
    key, value = netlib.parse_file( os.path.join( lapack_src_path, lapack_file ), templates )
    if key != None and value != None:
      print "Adding BLAS subroutine", key
      function_info_map[ key ] = value

cblas.parse_file( cblas_h_path, function_info_map, templates )
cublas.parse_file( cublas_h_path, function_info_map, templates )

print "Grouping subroutines..."

value_type_groups = {}
value_type_groups = group_by_value_type( function_info_map )

routines = {}
routines[ 'level1' ] = {}
routines[ 'level1' ][ 'endings' ] = [ 'ROTG', 'OTMG', 'ROT', 'ROTM', 'SWAP', 'SCAL', 'COPY', 'AXPY', 'DOT', 'DOTU', 'DOTC', 'NRM2', 'ASUM', 'AMAX' ]

routines[ 'level2' ] = {}
routines[ 'level2' ][ 'endings' ] = [ 'MV', 'SV', 'GER', 'GERU', 'GERC', 'HER', 'HPR', 'HER2', 'HPR2', 'SYR', 'SPR', 'SPR2', 'SYR2' ]

routines[ 'level3' ] = {}
routines[ 'level3' ][ 'endings' ] = [ 'MM', 'RK', 'R2K', 'SM' ]

for name in value_type_groups.keys():
  found = False
  for level, level_properties in routines.iteritems():
      if name[ -2: ] in level_properties[ 'endings' ] or \
         name[ -3: ] in level_properties[ 'endings' ] or \
         name[ -4: ] in level_properties[ 'endings' ]:
        print name, "is in " + level
        if not level_properties.has_key( 'routines_by_value_type' ):
          level_properties[ 'routines_by_value_type' ] = {}
        level_properties[ 'routines_by_value_type' ][ name ] = value_type_groups[ name ]
        found = True
  if found == False:
    print name, "is in {??}"

print routines 

bindings.write_names_header( function_info_map, routines, templates, bindings_impl_target_path + 'detail/blas_names.h' )
bindings.write_header( function_info_map, routines, templates, bindings_impl_target_path + 'detail/blas.h' )

for level, level_properties in routines.iteritems():
  impl_target_path = bindings_impl_target_path + level
  if not os.path.exists( impl_target_path ):
    print "Creating directory " + impl_target_path
    os.mkdir( impl_target_path )

  doc_target_path = bindings_doc_target_path + level
  if not os.path.exists( doc_target_path ):
    print "Creating directory " + doc_target_path
    os.mkdir( doc_target_path )

  if not os.path.exists( test_target_path + level ):
    print "Creating directory " + doc_target_path
    os.mkdir( test_target_path + level )

  print level_properties

  if level_properties.has_key( 'routines_by_value_type' ):
    print "has key..." 
    write_functions( function_info_map, level_properties[ 'routines_by_value_type' ], templates, impl_target_path )
    documentation.write_documentation( function_info_map, level_properties[ 'routines_by_value_type' ], templates, doc_target_path )
    write_test_case( function_info_map, level_properties[ 'routines_by_value_type' ], templates, test_target_path + level, level )

  write_cmakefile( level_properties, templates, test_target_path + level )

