def displayTable(pop, percInc, days):
    def printLine():
        print("----------------------------")
        
    printLine()
    print("|Day approximate", end="")
    print("|", end="")
    print("Population|")
    printLine()
    
    
    for i in range(1, days+1):
        print("|", end="")
        print(i, end="")
        if i < 10:
            print("              |", end="")
        else:
            print("             |", end="")
        print(format(pop, "10,.7f"), end="")    
        print("|")
        pop *= (1+(percInc/100))
        printLine()

def main(): 
    population = int(input("Starting number of organisms: "))
    percentIncrease = float(input("Average daily increase: "))
    numDays = int(input("Number of days to multiply: "))
    
    displayTable(population, percentIncrease, numDays)
    
    
main()