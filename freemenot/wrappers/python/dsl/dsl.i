%module(docstring="Dune Scientific Library (dsl), (c) 1987-2018 Totte Karlsson",threads="1", directors="1" ) dsl

// ************************************************************
// Module Includes
// ************************************************************

// These are copied directly to the .cxx file and are not parsed
// by SWIG.  Include include files or definitions that are required
// for the module to build correctly.

%{
#include "freemenot.h"
#include  <string>
using namespace std;
%}
 
%include "std_string.i"
%include "std_vector.i"

#define DSL_COMMON

//Expose  Python
%include "freemenot.h"


