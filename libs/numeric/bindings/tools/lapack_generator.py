#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Copyright (c) 2008 Thomas Klimpel and Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import netlib, bindings, documentation
import cblas

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
  


  
def indent_lines( source_text, indent_size = 8 ):
  indent_string = '\n'
  for i in range(indent_size):
    indent_string += ' '
  return indent_string.join( source_text.splitlines() )
  

  
#
# Write the (many) driver routine file(s).
#
def write_functions( info_map, group, template_map, base_dir ):
  #
  # group.keys() is a vector of different grouped function names
  # like gees, dgesv, etc.
  #
  for group_name, subroutines in group.iteritems():
    
    filename = group_name.lower() + '.hpp'
    includes = [ '#include <boost/assert.hpp>',
      '#include <boost/numeric/bindings/remove_imaginary.hpp>',
      '#include <boost/numeric/bindings/value.hpp>',
      '#include <boost/numeric/bindings/begin.hpp>',
      '#include <boost/numeric/bindings/size.hpp>',
      #'#include <boost/numeric/bindings/tag.hpp>',
      '#include <boost/numeric/bindings/stride.hpp>',
      '#include <boost/numeric/bindings/is_mutable.hpp>',
      #'#include <boost/numeric/bindings/traits/traits.hpp>',
      #'#include <boost/numeric/bindings/traits/type_traits.hpp>', 
      #'#include <boost/mpl/bool.hpp>',
      '#include <boost/type_traits/is_same.hpp>',
      '#include <boost/type_traits/remove_const.hpp>',
      '#include <boost/static_assert.hpp>' ]

    if template_map.has_key( group_name.lower() + '.includes' ):
      includes += template_map[ group_name.lower() + '.includes' ].splitlines()

    #
    # LEVEL 0 HANDLING
    #
    # If the first subroutine has a clapack_ routine, assume we are going
    # to provide specialisations
    overloads = ''
    backend_includes = ''
    if 'clapack_routine' in info_map[ subroutines[0] ]:
        overloads = template_map[ 'backend_lapack_with_clapack' ]
        backend_includes = template_map[ 'lapack_backend_includes_with_clapack' ]
    else:
        overloads = template_map[ 'backend_lapack_default' ]
        backend_includes = template_map[ 'lapack_backend_includes_default' ]

    for select_backend in [ 'lapack_overloads', 'clapack_overloads' ]:

      sub_overloads = ''

      for subroutine in subroutines:

        sub_template = template_map[ select_backend ]
        have_clapack = 'clapack_routine' in info_map[ subroutine ]
        # add the argument list here
        arg_list = []
        lapack_arg_list = []
        clapack_arg_list = []
        typename_list = []
        level0_static_asserts = []

        for arg in info_map[ subroutine ][ 'arguments' ]:
            print "Subroutine ", subroutine, " arg ", arg
            if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0' ] != None:
                arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0' ] ]
            if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_lapack_header' ] != None:
                lapack_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_lapack_header' ] ]
            if have_clapack and info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_clapack_header' ] != None:
                clapack_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_clapack_header' ] ]
            if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0_typename' ] != None:
                typename_list +=  [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_0_typename' ] ]

        if "has_clapack_order_arg" in info_map[ subroutine ]:
            if info_map[ subroutine ][ "has_clapack_order_arg" ] == True:
                arg_list.insert( 0, "Order" )
                clapack_arg_list.insert( 0, "clapack_option< Order >::value" )
                typename_list.insert( 0, "typename Order" )
                level0_static_asserts.append( "BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );" )
                includes += [ "#include <boost/type_traits/is_same.hpp>" ]

        sub_template = sub_template.replace( "$TYPES", ", ".join( typename_list ) )
        sub_template = sub_template.replace( "template<  >\n", "" )
        sub_template = sub_template.replace( "$LEVEL0", ", ".join( arg_list ) )
        sub_template = sub_template.replace( "$CALL_LAPACK_HEADER", ", ".join( lapack_arg_list ) )
        sub_template = sub_template.replace( "$CALL_CLAPACK_HEADER", ", ".join( clapack_arg_list ) )
        sub_template = sub_template.replace( "$SUBROUTINE", subroutine )
        sub_template = sub_template.replace( '$groupname', group_name.lower() )
        sub_template = sub_template.replace( "$SPECIALIZATION", documentation.routine_value_type[ subroutine[0] ] )
        sub_template = sub_template.replace( '$STATIC_ASSERTS', "\n    ".join( level0_static_asserts ) )

        if select_backend == 'lapack_overloads':
            sub_template = sub_template.replace( '$LIBRARY_INT_TYPE', "fortran_int_t" )
        else:
            sub_template = sub_template.replace( '$LIBRARY_INT_TYPE', "int" )

        # CLAPACK stuff
        if 'clapack_routine' in info_map[ subroutine ]:
            clapack_routine = info_map[ subroutine ][ 'clapack_routine' ]
        else:
            clapack_routine = '// NOT FOUND'
        sub_template = sub_template.replace( "$CLAPACK_ROUTINE", clapack_routine )


        # Finalize this sub_overload
        sub_overloads += bindings.proper_indent( sub_template )

      # fill in for the appropriate back-end
      print "Replacing ", '$' + select_backend.upper()
      overloads = overloads.replace( '$' + select_backend.upper(),
        sub_overloads )

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

    # Figure out what the real/complex type selector argument might be
    type_selector_candidates = []
    if cases.has_key( 'real' ) and cases.has_key( 'complex' ):
      # we have real and complex scenarios, these keys only exist
      # if we also have associated routines
      for arg in info_map[ cases[ 'real' ][ 'subroutines' ][0] ][ 'arguments' ]:
        if arg in info_map[ cases[ 'complex' ][ 'subroutines' ][0] ][ 'arguments' ]:
          if info_map[ cases[ 'real' ][ 'subroutines' ][0] ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None and \
             info_map[ cases[ 'complex' ][ 'subroutines' ][0] ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None and \
             info_map[ cases[ 'real' ][ 'subroutines' ][0] ][ 'argument_map' ][ arg ][ 'value_type_variant' ] == 'real' and \
             info_map[ cases[ 'complex' ][ 'subroutines' ][0] ][ 'argument_map' ][ arg ][ 'value_type_variant' ] == 'complex':
            type_selector_candidates += [ arg ]

    #
    # LEVEL 1 and 2 HANDLING
    #
    level1_map = {}
    level2_map = {}
    for value_type, case_map in cases.iteritems():

      level1_template = ''
      level2_template = ''
      if info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ].has_key( 'workspace' ):
        level1_template = template_map[ 'level1_workspace' ]
        level2_template = template_map[ 'level2_workspace' ]
      else:
        level1_template = template_map[ 'level1_noworkspace' ]
        level2_template = template_map[ 'level2_noworkspace' ]

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

      # continue with first replacements
      level1_template = level1_template.replace( '$groupname', group_name.lower() )
      level1_template = level1_template.replace( "$SPECIALIZATION", value_type )

      # take this subroutine for arguments etc.
      subroutine = case_map[ 'subroutines' ][ 0 ]
      print "taking",subroutine
      
      level0_arg_list = []
      level1_arg_list = []
      level2_arg_list = []
      level1_type_arg_list = []
      level1_assert_list = []
      level1_static_assert_list = []
      call_level1_arg_list = []
      workspace_query_arg_list = []
      user_defined_arg_list = []
      user_defined_opt_arg_list = []
      keyword_type_list = []
      typedef_list = []

      #
      # Add an include in case of the uplo or diag options
      #
      if 'UPLO' in info_map[ subroutine ][ 'arguments' ]:
        includes += [ '#include <boost/numeric/bindings/data_side.hpp>' ]
      if 'DIAG' in info_map[ subroutine ][ 'arguments' ]:
        includes += [ '#include <boost/numeric/bindings/diag_tag.hpp>' ]
      if 'TRANS' in info_map[ subroutine ][ 'arguments' ]:
        includes += [ '#include <boost/numeric/bindings/trans_tag.hpp>' ]

      #
      # Create static assertions, first by value type
      #
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
            assert_line = 'BOOST_STATIC_ASSERT( (boost::is_same< ' + \
                'typename remove_const< typename value< ' + info_map[ subroutine ][ 'argument_map' ][ arg_A ][ 'code' ][ 'level_1_static_assert' ] + ' >::type >::type, ' + \
                'typename remove_const< typename value< ' + info_map[ subroutine ][ 'argument_map' ][ arg_B ][ 'code' ][ 'level_1_static_assert' ] + ' >::type >::type' \
                ' >::value) );'
            level1_static_assert_list += [ assert_line ]

      # Make sure the mutable stuff is mutable
      if 'output' in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ]:
        for arg in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'output' ]:
          if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None:
            assert_line = 'BOOST_STATIC_ASSERT( (is_mutable< ' + \
                info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_static_assert' ] + ' >::value) );'
            level1_static_assert_list += [ assert_line ]

      # import the code, by argument
      for arg in info_map[ subroutine ][ 'arguments' ]:
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_0' ] != None:
          level0_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_0' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1' ] != None:
          level1_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] != None:
          level2_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_2' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] != None and \
          info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] not in level1_type_arg_list:
          level1_type_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_type' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_assert' ] != []:
          level1_assert_list += info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'level_1_assert' ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_1' ] != None:
          call_level1_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'call_level_1' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'opt_workspace_query' ] != None:
          workspace_query_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'opt_workspace_query' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'typedef' ] != None:
          typedef_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'typedef' ] ]
        if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'keyword_type' ] != None:
          keyword_type_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'keyword_type' ] ]

      if info_map[ subroutine ][ 'user_defined_variables' ] != None:
        for arg in info_map[ subroutine ][ 'user_defined_variables' ]:
          print arg
          if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'user_defined_init' ] != None:
            user_defined_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'user_defined_init' ] ]

      if info_map[ subroutine ][ 'user_defined_opt_variables' ] != None:
        for arg in info_map[ subroutine ][ 'user_defined_opt_variables' ]:
          print arg
          if info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'user_defined_init' ] != None:
            user_defined_opt_arg_list += [ info_map[ subroutine ][ 'argument_map' ][ arg ][ 'code' ][ 'user_defined_init' ] ]

      # Insert the order_type() if appropriate
      if "has_clapack_order_arg" in info_map[ subroutine ]:
          level0_arg_list.insert( 0, "order()" )

      # Level 1 replacements
      level1_template = level1_template.replace( "$TYPEDEFS", "\n        ".join( typedef_list ) )
      level1_template = level1_template.replace( "$CALL_LEVEL0", ", ".join( level0_arg_list ) )
      level1_template = level1_template.replace( "$CALL_LEVEL1", ", ".join( call_level1_arg_list ) )
      level1_template = level1_template.replace( "$LEVEL1", ", ".join( level1_arg_list ) )
      level1_template = level1_template.replace( "$TYPES", ", ".join( level1_type_arg_list ) )
      level1_template = level1_template.replace( "$ASSERTS", "\n        ".join( sorted( level1_assert_list ) ) )
      level1_template = level1_template.replace( "$KEYWORDS", ", ".join( keyword_type_list ) )
      
      if len( level1_static_assert_list ) > 0:
        level1_template = level1_template.replace( "$STATIC_ASSERTS", "\n        ".join( level1_static_assert_list ) )
      else:
        level1_template = level1_template.replace( "\n        $STATIC_ASSERTS", "" )

      if len( user_defined_arg_list ) > 0:
        level1_template = level1_template.replace( "$INIT_USER_DEFINED_VARIABLES", indent_lines( "\n".join(user_defined_arg_list), 8 ) )
      else:
        level1_template = level1_template.replace( "\n        $INIT_USER_DEFINED_VARIABLES", "" )

      # Level 2 replacements
      # some special stuff is done here, such as replacing real_type with a 
      # type-traits deduction, etc..
      # more important: all non-const and const variants of functions are written here
      level2_functions = []
      level2_arg_lists, level2_comments = \
            bindings.generate_const_variants( \
                group_name.lower() + '.' + value_type, level2_arg_list, template_map )
      for level2_idx in range( 0, len( level2_arg_lists ) ):
        level2_function = level2_template.replace( "$LEVEL2", \
                ", ".join( level2_arg_lists[ level2_idx ] ) )
        if len( "".join(level2_comments[ level2_idx ] ) ) > 0:
          level2_function = level2_function.replace( "$COMMENTS", \
                "\n".join( level2_comments[ level2_idx ] ) )
        level2_functions.append( level2_function )

      level2_template = "\n".join( level2_functions )
      level2_template = level2_template.replace( "$COMMENTS\n", "" )

      # Determine a right type to select for real or complex variants
      first_typename = ''
      print "Type selectors: ", type_selector_candidates
      if len( type_selector_candidates ) > 0:
        first_typename_arg = type_selector_candidates[0]
        first_typename_code = info_map[ subroutine ][ 'argument_map' ][ first_typename_arg ][ 'code' ][ 'level_1_type' ]
        first_typename = first_typename_code.split(" ")[-1]
      else:
        first_typename = level1_type_arg_list[0].split(" ")[-1]

      # generate the word "matrix" or "vector", to select the right traits
      first_typename_datatype = first_typename[0:6].lower()
      level2_template = level2_template.replace( "$FIRST_TYPENAME", first_typename )
      level2_template = level2_template.replace( "$TYPEOF_FIRST_TYPENAME", first_typename_datatype )
      level2_template = level2_template.replace( "$CALL_LEVEL1", ", ".join( call_level1_arg_list ) )
      level2_template = level2_template.replace( "$TYPES", ", ".join( level1_type_arg_list ) )

      #
      # Workspace stuff
      #
      if info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ].has_key( 'workspace' ):
        # Add an include for the workspace stuff
        includes += [ '#include <boost/numeric/bindings/lapack/workspace.hpp>' ]
        includes += [ '#include <boost/numeric/bindings/detail/array.hpp>' ]

        # Continue
        workspace_size = len( info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'workspace' ] )
        workspace_args = info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'workspace' ]
        level1_template = level1_template.replace( "$WORKSPACE_SIZE", str(workspace_size) )
        level1_template = level1_template.replace( "$WORKSPACE_TYPENAMES", "typename " + ", typename ".join( workspace_args ) )
        level1_template = level1_template.replace( "$WORKSPACE_TYPES", ", ".join( workspace_args ) )

        # $TMP_WORKARRAYS is something like "tmp_work, tmp_rwork"
        tmp_workspace_args = []
        for name in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'workspace' ]:
          tmp_workspace_args += [ 'tmp_' + name.lower() ]
        level1_template = level1_template.replace( "$TMP_WORKARRAYS", ", ".join( tmp_workspace_args ) )
        
        # $SETUP_WORKARRAYS looks like 
        #    traits::detail::array< value_type > $TMP_NAME .... 
        setup_min_workarrays = ''
        setup_opt_workarrays_pre = []
        setup_opt_workarrays_post = []
        for name in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'workspace' ]:
          # minimal case
          sub_min_template = template_map[ 'setup_min_workspace' ]
          sub_min_template = sub_min_template.replace( '$NAME', name.lower() )
          sub_min_template = sub_min_template.replace( '$WORKSPACE_TYPE', info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'workspace_type' ] )
          if info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace_call' ] != None:
            sub_min_template = sub_min_template.replace( "$CALL_MIN_SIZE", info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace_call' ] )
          
          setup_min_workarrays += sub_min_template

          # optimal case
          if info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'opt_workspace_pre' ] != None:
            setup_opt_workarrays_pre += [ info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'opt_workspace_pre' ] ]
          if info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'opt_workspace_post' ] != None:
            setup_opt_workarrays_post += [ info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'opt_workspace_post' ] ]


        # if the length of setup_opt_workarrays_post equals 0, it's equal to the minimal_case
        opt_workspace_template = ''
        if len( setup_opt_workarrays_post ) == 0:
          print "EQUAL to MINIMAL CASE!"
          opt_workspace_template = template_map[ 'level1_opt_workspace_is_min' ]
        else:
          includes += [ '#include <boost/numeric/bindings/traits/detail/utils.hpp>' ]
          opt_workspace_template = template_map[ 'level1_opt_workspace' ]

        opt_workspace_template = opt_workspace_template.replace( "$WORKSPACE_QUERY", ", ".join( workspace_query_arg_list ) )
        opt_workspace_template = opt_workspace_template.replace( "$SETUP_OPT_WORKARRAYS_POST", "\n        ".join( setup_opt_workarrays_post ) )
        opt_workspace_template = opt_workspace_template.replace( "$SETUP_OPT_WORKARRAYS_PRE", "\n        ".join( setup_opt_workarrays_pre ) )
        opt_workspace_template = opt_workspace_template.replace( "$CALL_LEVEL1", ", ".join( call_level1_arg_list ) )
        opt_workspace_template = opt_workspace_template.replace( "$TMP_WORKARRAYS", ", ".join( tmp_workspace_args ) )
        
      
        if len( user_defined_opt_arg_list ) > 0:
          opt_workspace_template = opt_workspace_template.replace( "$INIT_USER_DEFINED_OPT_VARIABLES", indent_lines( "\n".join(user_defined_arg_list), 8 ) )
        else:
          print "removing $INIT_USER_DEFINED_OPT_VARIABLES"
          opt_workspace_template = opt_workspace_template.replace( "        $INIT_USER_DEFINED_OPT_VARIABLES\n", "" )
        
        
        level1_template = level1_template.replace( "$OPT_WORKSPACE_FUNC", opt_workspace_template.rstrip() )
        level1_template = level1_template.replace( "$SETUP_MIN_WORKARRAYS_POST", setup_min_workarrays.rstrip() )
        
        
        #
        # INSERT THE MINIMAL WORKSPACE FUNCTIONS
        #
        min_size_funcs = ''
        for name in info_map[ subroutine ][ 'grouped_arguments' ][ 'by_io' ][ 'workspace' ]:
          sub_template = template_map[ 'min_size_func' ]
          sub_template = sub_template.replace( "$NAME", name.lower() )

          # first: user-defined stuff (overrules any auto-detected stuff)

          my_key = group_name.lower() + '.' + value_type + '.min_size_' + name.lower()
          if netlib.my_has_key( my_key, template_map ):
            sub_template = sub_template.replace( "$MIN_SIZE", indent_lines( template_map[ netlib.my_has_key( my_key, template_map ) ].rstrip(), 8 ) )

          elif info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace' ] != None:
            resulting_code = 'return ' + info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace' ] + ';'
            sub_template = sub_template.replace( "$MIN_SIZE", resulting_code.rstrip() )
            
          # Do about the same for the argument stuff.  
          if info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace_args' ] != None:
            sub_template = sub_template.replace( "$ARGUMENTS", info_map[ subroutine ][ 'argument_map' ][ name ][ 'code' ][ 'min_workspace_args' ] )

            #sub_template += 'FOUND'
          min_size_funcs += sub_template

        min_size_funcs = min_size_funcs.rstrip()
        level1_template = level1_template.replace( "$MIN_SIZE_FUNCS", min_size_funcs )

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
    if len( level1_map ) > 1:
      level1 = template_map[ 'level1_pre_header' ]
      includes += [ '#include <boost/utility/enable_if.hpp>' ]
      includes += [ '#include <boost/numeric/bindings/is_real.hpp>' ]
      includes += [ '#include <boost/numeric/bindings/is_complex.hpp>' ]

    for value_type in level1_map.keys():
      if len( level1_map ) == 1:
        header = template_map[ 'level1_header1' ]
      else:
        header = template_map[ 'level1_header2' ]

      level1 += header.replace( "$SPECIALIZATION", value_type )
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

    result = template_map[ 'lapack.hpp' ]
    result = result.replace( '$INCLUDES', includes_code )
    result = result.replace( '$BACKEND_INCLUDES', backend_includes )
    result = result.replace( '$OVERLOADS', overloads )
    result = result.replace( '$LEVEL1', level1 )
    result = result.replace( '$LEVEL2', level2 )
    result = result.replace( '$GROUPNAME', group_name )
    result = result.replace( '$groupname', group_name.lower() )
    result = result.replace( '$DIRNAME', base_dir.split("/")[-1].upper() )
    result = result.replace( '$dirname', base_dir.split("/")[-1].lower() )
    result = result.replace( '$INTEGER_TYPE', netlib.generic_integer_type )
    result = result.replace( '$LIBRARY_INT_TYPE', "fortran_int_t" )
    result = result.replace( '\n\n\n', '\n\n' )
    result = result.replace( "\n    \n", "\n" )
    result = result.replace( "\n        \n", "\n" )
    result = result.replace( "\n        \n", "\n" )

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
    result = result.replace( '$library', 'lapack' )

    open( os.path.join( base_dir, filename ), 'wb' ).write( result )

