#ifndef freemenotH
#define freemenotH
#include <vector>
#include <string>
#include "dslCommonExporter.h"

using std::string;
class DSL_COMMON MyObject
{
    public:
                        MyObject(const string& lbl);
                        ~MyObject();
        string          getLabel();

    private:
        string          label;

};

class DSL_COMMON MyContainer
{
    public:
                    MyContainer();
                    ~MyContainer();
        void        addObject(MyObject* o);
        MyObject*   getObject(unsigned int t);
        int         getNrOfObjects();

    private:
        std::vector<MyObject*>   mObjects;
};

#endif




