import random
#1-7 = one dark, 8 = two dark
#9 = one light, 10-12 = two light\
darkCount = 0
darkTotal = 0
lightCount = 0
lightTotal = 0
for i in range(1000000):
    outcome = random.randint(1,12)
    if outcome == 1 or outcome == 2 or outcome == 3 or outcome == 4 or outcome == 5 or outcome == 6 or outcome == 7:
        darkCount += 1
        darkTotal += 1
    elif outcome == 8:
        darkCount += 1
        darkTotal += 2
    elif outcome == 9:
        lightCount += 1
        lightTotal += 1
    elif outcome == 10 or outcome == 11 or outcome == 12:
        lightCount += 1
        lightTotal += 2

print("How many times it rolled 1-8:", darkCount)
print("How many total darks it totals:", darkTotal)
print("")
print("How many times it rolled 9-12:", lightCount)
print("How many total lights it totals:", lightTotal)
print("")
total = darkTotal + lightTotal
print("Overall balance:", format(darkTotal/total, ".2f"), "% darks and", format(lightTotal/total, ".2f"), "% lights")