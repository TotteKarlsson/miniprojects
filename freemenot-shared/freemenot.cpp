#include "freemenot.h"
#include <iostream>
using namespace std;

namespace mine
{

/* MyObjectBase source */
MyObjectBase::MyObjectBase(const string& lbl)
:
label(lbl)
{
    cout<<"In object ctor"<<endl;
}

MyObjectBase::~MyObjectBase()
{
    cout<<"In object dtor"<<endl;
}

string MyObjectBase::getLabel()
{
    return label;
}

/* MyContainer source */
MyContainer::MyContainer() { cout<<"In container ctor"<<endl; }

MyContainer::~MyContainer()
{
    cout<<"In container dtor"<<endl;
    for(unsigned int i = 0; i < mObjects.size(); i++)
    {
        delete mObjects[i];
    }
}

int MyContainer::getNrOfObjects()
{
    return mObjects.size();
}

void MyContainer::add(MyObjectBase* o)
{
    mObjects.push_back(o);
}

MyObjectBase* MyContainer::getObject(unsigned int i)
{
    return mObjects[i];
}

}
