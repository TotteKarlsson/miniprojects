#ifndef MyObjectH
#define MyObjectH
#include <string>
#include "MyExporter.h"
#include "Constants.h"
//---------------------------------------------------------------------------
using std::string;

namespace dsl
{

class MyExport MyObject
{
    public:
                                        MyObject();
                                        MyObject(const MyObject& obj);
        virtual                         ~MyObject();
        virtual string                  getTypeName() const;
        virtual string                  asString(const char& delimiter=',') const;
        virtual const char*             c_str() const;

    protected:

};

}
#endif
