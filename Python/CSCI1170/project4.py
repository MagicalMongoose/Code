#project4.py
#Due 4/12/21
#Written by Drew Lickman
#CSCI 1170-003
#Description:
#Write a python script (with comments) that computes
#the average score for an unknown number of students in a file.
#Specifically, your script should:
#Ask for a filename name (that has scores in it)
#Open the scores file
#Verify the scores file opened correctly
#Read the student's name and their four scores
#Display the student's name, all of their scores and their average to the screen
#Writes the students name and the scores' average to a file name "averages.csv"
#Close both files

def main():
    done = False
    while not done:
        try:
            filename = input("Enter a filename that has scores in it ")
            #filename = "inputText.txt"
            done = True
        except:
            print("File not found")

    print("You entered", filename)
    openfile = open(filename, "r")
    print("Opened scores file", filename)
    writefile = "averages.txt"
    writefile = open(writefile, "w")

    avg = 0
    numTests = 4
    line = (openfile.readline()).rstrip("\n")
    while line != "":
        print(line, "scores:", end=" ") #Name
        writefile.write(line)
        writefile
        line = (openfile.readline()).rstrip("\n")
        for i in range(numTests):
            avg += float(line)
            print(line, end=" ") #Grade
            line = (openfile.readline()).rstrip("\n")
        avg /= numTests
        print("Average:", format(avg, ".2f"))
        writefile.write("," + str(avg) + "\n")
        avg = 0

    #Close files
    openfile.close()
    writefile.close()
main()
