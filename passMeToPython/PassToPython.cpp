#include "Python.h"
#include <iostream>
#include <sstream>
#include "MyClass.h"
#include "swigpyrun.h"
using namespace std;

int main()
{
    MyClass obj("Made in C++");
    cout << "Object label: \"" << obj.getLabel() << "\"" << endl;

    //Now setup the Python interperter and call the execute function in the
    //demo python script
	Py_Initialize();

    //Load python Demo script, "passmetopythonDemo.py"
    string PyModule("passmetopythonDemo");
    PyObject* pm = PyUnicode_DecodeFSDefault(PyModule.c_str());

	PyRun_SimpleString("import sys");
    stringstream cmd;
    cmd << "sys.path.append(\"" << "." << "\")";
	PyRun_SimpleString(cmd.str().c_str());
    PyObject* PyModuleP = PyImport_Import(pm);
    Py_DECREF(pm);

    //Now create PyObjects for the Python functions that we want to call
    PyObject* pFunc1 = PyObject_GetAttrString(PyModuleP, "getMyClassObject");
    if(pFunc1)
    {
        //Execute function(s)
        PyObject *pReturnValue = PyObject_CallObject(pFunc1, NULL);

        //This value contains a pointer to a MyClass object, unwrap it
        PyObject* pThis = PyObject_GetAttrString(pReturnValue, "this");
        unsigned long addr = PyLong_AsLong(pThis);
        MyClass* myClass = (MyClass*)(addr);
        if(myClass)
        {
            cout << "Label for MyClass object fetched from Python: " << myClass->getLabel();
        }
    }

    //Call a Python function taking an integer as an argument:
    PyObject* pFunc2 = PyObject_GetAttrString(PyModuleP, "executeInt");
    if(pFunc2)
    {
        //Setup argument
        PyObject* pArgs = PyTuple_New(1);
        int test(35);

        //Construct a PyObject* from long
        PyObject* pValue = PyLong_FromLong(test);

        /* pValue reference stolen here: */
        PyTuple_SetItem(pArgs, 0, pValue);

        /***** Calling python here *****/
        cout<<endl<<"Calling function with an integer argument\n\n";
        PyObject* res = PyObject_CallObject(pFunc2, pArgs);
        if(!res)
        {
            cerr << "Failed calling function..";
        }
    }

    PyObject* pFunc3 = PyObject_GetAttrString(PyModuleP, "execute");
    if(pFunc3)
    {
        //Setup argument
        PyObject* pArgs = PyTuple_New(1);

        //Construct a PyObject* from long
        PyObject* pObj(NULL);

        //THIS QUESTION IS ABOUT HOW TO DO THIS
        pObj = SWIG_NewPointerObj((void*)&obj, SWIG_TypeQuery("_p_MyClass"),  0 );

		//pObj = Py_BuildValue("O", obj);
        /* pValue reference stolen here: */
        PyTuple_SetItem(pArgs, 0, pObj);

        /***** Calling python here *****/
        cout<<endl<<"Calling function with an MyClass argument\n\n";
        PyObject* res = PyObject_CallObject(pFunc3, pArgs);
        if(!res)
        {
            cerr << "Failed calling function..";
        }
    }

    Py_Finalize();
	return 0;
}

#pragma comment(lib, "Python37_CG.lib")