def write_cmakefile( level_properties, template_map, base_dir ):
  
  entries = '' 
  for problem_type, problem_properties in level_properties.iteritems():
    if problem_properties.has_key( 'routines_by_value_type' ):
      group = problem_properties[ 'routines_by_value_type' ]
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

lapack_src_path = './lapack-3.2.0/SRC'
clapack_h_path = './atlas-3.6.0/include/clapack.h'
template_src_path = './templates'
bindings_impl_target_path = '../../../../boost/numeric/bindings/lapack/'
test_target_path = '../test/lapack/'
bindings_doc_target_path = '../doc/lapack/'

templates = {}
templates[ 'PARSERMODE' ] = 'LAPACK'
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
  if right_file.match( lapack_file ) != None:
    print "Parsing", lapack_file, "..."
    key, value = netlib.parse_file( os.path.join( lapack_src_path, lapack_file ), templates )
    if key != None and value != None:
      print "Adding LAPACK subroutine", key
      function_info_map[ key ] = value

cblas.parse_file( clapack_h_path, function_info_map, templates )

print "Grouping subroutines..."

value_type_groups = {}
value_type_groups = group_by_value_type( function_info_map )

routines = {}
routines[ 'driver' ] = {}
routines[ 'driver' ][ 'linear_equations' ] = {}
routines[ 'driver' ][ 'linear_equations' ][ 'endings' ] = [ 'SV', 'SVX' ]

