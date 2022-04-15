/*
Name: Drew Lickman c8055315
Class: 2170-001
Professor: Dr. Yang
Due: 11/5/21
*/

#ifndef email_h
#define email_h

#include <string>
using namespace std;

class Email
{
	private:
		//private data members
		string firstName = "";
		string lastName = "";
		string password = "";
		string department = "";
		int mailBoxCapacity = 500;
		int passwordLength = 10;
		string domain = "mtsu.edu";

		//private methods
		void setDepartment();
		void randomPassword(int length);
		void setName();	

	public:
		//public methods
		//default constructor
		Email();
		Email(string, string);
		~Email();
		void displayInfo();
		void passwordChange();
	
};

#endif
