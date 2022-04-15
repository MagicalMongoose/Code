#To future Drew, try to convert this to use an array instead of calculating as it goes

#exercise9p7.py
#Written by Drew Lickman
#Due 3/17/21
#Problem:
#1. Read an integer value between 2 and 20 and store the value as upper.
#2. Using a nested-loop print the multiplication table from 2 to the upper value.
#3. Using a loop print the heading as shown below.

def multTable(uprBound):
    width = uprBound * 2
    if width >= 100:
        width = 100
    height = uprBound

    #Print the top part of the output
    for i in range(width):
        print("--", end="")
    print("") #newline

    for i in range(uprBound):
        if not (i >= 2 and i <= uprBound):
            print(" ", end=" ") #give room for the far left column
        else:
            if (i >= 10):
                print(i, "", end=" ")
            else:
                print(i, " ", end=" ")
    print("") #newline

    for i in range(width):
        print("--", end="")
    print("") #newline

    #Now print the actual table
    for i in range(2, height): #vertical
        #print left column
        if i < 10:
            print(i, "| ", end="")
        elif i >= 10:
            print(i, "| ", sep="", end="")

        #print all products in each row
        for j in range(2, uprBound): #horizontal
            print(i*j, end="")
            for k in range(1):
                print(" ", end="")

            for c in range(3): #3 is for 3 digits
                if len(str(i*j)) == c:
                    for d in range(3 - c):
                        print(" ", end="")
        print("") #newline

def main():
    uprBound = 20 #default
    try:
        uprBound = int(input("What is the upper bound of your multiplication table? "))
    except ValueError:
        print("The upper bound must be a positive integer")
        main()
    print("The multiplication table for 2 to ", uprBound, ":", sep="")
    multTable(uprBound+1)
main()
