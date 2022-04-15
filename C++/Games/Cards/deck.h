#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "card.h"
using namespace std;

class Deck
{
    private:
        int deckSize = 52;
        vector<Card> deck;
    public:
        //Default Constructor
        Deck()
        {
            for (int s = 1; s <= 4; s++)
            {
                for (int v = 2; v <= 14; v++)
                {
                    Card newCard(v, s);
                    deck.push_back(newCard);
                }
            }
        };

        void printDeck()
        {
            cout << "Current Deck:\n";
            for (int i = 0; i < deckSize; i++)
            {
                if (i % 13 == 0 && i != 0)
                {cout << endl;}
                cout << deck[i].printCard();
            }
            cout << endl;
        };

        int getSize()
        {
            return deckSize;
        };

        void shuffle()
        {   
            std::shuffle(deck.begin(), deck.end(), std::random_device());
        };

        Card drawFromDeck()
        {
            Card drawnCard = deck.back();
            deck.pop_back();
            deckSize--;
            return drawnCard;
        };
};

#endif