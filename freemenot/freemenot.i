%module freemenot

%{
#include "freemenot.h"
%}
 
%include "std_string.i"


#The following wrapper code allow the thisown flag
#to be set to zero, hidden from the client
%pythonprepend MyContainer::addObject(MyObject* o) %{
# mess with thisown
print('thisown was: ' + str(o.thisown))
o.thisown = 0
print('thisown is now: ' + str(o.thisown))

%}

//Expose to Python
%include "freemenot.h"


