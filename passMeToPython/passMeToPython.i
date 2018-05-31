%module passmetopython

%{
#include "MyClass.h"
%}

%include "std_string.i"

//Expose to Python
%include "MyClass.h"