routines[ 'driver' ][ 'least_squares' ] = {}
routines[ 'driver' ][ 'least_squares' ][ 'endings' ] = [ 'LS', 'LSY', 'LSS', 'LSD' ]

routines[ 'driver' ][ 'general_least_squares' ] = {}
routines[ 'driver' ][ 'general_least_squares' ][ 'endings' ] = [ 'LSE', 'GLM' ]

# based on LAPACK Users' Guide, table 2.5
routines[ 'driver' ][ 'eigen' ] = {}
routines[ 'driver' ][ 'eigen' ][ 'endings' ] = [ 'YEV', 'EEV', 'YEVX', 'EEVX', 'YEVD', 'EEVD', 'YEVR', 'EEVR', 'EES', 'PEV', 'PEVD', 'PEVX', 'BEV', 'BEVD', 'BEVX', 'EESX', 'ESVD', 'ESDD', 'TEV', 'TEVD', 'TEVX', 'TEVR' ]

# based on LAPACK Users' Guide, table 2.6
routines[ 'driver' ][ 'general_eigen' ] = {}
routines[ 'driver' ][ 'general_eigen' ][ 'endings' ] = [ 'GV', 'GVD', 'GVX', 'GES', 'GESX', 'GEV', 'GEVX', 'GSVD' ]


