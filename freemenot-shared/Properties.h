#ifndef PropertiesH
#define PropertiesH
#include <vector>
#include <string>
#include "MyExporter.h"
#include "Property.h"
#include "MyObject.h"
//---------------------------------------------------------------------------

namespace dsl
{

using std::vector;
using std::string;

//Properties is a container for a group of properties
//See also INIFileProperties and Registry properties
class MyExport Properties : public MyObject
{
	public:

                                                            Properties(const string& iniSection = dsl::gEmptyString);
        virtual                                             ~Properties();

        void                                                setSection(const string& sec);
        string                                              getSection();
        unsigned int                                        count();

//        BaseProperty*				                        operator [](int index);
//        BaseProperty*				                        operator [](const string& label);

        BaseProperty*				                        getProperty(int index);
//        BaseProperty*				                        getProperty(const string& paraLabel);

        void                                                add(dsl::BaseProperty* o);
//        string                                              getListing();

        virtual bool                                        read();
        virtual bool                                        write();

        bool                                                isModified();
        void                                                setUnmodified();
//        void                                                applyModifications();
		MyExport friend ostream&                          operator<<(ostream& stream, const Properties& p);

    protected:
        vector<BaseProperty*>     	                        mProperties;
        string                       	                    mSection;

                                                            //Implement in derived classes
        virtual void                                        setupProperties();
};

MyExport string toString(const Properties& props);

MyExport string getFormattedParStr(const string& str, const Properties& props);


template<> inline
bool Property<Properties>::assignValueFromString(const string& val)
{
    return false;
}

template<> inline
string Property<Properties>::getTypeName() const
{
    return "properties";
}

}
#endif
