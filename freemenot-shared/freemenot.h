#ifndef freemenotH
#define freemenotH
#include <vector>
#include <string>
#include "myexporter.h"
#include "MyObject.h"
using std::string;

namespace dsl
{

class MyExport MyObjectBase : public MyObject
{
    public:
                        MyObjectBase(const string& lbl);
                        ~MyObjectBase();
        string          getLabel();

    private:
        string          label;
};

class MyExport MyDerived : public MyObjectBase
{
    public:
                        MyDerived() : MyObjectBase("Derived"){}
                        ~MyDerived(){}
};

template<class T>
class MyTemplateDerived : public MyObjectBase
{
    public:
                        MyTemplateDerived<T>() : MyObjectBase("TemplateDerived"){}

};

class MyExport MyContainer : public MyObject
{
    public:
                        MyContainer();
                        ~MyContainer();
        void            add(dsl::MyObjectBase* o);
        MyObjectBase*   getObject(unsigned int t);
        int             getNrOfObjects();

    private:
        std::vector<MyObjectBase*>   mObjects;
};

}
#endif
