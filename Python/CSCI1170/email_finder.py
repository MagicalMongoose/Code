#ola108.py
#due 4/20/21
#Written by Drew Lickman
#1170-003
#Description:
#Write a python script (with comments) that finds all of the valid email addresses in a specified file and writes them to another file. An email address is comprised of three parts:
#1. Username
#2. @
#3. domain name
#For the purposes of this project, a valid email address has the following:
#The username has only the following characters: a-z, A-Z, 0-9, ".", "-", and "_".
#One and only one "@"
#The domain name:
#Has only the following characters: a-z, A-Z, 0-9, ".", and "-".
#Has at least one "."
#Does not have "." as the first or last character
#Does not have two "." next to each other

#Algorithm plan:
#Ask user for input filename
#Ask user for output filename
#Split everything in the file into an array at each space
#Remove anything that doesn't have @
#Loop through each array index to search for valid email addresses
#In the loop I check for each of the email address rules
#First check domain for validity
#Then check the username for validity
#If it is a valid email, append to the output file

import sys

def main():
####################################################################################
    done = False
    while not done:
        try:
            #inputFile = input("Please enter the input filename: ")
            inputFile = "email-inputC.txt"
            if inputFile == "exit":
                print("Exiting program")
                sys.exit()
            inFile = open(inputFile, "r")
            print("You entered", inputFile)
            done = True
        except FileNotFoundError:
            print("Error, file not found, try again")

    done = False
    while not done:
        try:
            #outputFile = input("Please enter the output filename: ")
            #outputFile = "output.txt"
            outputFile = "outTest.txt"
            if outputFile == "exit":
                print("Exiting program")
                sys.exit()
            outFile = open(outputFile, "w")
            print("You entered", outputFile)
            done = True
        except FileNotFoundError:
            print("Error, file not found, try again")

####################################################################################
    #Initialize variables
    username = ""
    domain = ""
    atPos = 0
    emailCount = 0
    document = ""
    emailList = ""
    skip = False

    for line in inFile:
        document += line #Document is converted to strings
    document = document.replace("\n", " ")
    document = document.replace("\t", " ")
    document = document.split(" ") #Document is now an array seperated by spaces

    for i in document: #Check each array index
        if "@" in i: #Check each potential address
            #This loops incase the string end with multiple of these
            while i.endswith(",") or i.endswith(".") or i.endswith("<") or i.endswith(">") or \
                  i.endswith("(") or i.endswith(")") or i.endswith(";"):
                i = i.strip(",.<>();")

            atPos = i.find("@")
            username = i[0:atPos]
            domain = i[atPos+1:]

            #Does domain have two . in a row
            domainCounter = 0
            for k in domain:
                if domain[domainCounter] == "." and domain[domainCounter+1] == ".":
                    #print("       Invalid, ..")
                    skip = True
                    break
                domainCounter += 1

                #Does domain include _ or @
                if k == "_" or k == "@":
                    #print("       Invalid, no _ or @ in domain")
                    skip = True
                    break
                #Does domain start with .
                if domain[0] == ".":
                    #print("       Invalid, starts with .")
                    skip = True
                    break

            #Is username alphanumeric or .-_
            for j in username:
                if not (j.isalnum() or j == "." or j == "-" or j == "_"):
                    #print("       Invalid, not alphanumeric or .-_")
                    skip = True
                    break

            #If the email is valid, print it and write to output
            if skip == False:
                #print(emailCount+1, ": ", username, " @(", atPos, ") ", domain, sep="") #Debug printer
                emailList += i
                emailList += "\n"
                emailCount += 1
                outFile.write(i + "\n")
            skip = False

    print("")
    print(emailList)
    print("Found", emailCount, "valid email addresses")

    inFile.close()
    outFile.close()

main()
