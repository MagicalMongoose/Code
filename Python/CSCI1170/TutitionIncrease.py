def main():
    tuition = 8000
    increatePercent = 1.03 #multiplier
    numYears = 5

    for i in range(numYears):
        tuition *= increatePercent
    print("$", format(tuition, ",.2f"), sep="")
main()