/*
Name: Drew Lickman c8055315
Class: 2170-001
Professor: Dr. Yang
Due: 11/5/21
*/
#include <iostream>
#include "Email.h"
using namespace std;

int main()
{
	Email myEmail; //create myEmail
	myEmail.displayInfo(); //show email, password, mbcap
	myEmail.passwordChange(); //change password algorithm
	
	/*
	The Email class fully supports the two string arguements constructor
	Email secondEmail("Ada", "Love");
	secondEmail.displayInfo();
	secondEmail.passwordChange();
	*/
	return 0;
}

