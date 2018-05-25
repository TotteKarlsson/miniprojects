%module freemenot

%{
#include "freemenot.h"
using namespace mine;
%}
 
%include "std_string.i"

%pythonprepend mine::MyContainer::add(mine::MyObjectBase* o) %{
    print('thisown was: '  + str(o.thisown))
    o.thisown = 0
    print('thisown is now: ' + str(o.thisown))
%}

#define MyExport 
//Expose to Python
%include "freemenot.h"

%template(intObject)          mine::MyTemplateDerived<int>;


