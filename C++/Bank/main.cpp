#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> //rand, srand
#include <time.h>   //time
#include <stdio.h>  //NULL
#include "account.h" //account class
#include "bubble.h" //bubble class
using namespace std;

//Temporary pseudo generator
unsigned long long int generateToken()
{
    unsigned long long int token = 0;
    for (int i = 0; i < 1024; i++)
    {
        token += rand() % 10;
        token *= 10;
    }
    return token;
}

//Parent class
class User
{
    private:
        string firstName = "";
        string lastName  = "";
        int userAge = 0;
        string gender = "";
        unsigned long long int userToken = generateToken();
        Account checkings = Account("Checkings");
        Account savings = Account("Savings");
        
    public: 
        //user Constructor
        User(string firstName, string lastName, int userAge, string gender)
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->userAge = userAge;
            this->gender = gender;
            cout << "user " << userToken << " created\n"; 
            cout << "Hello " << firstName << " " << lastName << "!\n";
            checkings.Account::newBubble("Reoccuring");
            savings.Account::newBubble("Reoccuring");
        }

        void displayAllInfo()
        {
            checkings.Account::displayInfo();
            savings.Account::displayInfo();
        }
        void deposit()
        {
            string accType = "Savings";
            double money = 0;
            string junk = "";
            cout << "Which account are you depositing to?\n";
            getline(cin, accType);
            cout << "How much would you like to deposit?\n";
            cin >> money;
            getline(cin, junk);

            if(money > 0)
            {
                savings.Account::deposit(money); //THIS IS ONLY DOING SAVINGS AAAAAAAAAAAAAAAAAA
            }
        }
};

void displayMenu()
{
    cout << "===========================\n";
    cout << "0: Exit Menu\n";
    cout << "1: Display All Info\n";
    cout << "2: Deposit\n";
    cout << "3: Withdraw\n";
    cout << "4: Transfer\n";
    cout << "===========================\n";
}

string getUserResponse()
{
    string response;
    getline(cin, response);
    return response;
}

int main()
{
    //Generate random seed
    srand (time(NULL));
    cout << "Hello world!\n";
    
    string firstName = "Drew";
    string lastName  = "Lickman";
    int userAge = 20;
    string gender = "Male";
    
    //Create a user named person
    User person(firstName, lastName, userAge, gender);
    while(true)
    {
        displayMenu();
        string resp = getUserResponse();
        if(resp == "0")
        {
            break;
        }
        else if(resp == "1")
        {
            person.User::displayAllInfo();
        }
        else if(resp == "2")
        {
            person.User::deposit();
        }
    }
    return 0;
}