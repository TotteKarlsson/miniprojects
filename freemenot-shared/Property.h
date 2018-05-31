#ifndef dslPropertyH
#define dslPropertyH
#include <string>
#include "MyObject.h"
#include "MyExporter.h"
#include "BaseProperty.h"
//---------------------------------------------------------------------------

namespace dsl
{

using std::string;
using std::ostream;
template <class T>
class Property : public BaseProperty
{
    public:
                                                    Property(const T& value, const string& lbl = gNoneString);
                                                    ~Property(){}
		void                                        setDefaultValue(const T& val)               {mDefaultValue = val;}
		T	                                        getDefaultValue()      				        {return mDefaultValue;}
        void                                        setValue(const T& val)                      {*mValue = val;}
        void                                        setTemporaryValue(const T& val)             {mTemporaryValue = val;}
        void                                        setComment(const string& val)               {mComment = val;}
        void                                        resetToDefault()                            {*mValue = mDefaultValue;}
        virtual string                              getTypeName() const;
        T                                           getValue() const                            {return (T) (*mValue);}

        string                                      getComment()                                {return mComment;}

        void*                                       getValueHandle()                            {return mValue;}
        T&                                          getReference()                              {return *mValue;}
        T&                                          getTempValueReference()                     {return mTemporaryValue;}
        void                                        setReference(T* reference)                  {mValue = reference;}

                                                    operator T() const;
//                                                    operator T&();
        T                                           operator+(const T& a);
        void                                        operator+=(const T& val);
//        T&                                          operator=(const T& a);

        bool                                        operator==(const T& val)                    {return (*mValue) == val;}

//        friend                                      std::ostream& operator<<(ostream& stream, const Property<T>& val)
//                                                    {
//                                                        stream << val.getValueAsString();
//                                                        return stream;
//                                                    }


//        string                                      getFormattedStr()                           {return getFormattedParStr(mKey, getValue());}

        const char*                                 c_str() const;

                                                    //The setup function return a reference to the object.
                                                    //The reference allow catching the object immediately after the object is setup.
        Property<T>&                                setup(const string& lbl, const T& val, bool readIt = true)
                                                    {
                                                        mKey = lbl;
                                                        setValue(val);
                                                        mDefaultValue = val;
                                                        mDoReadFromINI = readIt;
                                                        return *this;
                                                    }


        bool                                        assignValueFromString(const string& val);
        void                                        applyModification();

    protected:
        T                                           mDefaultValue;
        T                                           mDummyValue;
        T                                           mTemporaryValue;
        T*                                          mValue;
                                                    //Initially the mValue points to DummyValue
                                                    //However, the value can be set to point to
                                                    //another variable by using the function setReference
                                                    //and set back to setReferenceToDummy
};

template <class T>
Property<T>::Property(const T& value, const string& lbl)
:
BaseProperty(lbl)
{
    mDummyValue = value;
    mValue = &mDummyValue;
}

template<class T>
void Property<T>::applyModification()
{
    (*mValue) = mTemporaryValue;
    mIsModified = false;
}

template<class T>
const char* Property<T>::c_str() const
{
    string tmp("NONO");// = getValueAsString();
    return tmp.c_str();
}

template<class T>
T Property<T>::operator+(const T& addMe)
{
    T newVal = (*mValue) + addMe;
    return newVal;
}

template<class T>
void Property<T>::operator += (const T& val)
{
    (*mValue) += (T) val;
}

//template<class T>
//string Property<T>::getValueAsString() const
//{
//    T val = getValue();
//    return dsl::toString(val);
//}
//
//
//template<class T> inline
//string Property<T>::getINIRecord()
//{
//    return string(mKey + "=" + dsl::toString((T) getValue()));
//}

//template<class T>
//T& Property<T>::operator=(const T& rhs)
//{
//    (*mValue) = rhs;
//    return (*mValue);
//}

//======================== SPECIALIZATIONS
//------------- bool
template<> inline
string Property<bool>::getTypeName() const
{
    return "bool";
}

template<> inline
Property<bool>::operator bool() const
{
    return (*mValue);
}

template<> inline
void* Property<bool>::getValueHandle()
{
    return (void*) mValue;
}

template<> inline
bool Property<bool>::operator+(const bool& addMe)
{
    bool newVal = (*mValue) | addMe;
    return newVal;
}

template<> inline
void Property<bool>::operator += (const bool& val)
{
    (*mValue) = (*mValue) | val;
}


//------------- int -----------------------------------------
template<> inline
string Property<int>::getTypeName() const
{
    return "int";
}

template<>
inline Property<int>::operator int () const
{
    return (*mValue);
}

//template<>
//inline Property<int>::operator int & ()
//{
//    return (*mValue);
//}

template<> inline
bool Property<int>::assignValueFromString(const string& val)
{
    return true;
}

//------------- double -----------------------------------------
template<> inline
string Property<double>::getTypeName() const
{
    return "double";
}

template<>
inline Property<double>::operator double () const
{
    return (*mValue);
}

//template<>
//inline Property<double>::operator double & ()
//{
//    return (*mValue);
//}

template<> inline
bool Property<double>::assignValueFromString(const string& val)
{

    return true;
}

//------------- string -----------------------------------------
//template<> inline
//Property<string>::Property() : mDummyValue("")                    {mValue = &mDummyValue;}
//template<> inline
//Property<string>::Property(const string& lbl, const string& val)
//:
//mDummyValue(val)
//{
//    mValue = &mDummyValue;
//}


template<> inline
string Property<string>::getTypeName() const
{
    return "string";
}

template<> inline
Property<string>::operator string() const
{
    return *mValue;
}

template<> inline
const char* Property<string>::c_str() const
{
    return mValue->c_str();
}

template<> inline
bool Property<string>::assignValueFromString(const string& val)
{
    setValue(val);
    return true;
}
}
#endif

