
Using the Python Generator
----
To test the python generator, you will need the lapack sources. Make sure the path to your lapack sources is also set in the lapack_parser.py file; look for the variable lapack_src_path.

On a debian-based system, acquiring the sources of BLAS and LAPACK may be achieved by 

$ cd tools
$ apt-get source blas lapack

this will give you a subdirectory called 'blas-X.X' and 'lapack-X.X.X'. Running the generator may be done by

$ ./lapack_generator
$ ./blas_generator

from within the tools directory.

To use the compile_test, you need cmake. Please do a 

$ mkdir build
$ cd build
$ cmake ..
$ make

to try to compile all test files. ]
