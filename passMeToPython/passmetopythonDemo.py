import passmetopython as pmtp

def getMyClassObject():
    print ("Printing from within python fucntin getMyClassObject()")
    c = pmtp.MyClass("From Python")
    return c

def executeInt(obj):
    #This function is to be called from C/C++, with an
    #integer object as an argument
    print ("Printing from within python execute function. Integer passed: " + str(obj) )
    return True

def execute(obj):
    #This function is to be called from C/C++, with a
    #MyClass object as an argument
    print ("Entering execute function")
    lbl = obj.getLabel();
    print ("Printing from within python execute function. Object label is: " + lbl)
    return True

def main():
    c = pmtp.MyClass("Test 1")
    retValue = execute(c)
    print("Return value: " + str(retValue))
    print (getMyClassObject().getLabel())
    print (executeInt(45))


#Test function from within python
if __name__ == '__main__':
    main()
