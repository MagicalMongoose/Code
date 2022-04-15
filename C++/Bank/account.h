#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include "bubble.h"
using namespace std;
class Account
{
    private:
        string type = "";
        Bubble unallocated = Bubble("unallocated");
        int accountAge = 0;
    public:
        friend class user; //taught from MooseJuuice
        //default account Constructor
        Account()
        {

        }
        //overloaded account Constructor
        Account(string name)
        {
            type = name; //Checkings or Savings
        }

        void newBubble(string name)
        {
            //create a new bubble
        }
        void displayInfo()
        { //make a loop that shows all bubble values
            cout << type << " account: " << endl;
            unallocated.Bubble::displayInfo();
        }
        void deposit(double money)
        {
            unallocated.Bubble::deposit(money);
        }
};

#endif