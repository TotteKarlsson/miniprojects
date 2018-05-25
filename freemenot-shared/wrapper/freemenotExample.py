import freemenot as fmn

def getContainer():
   c = fmn.MyContainer()
   o1 = fmn.MyObjectBase("This is a label")
   #o1.thisown = 0
   o2 = fmn.MyDerived()
   o3 = fmn.intObject()

   c.add(o1)
   c.add(o2)
   c.add(o3)
   return c

cont = getContainer()
print (cont.getNrOfObjects())

a = cont.getObject(0)
print ("Label: " + a.getLabel())

b = cont.getObject(1)
print ("Label: " + b.getLabel())

c = cont.getObject(2)
print ("Label: " + c.getLabel())


