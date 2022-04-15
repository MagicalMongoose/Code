def getNumber():
    while True:
        num = 0
        
        try:
            num = float(input("Enter a number between 1 and 100 "))
        except ValueError:
            print("Error, that is not a number between 1 and 100")
            continue
        if num <= 0 or num > 100:
            print("Error, that is not a number between 1 and 100")
            continue
        else:
            break
    return num

def main():
    num = getNumber()
    print(num, "is a number between 1 and 100!")
        
main()