def main():
    done = False
    while not done:
        try:
            #filename = input("Enter a filename that has scores in it ")
            filename = "input.txt"
            done = True
        except:
            print("File not found")

    print("You entered", filename)
    openfile = open(filename, "r")
    print("Opened scores file", filename)

    studentName = [""]*3
    score = [[0]*4]*3
    line = "first line"
    avg = [0]*4

    while line != "":
        for i in range(3):
            studentName[i] = openfile.readline()
            for j in range(0,4):
                line = openfile.readline()
                score[i][j] = line
                score[i][j] = score[i][j].rstrip("\n")
                print(i, j, score[i][j]) #Prints correct values of each array index
                avg[i] += int(score[i][j])
            avg[i] = float(avg[i])/4
        break
        
    #Test inputs
    #studentName = ["Mary", "Joey", "Sally"]
    #score = [[76,89,82,100], [91,81,83,95], [92,93,90,97]]
#    for i in range(3):#studentCount):
#        for j in range(0,4): #NumOfScores
#            print("")
#            print(i, j, score[i][j], end="")

            #print(studentName[i], " scores: ", sep="", end="")
            #for j in range(4):
            #    print(score[i][j], end=" ", sep=" ")
            #print("average:", avg[i], end="")

    #Write averages to averages.txt
    openfile.close()
    writefile = "averages.txt"
    openfile = open(writefile, "w")
    for i in range(len(studentName)):
        openfile.write(studentName[i] + " " + str(avg[i]) + "\n")
main()
