#Time_calculator.py
#Due 3/14/21
#Written by Drew Lickman
#CSCI 1170-003
#Description of program: Input the number of seconds, do some calculations, then output days, hours, minutes, and seconds
#Purpose of the assignment: Practice displaying output with print function, comments, variable, reading input from keyboard, format output, if statement, and if-else statement
#Input: Keyboard input, an integer for the number of seconds
#Output: Text to the terminal, displays the number of days, hours, minutes, and seconds

def main():
    numSeconds = 0
    try:
        numSeconds = int(input("Enter the number of seconds: "))
    except ValueError:
        print("Please enter a positive integer")
        main()
    if numSeconds == 0:
        print("Please enter a positive integer")
        main()
            
    numMin = 0 
    numHr = 0
    numDay = 0

    if numSeconds >= 86400: #86400 seconds in a day
        numDay = numSeconds // 86400
        numSeconds = numSeconds % 86400
    if numSeconds >= 3600: #3600 seconds in an hour
        numHr = numSeconds // 3600
        numSeconds = numSeconds % 3600
    if numSeconds >= 60: #60 seconds in a minute
        numMin = numSeconds // 60
        numSeconds = numSeconds % 60
        
    if numSeconds > 0 or numMin > 0 or numHr > 0 or numDay > 0:
        if numSeconds < 2 and numMin < 2 and numHr < 2 and numDay < 2:
            print("There is ", end="")
        else:
            print("There are ", end="")

    if numDay > 0:
        if numDay > 1:
            print(numDay, "days, ", end="")
        else:
            print(numDay, "day, ", end="")
        
    if numHr > 0:
        if numHr > 1:
            print(numHr, "hours, ", end="")
        else:
            print(numHr, "hour, ", end="")   
        
    if numMin > 0:
        if numMin > 1:
            print(numMin, "minutes, ", end="")
        else:
            print(numMin, "minute, ", end="")  
        
    if ((numMin > 0 or numHr > 0 or numDay > 0) and numSeconds > 0):
        print("and ", end="")
        
    if numSeconds > 0:
        if numSeconds > 1:
            print(numSeconds, "seconds", end="")
        else:
            print(numSeconds, "second", end="")  
main()