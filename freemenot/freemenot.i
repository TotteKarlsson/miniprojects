%module freemenot

%{
#include "freemenot.h"
using namespace mine;
%}
 
%include "std_string.i"

%pythonprepend mine::MyContainer::addObject(mine::MyObject* o) %{
    print('thisown was: '  + str(o.thisown))
    o.thisown = 0
    #args[0]
    print('thisown is now: ' + str(o.thisown))
%}

//Expose to Python
%include "freemenot.h"


