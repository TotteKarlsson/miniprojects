import passmetopython as pmtp

def execute(o):
    #This function is to be called from C/C++, with a
    #MyClass object pointer as an argument
    lbl = o.getLabel();
    print ("Printing from within python execute function. Object label is: " + lbl)
    return True

#Test function from within python
c = pmtp.MyClass("Test 1")
retValue = execute(c)
print("Return value: " + str(retValue))

