print("Number of grapevines in the vineyard calculator! Please input the following...")
R = int(input("The length of the row, in feet: "))
E = int(input("The amount of space used by an end-post assembly, in feet: "))
S = int(input("The amount of space between the vines, in feet: "))
V = ( (R - (2*E)) / S )
print("The number of grapevines that will fit in the row are", V)