routines[ 'computational' ] = {}

# based on LAPACK Users' Guide, table 2.7
routines[ 'computational' ][ 'linear_equations' ] = {}
routines[ 'computational' ][ 'linear_equations' ][ 'endings' ] = [ 'TRF', 'TRS', 'CON', 'RFS', 'TRI', 'EQU' ]

# based on LAPACK Users' Guide, table 2.9 
routines[ 'computational' ][ 'least_squares' ] = {}
routines[ 'computational' ][ 'least_squares' ][ 'endings' ] = [ 'QP3', 'EQRF', 'GQR', 'MQR', 'LQF', 'GLQ', 'MLQ', 'QLF', 'GQL', 'MQL', 'ERQF', 'GRQ', 'MRQ', 'RZF', 'RZ' ]

routines[ 'computational' ][ 'general_least_squares' ] = {}
routines[ 'computational' ][ 'general_least_squares' ][ 'endings' ] = [ 'GQRF', 'GRQF' ]

# based on LAPACK Users' Guide, table 2.10
routines[ 'computational' ][ 'symmetric_eigen' ] = {}
routines[ 'computational' ][ 'symmetric_eigen' ][ 'endings' ] = [ 'TRD', 'MTR', 'GTR', 'TEQR', 'ERF', 'EDC', 'EGR', 'EBZ', 'TEIN', 'EMR' ]

