import random

def main():
    #deck = [[x, y] for x in range (4) for y in range(13)]
    hearts = [["Heart", x] for x in range(1, 14)]
    clubs = [["Club", x] for x in range(1, 14)]
    diamonds = [["Diamond", x] for x in range(1, 14)]
    spades = [["Spade", x] for x in range(1, 14)]
    deck = hearts + clubs + diamonds + spades
    print("")
    #print(deck)
    
    #Turn 11-13 and 1 into Jack-ace
    #Detect two of a kind, three of a kind, flush, straight, etc.
    randomCards = []
    for i in range(5):
        randomCards.append(random.randint(0,51))
        print(randomCards)
        randomCards[i] = deck[randomCards[i]] 
    print(randomCards)
main()