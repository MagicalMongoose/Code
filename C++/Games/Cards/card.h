#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
    private:
        int value; //2-14
        int suit; //1-4
    public:
        //Constructor
        Card(int val, int sui)
        {
            value = val;
            suit = sui;
        };
        
        int getValue()
        {
            return value;
        };

        int getSuit()
        {
            return suit;
        };

        //Convert 11-14 to JQKA for printing
        string valToStr(int num)
        {
            if (num == 10)
            {
                return "X";
            }
            else if (num == 11)
            {
                return "J";
            }
            else if (num == 12)
            {
                return "Q";
            }
            else if (num == 13)
            {
                return "K";
            }
            else if (num == 14)
            {
                return "A";
            }
            else
            {
                return to_string(num);
            }
        };

        //Convert 1-4 to ♥♦♣♠ for printing
        string suitToStr(int num)
        {
            if (num == 1)
            {
                return "H";
            }
            else if (num == 2)
            {
                return "D";
            }
            else if (num == 3)
            {
                return "C";
            }
            else if (num == 4)
            {
                return "S";
            }
            else return "";
        };

        string printCard()
        {
            return "[" + valToStr(value) + suitToStr(suit) + "]";
        };

        //Need to make ostream friend print also!

        bool operator< (const Card & rhs) const
        {
            return this->value < rhs.value;
        };

        bool operator<=(const Card & rhs) const
        {
            return this->value <= rhs.value;
        };

        bool operator>(const Card & rhs) const
        {
            return this->value > rhs.value;
        };

        bool operator>=(const Card & rhs) const
        {
            return this->value >= rhs.value;
        };

        bool operator==(const Card & rhs) const
        {
            return this->value == rhs.value;
        };

        bool operator!=(const Card & rhs) const
        {
            return this->value != rhs.value;
        };

};
#endif