# based on LAPACK Users' Guide, table 2.11
routines[ 'computational' ][ 'nonsymmetric_eigen' ] = {}
routines[ 'computational' ][ 'nonsymmetric_eigen' ][ 'endings' ] = [ 'EHRD', 'EBAL', 'EBAK', 'GHR', 'MHR', 'SEQR', 'SEIN', 'REVC', 'REXC', 'RSYL', 'RSNA', 'RSEN' ]

# based on LAPACK Users' Guide, table 2.12
routines[ 'computational' ][ 'svd' ] = {}
routines[ 'computational' ][ 'svd' ][ 'endings' ] = [ 'BRD', 'GBR', 'MBR', 'SQR', 'SDC' ]

# based on LAPACK Users' Guide, table 2.14
routines[ 'computational' ][ 'general_eigen' ] = {}
routines[ 'computational' ][ 'general_eigen' ][ 'endings' ] = [ 'GST', 'STF' ]

# based on LAPACK Users' Guide, table 2.15
routines[ 'computational' ][ 'general_nonsymmetric_eigen' ] = {}
routines[ 'computational' ][ 'general_nonsymmetric_eigen' ][ 'endings' ] = [ 'GHRD', 'GBAL', 'GBAK', 'EQZ', 'GEVC', 'GEXC', 'GSYL', 'GSNA', 'GSEN' ]

