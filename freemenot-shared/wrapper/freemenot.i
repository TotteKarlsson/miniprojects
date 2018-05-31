%module freemenot

%{
#include "freemenot.h"
#include "MyObject.h"
#include "Properties.h"
#include "BaseProperty.h"
#include "Property.h"


using namespace dsl;
%}

%include "std_string.i"

%pythonprepend dsl::MyContainer::add(dsl::MyObjectBase* o) %{
    print('thisown was: '  + str(o.thisown))
    o.thisown = 0
    print('thisown is now: ' + str(o.thisown))
%}

%pythonprepend dsl::Properties::add(dsl::BaseProperty* o) %{
    print('thisown was: '  + str(o.thisown))
    o.thisown = 0
    print('thisown is now: ' + str(o.thisown))
%}

#define MyExport


//Expose to Python
%include "MyObject.h"
%include "freemenot.h"

#Base property must be included before the Properties header
#If not, a SWIGPyObject is returned from the container, instead of "a Base Property"
%include "BaseProperty.h"
%include "Properties.h"
%include "Property.h"


%template(intObject)          dsl::MyTemplateDerived<int>;
%template(intProperty)        dsl::Property<int>;


