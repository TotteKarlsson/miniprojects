%module(docstring="Dune Scientific Library (dsl), (c) 1987-2018 Totte Karlsson",threads="1", directors="1" ) dsl

// ************************************************************
// Module Includes
// ************************************************************

// These are copied directly to the .cxx file and are not parsed
// by SWIG.  Include include files or definitions that are required
// for the module to build correctly.

%{
#include "dslObject.h"
#include "dslTypeInfo.h"
#include "dslBaseProperty.h"
#include "dslProperty.h"
#include "dslStringList.h"
#include "dslProperties.h"
#include "Plugins/dslPlugin.h"
#include "Plugins/dslPluginMetaData.h"
#include "Plugins/dslPluginmanager.h"
#include  <string>
using namespace dsl;
using namespace std;
%}
 
%include "std_string.i"
%include "std_vector.i"
%include "std_map.i"
%include "std_list.i"
%include "std_pair.i"
%include "std_set.i"
//%include "std_iostream.i"
//%include "std_sstream.i"
//%include "std_wsstream.i"
//%include "windows.i"

#define DSL_COMMON
#define DSL_PLUGINS
#define DSL_PYTHONPLUGINS
#define Foundation_API

//%feature("director");

%ignore *::operator[];
%ignore *::operator=;
%ignore std::ostream;
%ignore operator<<;
%ignore operator int;
%ignore operator std::string;

%warnfilter(315) ostream; 
%warnfilter(315) stringstream; 

//Expose  Python
%import "dslConstants.h"
%import "Poco/DateTimeFormatter.h"
%import "Poco/SharedLibrary.h"
%include "dslObject.h"
%include "dslTypeInfo.h"
%include "dslBaseProperty.h"
%include "dslProperty.h"
%include "dslProperties.h"
%include "dslPluginMetaData.h"
%include "dslPlugin.h"
%include "dslPluginManager.h"

%template(intProperty)          dsl::Property<int>;
%template(stringProperty)       dsl::Property<std::string>;


