#ifndef freemenotH
#define freemenotH
#include <vector>
#include <string>

using std::string;

namespace mine
{

class MyObject
{
    public:
                        MyObject(const string& lbl);
                        ~MyObject();
        string          getLabel();

    private:
        string          label;
};

class MyContainer
{
    public:
                    MyContainer();
                    ~MyContainer();
        void        addObject(mine::MyObject* o);
        MyObject*   getObject(unsigned int t);
        int         getNrOfObjects();

    private:
        std::vector<MyObject*>   mObjects;
};

}
#endif




