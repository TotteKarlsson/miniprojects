#ifndef freemenotH
#define freemenotH
#include <vector>
#include <string>
#include "freemenotexporter.h"
using std::string;

namespace mine
{

class MyExport TObject
{

};

class MyExport MyObjectBase : public TObject
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

class MyExport MyContainer : public TObject
{
    public:
                        MyContainer();
                        ~MyContainer();
        void            add(mine::MyObjectBase* o);
        MyObjectBase*   getObject(unsigned int t);
        int             getNrOfObjects();

    private:
        std::vector<MyObjectBase*>   mObjects;
};

}
#endif
