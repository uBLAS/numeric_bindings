#!/usr/bin/python
#
#  Copyright (c) 2008 Thomas Klimpel and Rutger ter Borg
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#

import re

#
# This routine actually does what it's named after :-).
# Changes: 
# * used regex matching on delimiter instead of .find
#
def proper_indent( input_string ):
  max_chars = 80
  all_results = []
  find_delim = re.compile( "([\,\+/]|\|\||>=|std::log\(|work\()[ ]*" )
  for input_line in input_string.splitlines():
    result = ''
    # extra indentation size is 8
    indentation = len(input_line) - len(input_line.lstrip() ) + 8

    #print "indentation: ", indentation

    indentation_string = ''
    for i in range(indentation ):
      indentation_string += ' '
    #cur_index = input_line.find( ",", 0, -1 ) + 1

    match_delim = find_delim.search( input_line, 0, len(input_line) )
    if match_delim != None:
      #print match_delim.end( 0 )- match_delim.start( 0 )
      cur_index = match_delim.end( 0 )
    else:
      cur_index = 0

    prev_index = 0
    prev_slice = 0
    prev_indentation = 0
    while cur_index != 0:
      if ( (cur_index - prev_slice) > (79-prev_indentation) ):
        result = result + input_line[ prev_slice : prev_index ].rstrip() + '\n' + indentation_string
        prev_indentation = indentation
        prev_slice = prev_index
      prev_index = cur_index
      if cur_index != len(input_line):
        match_delim = find_delim.search( input_line, cur_index+1, len(input_line) )
        if match_delim != None:
          #print match_delim.end( 0 )- match_delim.start( 0 )
          cur_index = match_delim.end( 0 )
        else:
          cur_index = 0
        #cur_index = input_line.find( ",", cur_index+1, -1 ) + 1
        if cur_index == 0:
          cur_index = len(input_line)
      else:
        cur_index = 0
    cur_index = len( input_line )
    result = result + input_line[ prev_slice : cur_index ]
    all_results += [ result ]

  return "\n".join( all_results ) + "\n"



#
# Write the blas.h/lapack_names.h file.
#
def write_names_header( global_info_map, group, template_map, dest_file ):
  parsermode = template_map[ 'PARSERMODE' ].lower()
  group_keys = group.keys()
  group_keys.sort()
  content = ''
  for g in group_keys:
    content += '// Variants of ' + g.lower() + '\n'
    for k in group[ g ]:
      template = template_map[ parsermode + '_names.h_function' ]
      template = template.replace( '$SUBROUTINE', k )
      template = template.replace( '$subroutine', k.lower() )
      content += template
    content += '\n'

  result = template_map[ parsermode + '_names.h' ]
  result = result.replace( "$CONTENT", content )
  #//result = result.replace( "$PARSERMODE", template_map[ "PARSERMODE" ] )

  open( dest_file, 'wb' ).write( result )


#
# Write the blas.h/lapack.h file
#
def write_header( global_info_map, group, template_map, dest_file ):
  parsermode = template_map[ 'PARSERMODE' ].lower()
  group_keys = group.keys()
  group_keys.sort()
  content = ''
  for g in group_keys:
    content += '$INDENT// Variants of ' + g.lower() + '\n'
    for k in group[ g ]:

      template = template_map[ parsermode + '.h_function' ]
      arg_list = []
      for arg in global_info_map[ k ][ 'arguments' ]:
        arg_list += [ global_info_map[ k ][ 'argument_map' ][ arg ][ 'code' ][ 'lapack_h' ] ]

      template = template.replace( "$SUBROUTINE", k )
      template = template.replace( "$ARGUMENTS", ", ".join( arg_list ) )
      template = template.replace( '$RETURN_TYPE', global_info_map[ k ][ 'return_value_type' ] )
      template = template.replace( '$RETURN_STATEMENT', global_info_map[ k ][ 'return_statement' ] )
      content += proper_indent( template )

    content += '\n'

  result = template_map[ parsermode + '.h' ]
  result = result.replace( "$CONTENT", content )
  result = result.replace( '$INDENT', '    ' )
  #result = result.replace( "$PARSERMODE", template_map[ "PARSERMODE" ] )

  open( dest_file, 'wb' ).write( result )
