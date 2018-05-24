#ifndef freemenotH
#define freemenotH
#include <vector>
#include <string>

using std::string;
#if defined (_WIN32)
//     #if defined(EXPORT_DLL)
//         #define MyExport __declspec(dllexport)
//     #else
//         #define MyExport __declspec(dllimport)
//     #endif
// #else
    #define MyExport
#endif    

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
