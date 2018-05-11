#include "freemenot.h"

#include <iostream>
using namespace std;
MyObject::MyObject()
{
	cout<<"In object ctor"<<endl;
}

MyObject::~MyObject()
{
	cout<<"In object dtor"<<endl;
}

MyContainer::MyContainer()
{
	cout<<"In container ctor"<<endl;
}

MyContainer::~MyContainer()
{
    cout<<"In container dtor"<<endl;
    for(int i = 0; i < mObjects.size(); i++)
    {
        delete mObjects[i];
    }
}

void MyContainer::addObject(MyObject* o)
{
    mObjects.push_back(o);
}


