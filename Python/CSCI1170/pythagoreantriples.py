#pythagoreantriples.py
#Due 3/21/21
#Written by Drew Lickman
#Course CSCI 1170-003

#Description: 
#A right triangle can have sides that are all integers. 
#A set of three integer values for the sides of a right triangle is called a Pythagorean triple.
#These three sides must satisfy the relationship that the sum of the squares of two of the sides is equal to the hypotenuse square.
#Find all Pythagorean triples for side1, side2, and the hypotenuse, all no larger than 100. Use a triple-nested for loop that tries all possibilities.
#This is an example of “brute force computing. Test your program first with a lower number, such as 30. 
#Write your program so it will not show or count duplicate, such as (3 4 5 and 4 3 5). It should appear once and count as one.

#Purpose:
#Practice Displaying Output with print Function, Comments, 
#Variable, Reading Input from the Keyboard, format output, 
#and loop structure.

#Input: None

#Output: Screen output of the pythatorean triples

def main():
    total = 0
    
    print("  Hyp   Side1   Side2")
    
    for h in range(1, 30):
        for a in range(1, h):
            for b in range(1, a):
                if ((h**2) == ((a**2) + (b**2))):
                    print(format(h, "5d"), format(b, "5d"), format(a, "5d"))
                    total += 1
        
    print("Total number of triples are", total)    
                
main()