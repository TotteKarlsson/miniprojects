#ifndef BasePropertyH
#define BasePropertyH
#include <string>
#include "MyObject.h"
#include "MyExporter.h"
//---------------------------------------------------------------------------

namespace dsl
{

using std::string;
using std::ostream;
class IniFile;

//Abstract class for inifile parameters
//a non template base class allow us to store derived objects,
//of any type, in a vector for example
class MyExport BaseProperty : public MyObject
{
	public:
                                                        BaseProperty();
                                                        BaseProperty(const string& lbl);
        virtual                                         ~BaseProperty();

        //Interface
        virtual string                                  getINIRecord() {return string("Setup in baseclass!");}// = 0;
//        virtual bool                                    assignValueFromString(const string& val) = 0;
        string                                      	getLabel()                                  {return mKey;}
        void                                        	setLabel(const string& lbl)                 {mKey = lbl;}
//        virtual string                                  getValueAsString() const = 0;
        virtual void*                                   getValueHandle() = 0;
//
//
//                                                        //Copy temporary value to real value
//        virtual void                                    applyModification() = 0;

        virtual const char*                             c_str() const;

        //Utilities
        bool					                        doReadFromINI();
        bool					                        wasRead();
        bool					                        wasWritten();

                                                        //Modification idea is when we are using setting forms and OK, Cancel button
        bool					                        isModified();
        void					                        resetModifiedFlag();
        void					                        setModifiedFlag();

	protected:
        bool  					                        mIsModified;
        bool  					                        mDoReadFromINI;
        bool  					                        mWasRead;
        bool  					                        mWasWritten;

        string			                                mKey;
        string					                        mComment;
        string					                        mHint;
};

}
#endif
