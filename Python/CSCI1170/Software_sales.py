#Software_sales.py
#Due 3/14/21
#Written by Drew Lickman
#CSCI 1170-003
#Description of program: Input the number of packages purchased, then do some calculations, then output how much they got discounted, and the user's total amount to pay
#Purpose of the assignment: Practice displaying output with print function, comments, variable, reading input from keyboard, format output, if statement, and if-else statement
#Input: Keyboard input, an integer for the number of packages purchased
#Output: Text to the terminal, displays the user's discount amount, and their total purchase price

def main():
    packsBought = int(input("Enter the number of packages purchased: "))
    discountMult = 0 #Default is 0 discount

    if packsBought >= 10 and packsBought <= 19:
        discountMult = .1
    elif packsBought >= 20 and packsBought <= 49:
        discountMult = .2
    elif packsBought >= 50 and packsBought <= 99:
        discountMult = .3
    elif packsBought >= 100:
        discountMult = .4
        
    priceSubtracted = (packsBought * discountMult * 99)
    totalPrice = (packsBought * 99) - priceSubtracted

    print("Discount amount: $", format(priceSubtracted, ".2f"))
    print("Total amount: $", format(totalPrice, ".2f"))
        
main()