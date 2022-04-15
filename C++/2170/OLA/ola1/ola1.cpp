/*
Title: Calculate dollar denomination types 
Author: Drew Licman
Professor: Dr. Yang
Class: CSCI 2170 - 001
Due: Sep 8th, 2021 23:59 PM (Wednesday)
Description: 
    Input a number, and the program will output 
    the fewest amount of dollars you can receive from an ATM
    spread through different denomination types, such as $100 bills, $50 bills, $20 bills etc. 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int num;
    //Welcome user to ATM
    cout << "========================\n";
    cout << "Welcome to MTSU ATM Cash Withdrawals!\n";
    cout << "========================\n";
    cout << "Please enter the amount of money to be withdrawn:\n";
    cin >> num;
    cout << endl;
    cout << "The ATM is going to give you:\n";
    cout << "-------------------------\n";

    //Calculate the number of currency notes to print for each type of dollar denomination
    cout << (num / 100) << " currency notes of 100" << "$.\n";
    cout << (num % 100 / 50) << " currency notes of 50" << "$.\n";
    cout << (num % 100 % 50 / 20) << " currency notes of 20" << "$.\n";
    cout << (num % 100 % 50 % 20 / 10) << " currency notes of 10" << "$.\n";
    cout << (num % 100 % 50 % 20 % 10 / 5) << " currency notes of 5" << "$.\n";
    cout << (num % 100 % 50 % 20 % 10 % 5) << " currency notes of 1" << "$.\n";
    
    //Say goodbye to user
    cout << "========================\n";
    cout << "Thank you! See you next time!\n";
    cout << "========================\n";
    return 0;
}