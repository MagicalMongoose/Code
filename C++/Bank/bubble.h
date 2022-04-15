#ifndef BUBBLE_H
#define BUBBLE_H
#include <iostream>
#include <string>
using namespace std;
class Bubble
{
    private:
        double value = 0;
        string title = "";
    public:
        friend class account;
        //Bubble Constructor
        Bubble(string name)
        {
            title = name;
            //cout << name << " bubble\n";
        }
        void displayInfo()
        {
            cout << "\t" << title << " bubble: ";
            cout << "$" << value << endl;
        }
        void deposit(double money)
        {
            value += money;
        }
};

#endif