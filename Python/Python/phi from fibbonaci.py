a = 0
b = 1
c = 0

for i in range(100):
    c = a + b
    a = b
    b = c
    #print(c) #this is the fibbonaci printer
    print("Fibbonaci:", c, "--> Phi:", b/a) #this is the phi printer
    