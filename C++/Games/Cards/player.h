#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
using namespace std;

class Player
{
    private:
        string playerName;
        vector<Card> hand;
        int money = 10;
        int bet = 0;
        bool currentlyPlaying = true;
    public:
        Player(string n)
        {playerName = n;};

        string printPlayerName()
        {return playerName;};
        
        string getPlayerName()
        {return playerName;};

        int getHandSize()
        {return hand.size();};

        const int getBet()
        {return bet;};

        const int getMoney()
        {return money;};

        void addToBet(int num)
        {
            if (num > bet && num <= money && num > 0)
            {
                bet += num;
                money -= bet;
            }
        }

        void setPlaying(bool b)
        {
            currentlyPlaying = b;
        };

        bool isPlaying()
        {
            return currentlyPlaying;
        };

        void drawCard(Card c)
        {
            hand.push_back(c);
            sort(hand.begin(), hand.end(),
            [](Card & a, Card & b) -> bool
            {
                return a.getValue() > b.getValue();
            });
        };

        int handType()
        {
            //Returns an int so that hands can be numerically valued and compared
            bool four = false;
            bool fullHouse = false;
            bool flush = true;
            bool straight = false;
            int straightCount = 1;
            bool triple = false;
            int tripleValue = 0;
            bool twoPair = false;
            int pairCount = 0;
            bool pair = false;
            int pairValue = 0;
            int output = 0;

            //Flush checker
            for (int f = 1; f < hand.size(); f++)
            {
                if (hand[f].getSuit() != hand[0].getSuit())
                {
                    flush = false;
                }
            }

            //Straight checker
            for (int s = 1; s < hand.size(); s++)
            {
                if (hand[s].getValue() == hand[s-1].getValue()-1)
                {
                    straightCount++;
                }
            }
            if (straightCount == 5)
            {straight = true;}


            //Four checker
            if (hand[1].getValue() == hand[3].getValue())
            {
                if (hand[0].getValue() == hand[2].getValue() 
                || hand[2].getValue() == hand[4].getValue())
                {
                    four = true;
                    if (pairValue == 0)
                    {pairValue = hand[2].getValue();}}
            }

            //Three of a Kind checker
            if (four == false)
            {
                if (hand[0].getValue() == hand[2].getValue() 
                || hand[2].getValue() == hand[4].getValue())
                {
                    triple = true;
                    tripleValue = hand[2].getValue();
                }
                else if (hand[1].getValue() == hand[3].getValue())
                {
                    {
                    triple = true;
                    tripleValue = hand[1].getValue();
                }
                }
                
            }

            //Pair checker
            //p is the base card
            //pp is the card that is checked against p to see if they are pairs
            if (four == false)
            {
                for (int p = 0; p < hand.size()-1; p++)
                {
                    for (int pp = p+1; pp < hand.size(); pp++)
                    {
                        if (hand[p].getValue() == hand[pp].getValue() && hand[pp].getValue() != tripleValue)
                        {
                            if (pairValue == 0)
                            {pairValue = hand[p].getValue();}
                            pair = true;
                            pairCount++;
                            if (pairCount == 2)
                            {
                                twoPair = true;
                            }
                        }
                    }
                }
            }
            
            //Full House checker
            if (triple && pair)
            {
                if (tripleValue != pairValue)
                {fullHouse = true;}
            }

            //handType logic
            if (hand[0].getValue() == 14 && straight && flush) 
            {output = 9;}
            else if (straight && flush) 
            {output = 8;}
            else if (four)
            {output = 7;}
            else if (fullHouse) 
            {output = 6;}
            else if (flush) 
            {output = 5;}
            else if (straight) 
            {output = 4;}
            else if (triple) 
            {output = 3;}
            else if (twoPair) 
            {output = 2;}
            else if (pair) 
            {output = 1;}
            else       
            {output = 0;}

            /*
            cout << endl << "four: " << four << " " << "fH: " << fullHouse << " " << "flush: " << flush;
            cout << endl << "straight: " << straight << " " << "triple: " << triple <<  " " << "twoPair: " << twoPair;
            cout << endl << "pair: " << pair << " " << "pairValue: " << pairValue << " " << "output: " << output << endl;
            */

            return output;
        };

        static string handTypeIntToStr(int num)
        {
            if (num == 0)
            {
                return "High Card";
            }
            else if (num == 1)
            {
                return "Pair";
            }
            else if (num == 2)
            {
                return "Two Pair";
            }
            else if (num == 3)
            {
                return "Three of a Kind";
            }
            else if (num == 4)
            {
                return "Straight";
            }
            else if (num == 5)
            {
                return "Flush";
            }
            else if (num == 6)
            {
                return "Full House";
            }
            else if (num == 7)
            {
                return "Four of a Kind";
            }
            else if (num == 8)
            {
                return "Straight Flush";
            }
            else if (num == 9)
            {
                return "**ROYAL FLUSH**";
            }
            else
            {
                return "undefined";
            }
        }

        void displayHand()
        {
            for (int i = 0; i < hand.size(); i++)
            {
                cout << hand[i].printCard();
            }
            if (hand.size() == 5)
            {
                cout << " (";
                cout << handTypeIntToStr(handType());
                cout << ")";
            }
        };

        void fold()
        {
            setPlaying(false);
        };


        
};

#endif