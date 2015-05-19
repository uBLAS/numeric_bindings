# numeric_bindings
Planned official home of numeric bindings

Boost.Numeric_Bindings is a C++ library for numeric computing. It is a generic layer between linear algebra algorithms and data containers. 

For the data container part, it supports both compile-time statically sized and run-time dynamically sized vectors, matrices, through a traits system. Currently it includes traits for C-arrays, for standard vectors, for uBLAS' containers, Eigen containers, TNT, Boost.Array, to name a few. It offers compile-time inspection, iterators, and views on all mentioned containers.

For the algorithm part, it provides a C++ interface to algorithms offered by BLAS, LAPACK, and more. This covers algorithms from most vendor-provided math libraries, such as the reference BLAS, ATLAS, Intel's MKL, AMD's CML, NVidia's CUDA, etc.. 

The Bindings Library contains bindings to popular non-boost (numeric) libraries, usually written in Fortran or C. 
These non-boost libraries generally use data structures in their API for which there might be boostified equivalents or other popular non-boost equivalents.

The Bindings Library offers a generic thin layer API on top of the original API of the external library. This generic API accepts a whole range of data structures from different origins and usually hides or reduces the  complexity of the original API.

E.g., it allows you to write

```
double a[5] = { 1,2,3,4,5 };
double b[5][5];
...
```

In scope are container adaptors and algorithms:

* Adaptors for a wide variety of foreign container types, supporting both 
  compile-time statically sized and run-time dynamically sized containers.
  At the moment, the library includes bindings for C-style arrays, 
  ISO C++ standard vectors, uBLAS', Eigen2, Boost.Array, Boost.MultiArray,
  to name a few.
* Meta-adaptors to create views on these containers, 
  such as row, transpose, and upper. These are convenient when addressing BLAS or LAPACK.
* Iterators supporting different strategies to inspect and modify all containers 
  mentioned above. This invites users to write container-independent algorithms.
* A BLAS module supporting cblas, blas, and cublas backends. This covers algorithms from 
  the reference BLAS, ATLAS, Intel's MKL, AMD's CML, NVidia's CUBLAS, and 
  many more vendor-specific BLASs.
* A LAPACK module supporting lapack and clapack backends. This coverts algorithms from 
  the reference LAPACK, and from the routines implemented by ATLAS.
* A MUMPS module.
* A UMFPACK module.
