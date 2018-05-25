#pragma hdrstop
#include <sstream>
#include <iomanip>
#include "Properties.h"
//---------------------------------------------------------------------------

namespace dsl
{

string toString(const Properties& props)
{
    return gEmptyString;
}

string getFormattedParStr(const string& str, const Properties& props)
{
    return gEmptyString;
}

Properties::Properties(const string& regSubSection)
:
mSection(regSubSection)
{}

Properties::~Properties()
{
    mProperties.clear();
}

string Properties::getSection()
{
    return mSection;
}

void Properties::applyModifications()
{
    for(unsigned int i = 0; i < count(); i++)
    {
        if(mProperties[i]->isModified())
        {
            mProperties[i]->applyModification();
        }
    }
}

bool Properties::isModified()
{
    for(unsigned int i = 0; i < count(); i++)
    {
        if(mProperties[i]->isModified())
        {
            return true;
        }
    }
    return false;
}

void Properties::setUnmodified()
{
    for(unsigned int i = 0; i < count(); i++)
    {
        mProperties[i]->resetModifiedFlag();
    }
}

BaseProperty* Properties::operator [](const string& label)
{
    //Search trough parameters for label
    for(unsigned int i = 0; i < count(); i++)
    {
        if(mProperties[i]->getLabel() == label)
        {
            return mProperties[i];
        }
    }
    return nullptr;
}

BaseProperty* Properties::getProperty(const string& label)
{
    //find parameter usign its label
    for(unsigned int i = 0; i < count(); i++)
    {
        if(mProperties[i]->getLabel() == label)
        {
            return mProperties[i];
        }
    }
    return nullptr;
}

string Properties::getListing()
{
    stringstream paras_list;
    for(unsigned int i = 0; i < count(); i++)
    {
        paras_list << setw(30)<<mProperties[i]->getLabel()<<"="<<mProperties[i]->getValueAsString()<<endl;
    }
    return paras_list.str();
}

bool Properties::read()
{
    return false;
}

bool Properties::write()
{
    return false;
}

unsigned int Properties::count()
{
	return mProperties.size();
}

BaseProperty* Properties::operator [](int index)
{
	return mProperties[index];
}

void Properties::setSection(const string& sec)
{
    mSection = sec;
}

BaseProperty* Properties::getProperty(int index)
{
	return mProperties[index];
}

void Properties::add(BaseProperty* para)
{
    mProperties.push_back(para);
}

void Properties::setupProperties()
{}

ostream&  operator<<(ostream& stream, const Properties& p)
{
	return stream;
}

}

