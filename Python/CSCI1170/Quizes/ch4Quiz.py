for i in range(9):
    print()
    print("Question " + str(i+1) + ".")
    
    if i == 0: #Q1
        product = int(input("Input a number, which will iterate until it is 100 or more... "))
        if product <= 0:
            print("Please input a number that is greater than 0!")
        while product < 100:
            product *= 10
            print(product)

    elif i == 1: #Q2
        repeatLoop = True
        print("Please input two numbers to be added together...")
        num1 = input("Number 1: ")
        num2 = input("Number 2: ")
        Addsum = int(0)
        while repeatLoop == True:
            Addsum = int(Addsum) + int(num1) + int(num2)
            print("Sum: " + str(Addsum))
            response = input("Would you like to repeat? ")
            if response == "No" or response == "no":
                break

    elif i == 2: #Q3
        for i in range(1010):
            if i%10 == 0:
                print(i)
    
    elif i == 3: #Q4
        total = 0
        for i in range(10):
            newNumb = input("Input a number " )
            total += int(newNumb)
            print("Total: " + str(total))
            print()

    elif i == 4: #Q5
        numerator = 1
        denominator = 30
        for i in range(30):
            print(str(numerator) + "/" + str(denominator))
            numerator += 1
            denominator -= 1

    elif i == 5: #Q6
        print("x += 1")
        print("x *= 2")
        print("x /= 10")
        print("x -= 100")

    elif i == 6: #Q7
        for i in range(10): #10 lines
            print()
            for i in range(15): #15 #'s in each row
                print("#", end="")
        print()
    
    elif i == 7: #Q8
        testNum = input("Please enter a positive nonzero number... ")
        if int(testNum) > 0:
            print("Validation complete")
        else:
            print("You failed")

    elif i == 8: #Q9
        testNum = input("Please enter a number in the range of 1 through 100... ")
        if int(testNum) >= 1 and int(testNum) <= 100:
            print("You are finished!")
        else:
            print("You failed")
