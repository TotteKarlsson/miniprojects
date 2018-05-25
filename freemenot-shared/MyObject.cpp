#pragma hdrstop
#include "MyObject.h"
//---------------------------------------------------------------------------
namespace dsl
{

MyObject::MyObject()
{}

MyObject::MyObject(const MyObject& /*obj*/)
{}

MyObject::~MyObject()
{}


string MyObject::getTypeName() const
{
    return "MyObject";
}

string MyObject::asString(const char& delimiter) const
{
    return "Implement asString(const char delimiter) function in derived class!";
}

const char* MyObject::c_str() const
{
    return "Implement const char* asCString(const char delimiter) function in derived class!";
}

}
