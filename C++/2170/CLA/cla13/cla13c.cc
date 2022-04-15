/*
Author: Drew Lickman c8055315
Professor: Dr. Yang
Class: 2170-001
Lab: CLA13: Programming Exercise 3)
Due: 10/20/21
Description: Create a dynamically sized array that will be used to print Student info.
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Student
{
	string name;
	string email;
	int id;
};

void getStudentInfo(Student *studPtr, int i)
{
	string junk;
	getline(cin, junk);
	cout << "Student [" << i+1 << "]:" << endl;
	cout << "Enter name: ";
	getline(cin, studPtr->name);
	cout << "Enter email: ";
	cin >> studPtr->email;
	cout << "Enter id: ";
	cin >> studPtr->id;	
	cout << endl << endl;
}

void printStudentInfo(const Student *studPtr)
{
	cout << "Name: " << fixed << setw(20) << left << studPtr->name;
	cout << "Email: " << fixed << setw(20) << left << studPtr->email;
	cout << "ID: " << fixed << setw(20) << left << studPtr->id << endl;
}


int main()
{	
	int num;
	cout << "How many students are in the class?" << endl;
	cin >> num;
	Student *studPtr = new Student[num];
	
	for (int i = 0; i < num; i++)
	{
		getStudentInfo(studPtr+i, i);
	}
	cout << "==========================" << endl;
	for (int i = 0; i < num; i++)
	{
		printStudentInfo(studPtr+i);
	}
	delete [] studPtr;
	return 0;
}

