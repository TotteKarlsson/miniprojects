import freemenot as fmn

def getContainer():
   c = fmn.MyContainer()
   o1 = fmn.MyObject("This is a label")
   #o1.thisown = 0
   c.addObject(o1)
   return c

c = getContainer()
print (c.getNrOfObjects())

#if the thisown flag for objects in the getContainer function
#is equal to 1, the following call return an undefined object
#If the flag is equal to 0, the following call will return a valid object
a = c.getObject(0)
print ("Label: " + a.getLabel())


