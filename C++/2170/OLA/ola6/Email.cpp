/*
Name: Drew Lickman c8055315
Class: 2170-001
Professor: Dr. Yang
Due: 11/5/21
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <ctype.h>
#include <locale>
#include <cstring>
#include <iomanip>
#include "Email.h"
using namespace std;
const string dprtmntName[] = {"None", "Computer Science", "Accounting", "Electrical Engineering"};
const string department[] = {"", "cs.", "act.", "ee."};
const char validChars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$'};

string numToDepartment(int num)
{
	/*
	Purpose: Converts department ID number to department name
	Input: int from 0 to 3
	Output: corresponding department name from global constant dprtmntName[]
	*/
	string dep = department[num];
	return dep;
}

//Default constructor
Email::Email()
{
	setName();
	setDepartment();
	randomPassword(passwordLength);
	cout << "Your email account has been created successfully!\n";
}

//Overloaded constructor
Email::Email(string first, string last)
{
	firstName = first;
	lastName = last;
	setDepartment();
	randomPassword(passwordLength);
	cout << "Your email account has been created successfully!\n\n";
}

void Email::setDepartment()
{
	/*
Purpose: Set the department variable for an object
Input: User inputs int from 0 to 3
Output: No output, sets the department variable
	 */
	int response = -1;
	cout << firstName << " " << lastName;
	cout << ", please enter your department code:" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << i << ": " << dprtmntName[i] << endl;
	}

	do
	{ 
		cin >> response;
	} while (response < 0 || response > 3);
	cout << endl;

	department = numToDepartment(response);
}

void Email::randomPassword(int length)
{
	/*
Purpose: Create a default random password 10 characters long
Input: No input
Output: String that is 10 characters long
	 */
	string pass = "ABCDEFGHIJ";
	for (int i = 0; i < length; i++)
	{
		pass[i] = validChars[rand() % 40];
	}
	password = pass;
	cout << "Your default password is:\n" << pass << endl;
}

void Email::setName()
{

	/*
Purpose: If an object is created without arguements, this function will be called, and will set the object's firstname and lastname variables
Input: First name and Last name
Output: No output, sets the first and last name variables for the object
	 */
	string first, last;
	cout << "Please enter your first name: ";
	cin >> first;
	cout << "Please enter your last name: "; 
	cin >> last;
	firstName = first;
	lastName = last;
}

void Email::displayInfo()
{
	/*
	Purpose: Display the email account info
	Input: No input
	Output: Outputs the Email Address, Password, and Mailbox Capacity of an object
	*/
	cout << endl;
	cout << "Your Email Account Information: " << endl;
	cout << "======================================" << endl;

	cout << fixed << setw(20) <<  "Email address: ";
	cout << firstName << "." << lastName;
	cout << "@" << department << domain << endl;
 
	cout << fixed << setw(20) << "Password: " << password << endl;
	cout << fixed << setw(20) << "Mailbox capacity: " << mailBoxCapacity << "MB" << endl;
	cout << "======================================" << endl;
}

void Email::passwordChange()
{
	/*
	Purpose: Allow the user to set their own password
	Input: String that is at least the length of passwordLength variable
	Output: Makes sure the password is long enough, then tells the user the password is updated if successful
	*/
	char response = 'n';
	string newPass;
	cout << "Do you want to change your password? (Y/N)" << endl;
	cin >> response;
	if (response == 'y' || response == 'Y')
	{
		do
		{
			cout << "Enter your new password: " << endl;
			cin >> newPass;
			if (newPass.length() < passwordLength)
			{
				cout << "Please use a longer password!" << endl;
			}
		}
		while (newPass.length() < passwordLength);
		
		password = newPass;
		cout << "Your password has been updated!" << endl;
	}
}


//Deconstructor
Email::~Email()
{

}

