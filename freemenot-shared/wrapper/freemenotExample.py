import freemenot as fmn

def setupProperties():
    p = fmn.Properties("My Properties Section")
    ip = fmn.intProperty(43, "Int Property")
    print(ip.getLabel())

    p.add(ip)
    return p

def getContainer():
   c = fmn.MyContainer()
   o1 = fmn.MyObjectBase("This is a label")
   o2 = fmn.MyDerived()
   o3 = fmn.intObject()

   c.add(o1)
   c.add(o2)
   c.add(o3)
   return c

##Test Properties
p = setupProperties()

print ("Properties section: " + p.getSection())
print ("Number of properties: " + str(p.count()))

ap = p.getProperty(0)

lbl = ap.getLabel()
print(lbl)



## Test simple container
##cont = getContainer()
##print ("Number of objects: " + str(cont.getNrOfObjects()))
##
##a = cont.getObject(0)
##print ("Label: " + a.getLabel())
##
##b = cont.getObject(1)
##print ("Label: " + b.getLabel())
##
##c = cont.getObject(2)
##print ("Label: " + c.getLabel())