# based on LAPACK Users' Guide, table 2.16
routines[ 'computational' ][ 'general_nonsymmetric_svd' ] = {}
routines[ 'computational' ][ 'general_nonsymmetric_svd' ][ 'endings' ] = [ 'SVP', 'SJA' ]

for name in value_type_groups.keys():
  found = False
  for level, level_properties in routines.iteritems():
    for problem_type, problem_properties in level_properties.iteritems():
      if name[ -2: ] in problem_properties[ 'endings' ] or \
         name[ -3: ] in problem_properties[ 'endings' ] or \
         name[ -4: ] in problem_properties[ 'endings' ]:
        print name, "is in {"+level+", "+  problem_type + "}"
        if not problem_properties.has_key( 'routines_by_value_type' ):
          problem_properties[ 'routines_by_value_type' ] = {}
        problem_properties[ 'routines_by_value_type' ][ name ] = value_type_groups[ name ]
        found = True
  if found == False:
    print name, "is in {??}"

print routines 


bindings.write_names_header( function_info_map, routines, templates, bindings_impl_target_path + 'detail/lapack_names.h' )
bindings.write_header( function_info_map, routines, templates, bindings_impl_target_path + 'detail/lapack.h' )

bindings.write_include_hierarchy( function_info_map, routines, templates, bindings_impl_target_path )
templates[ 'PARSERMODE' ] = 'LAPACK_DOC'
bindings.write_include_hierarchy( function_info_map, routines, templates, bindings_doc_target_path )
templates[ 'PARSERMODE' ] = 'LAPACK'

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

  for problem_type, problem_properties in level_properties.iteritems():
    if problem_properties.has_key( 'routines_by_value_type' ):
      write_functions( function_info_map, problem_properties[ 'routines_by_value_type' ], templates, impl_target_path )
      documentation.write_documentation( function_info_map, problem_properties[ 'routines_by_value_type' ], templates, doc_target_path )
      write_test_case( function_info_map, problem_properties[ 'routines_by_value_type' ], templates, test_target_path + level, level )

  write_cmakefile( level_properties, templates, test_target_path + level )


