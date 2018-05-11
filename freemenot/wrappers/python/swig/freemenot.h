#ifndef freemenotH
#define freemenotH
#include <iostream>
#include <vector>

class MyObject
{
    public:
        MyObject();
        ~MyObject();
};

class MyContainer
{
    public:
        MyContainer();
        ~MyContainer();
        void addObject(MyObject* o);

    private:
        std::vector<MyObject*>   mObjects;
};

#endif




