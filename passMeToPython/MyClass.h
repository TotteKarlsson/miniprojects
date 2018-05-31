#ifndef MyClassH
#define MyClassH
#include <string>

using std::string;
class MyClass
{
    public:
                        MyClass(const string& lbl): label(lbl) {}
                        ~MyClass(){}
        string          getLabel() {return label;}

    private:
        string          label;
};
#endif
