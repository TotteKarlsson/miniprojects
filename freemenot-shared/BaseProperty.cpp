#pragma hdrstop
#include "BaseProperty.h"
//---------------------------------------------------------------------------

namespace dsl
{

BaseProperty::BaseProperty()
:
mKey("<none>"),
mWasRead(false),
mIsModified(false)
{}

BaseProperty::BaseProperty(const string& lbl)
:
mKey(lbl),
mWasRead(false),
mIsModified(false)
{}

BaseProperty::~BaseProperty()
{}

const char* BaseProperty::c_str() const
{
    return "Implement c_str() in derived property!";
}

bool BaseProperty::doReadFromINI()
{
    return mDoReadFromINI;
}

bool BaseProperty::wasRead()
{
    return mWasRead;
}

bool BaseProperty::wasWritten()
{
    return mWasWritten;
}

bool BaseProperty::isModified()
{
    return mIsModified;
}

void BaseProperty::setModifiedFlag()
{
    mIsModified = true;
}

void BaseProperty::resetModifiedFlag()
{
    mIsModified = false;
}

//void* BaseProperty::getValueHandle()
//{
//    return nullptr;
//}
}
