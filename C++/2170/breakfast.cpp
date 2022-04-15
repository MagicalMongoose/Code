






//This is old and doesnt work




/*
Title: Breakfast Self Service System
Author: Drew Lickman
Professor: Dr. Yang
Class CSCI 2170 - 001
Due: Sep 15th, 2021 23:59 PM (Wednesday)
Description:
        User will select a food item from the menu and
        this program will calculate the total cost.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Menu
{
        public:
                Menu(string fN, double fP)
                {
                        foodName = fN;
                        foodPrice = fP;
                }
                void setName(string n)
                {
                        foodName = n;
                }
                void setPrice(double p)
                {
                        foodPrice = p;
                }
                string getFoodName()
                {
                        return foodName;
                }
                double getFoodPrice()
                {
                        return foodPrice;
                }
        private:
                string foodName;
                double foodPrice;


};


int main()
{
        int userChoice;
        int userQuantity;
        //Create a Menu object
        Menu menu[4]
        {
                Menu("Egg McMuffin", 2.99),
                Menu("Sausage Buritto", 4.99 ),
                Menu("Fruit Yogurt Parfait", 3.56),
                Menu("Hash Brown", 1.50),
        };

        cout << "=====================================\n";
        cout << "Welcome to MTSU's Breakfast Menu\n";
        cout << "=====================================\n";

        for (int i = 0; i < sizeof(menu); i++)
        {
                if (i == sizeof(menu))
                {
                        cout << i << "Quit\n";
                }
                 else
                {
                        cout << setprecision(2) << fixed;
                        cout << left << i+1 << ". " << setw(25) << menu[i].getFoodName() << setw(2) << right << "($" << menu[i].getFoodPrice() << ")"  << endl;
                }
        }

        cout << "Please select your option:\n";
        cin >> userChoice;
        if (userChoice == 5) {return -1;};
        cout << "The unit price for " << menu[userChoice-1].getFoodName() << " is: " << menu[userChoice-1].getFoodPrice() << endl;
        cout << "=====================================\n";
        cout << "Your Order Information:\n";
        cout << "-------------------------------------\n";
        cout << menu[userChoice-1].getFoodName() << ": " << menu[userChoice-1].getFoodPrice() << "(Unit:" << userQuantity << ")\n";
        cout << "-------------------------------------\n";
        cout << "Total Price: $" << menu[userChoice-1].getFoodPrice() * userQuantity << endl;
        cout << "=====================================\n";
        return 0;
}
