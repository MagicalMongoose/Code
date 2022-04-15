/*
Title: Breakfast Self Service System
Author: Drew Lickman
Professor: Dr. Yang
Class CSCI 2170 - 001
Due: Sep 17th, 2021 23:59 PM (Friday)
Description:
    User will select a food item from the menu and
    this program will calculate the total cost.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getFoodPrice(int n)
    {
        switch (n)
        {
        case 0://"Egg McMuffin"
            return 2.99;
        case 1://"Sausage Buritto"
            return 4.99;
        case 2://"Fruit Yogurt Parfait"
            return 3.56;
        case 3://"Hash Brown"
            return 1.50;    
        default:
            return 0.00;
        }

        return 0.00;
    }

int main()
{
    //Set up variables
    int userChoice;
    int userQuantity;
    int menuSize = 4;
    const string menu[menuSize] =
    {
        "Egg McMuffin",
        "Sausage Buritto", 
        "Fruit Yogurt Parfait",
        "Hash Brown",
    };

    cout << "=====================================\n";
    cout << "Welcome to MTSU's Breakfast Menu\n";
    cout << "=====================================\n";

    cout << setprecision(2) << fixed;
    //I made 0 to be Quit so that if the menu is for example 30 items long, the user isn't told to quit by typing "31"
    cout << left << "0. Quit\n";
    for (int i = 0; i < menuSize; i++)
    {
        //Prints a loop that uses an array of strings for foodNames, and a switch case for foodPrice, to show data can be retrieved in both methods.
        cout << left << i+1 << ". " << setw(25) << menu[i] << setw(2) << right << "($" << getFoodPrice(i) << ")" << endl;
    }
    //Guide the user through the menu. They can only select one food type.
    cout << "Please select your choice:\n";
    cin >> userChoice;
    if (userChoice > 0 && userChoice < 5)
    {
        cout << "The unit price for " << menu[userChoice-1] << " is: $" << getFoodPrice(userChoice-1) << endl;
        cout << "Please enter the quantity:\n";
        cin >> userQuantity;
        cout << "=====================================\n";
        cout << "Your Order Information:\n";
        cout << "-------------------------------------\n";
        cout << menu[userChoice-1] << ": $" << getFoodPrice(userChoice-1) << " (Unit:" << userQuantity << ")\n";
        cout << "-------------------------------------\n";
        cout << "Total Price: $" << getFoodPrice(userChoice-1) * userQuantity << endl;
        cout << "=====================================\n";
    }
    else if (!(userChoice > 0 && userChoice < 5))
    {   cout << "=====================================\n";
        cout << "Invalid option.\nThank you!\n";
        cout << "=====================================\n";
    }
    return 0;
}
