#factorials.py
#Due 3/21/21
#Written by Drew Lickman
#Course CSCI 1170-003

#Description: 
#Write a program that lets the user enter a nonnegative integer 
#then use a loop to calculate the factorial of that number. Display the factorial. 
#You need to implement your program by using both
#for loop and while loop “You will calculate the factorial twice.”

#Purpose:
#Practice Displaying Output with print Function, Comments, 
#Variable, Reading Input from the Keyboard, format output, 
#and loop structure.

#Input: Keyboard input of a positive integer

#Output: Screen output of the factorial of the input

def main():
   
    while True:
        try: num = int(input("Enter a positive integer value to calculate the factorial: "))
        except ValueError:
            print("Error, enter a positive integer")
            continue
        if num < 0:
            print("Error, enter a positive integer")
            continue
        else:
            break
           
    
    forTotal = 1
    for i in range(1, num+1):
        forTotal *= i
    print("The factorial value using for loop is equal to", forTotal)
    
    whileTotal = 1
    mult = 1
    while mult <= num:
        whileTotal *= mult
        mult += 1
    print("The factorial value using while loop is equal to", whileTotal)
    
main()