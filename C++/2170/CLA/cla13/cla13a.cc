/*
Author: Drew Lickman c8055315
Professor: Dr. Yang
Class: 2170-001
Lab: CLA13: Programming Exercise 1)
Due: 10/20/21
Description: Input a user's information then output to console. Uses pointers.
*/

#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;
	string email;
	int id;
};

void getStudentInfo(Student *studPtr)
{
	cout << "Enter the student's name: ";
	getline(cin, studPtr->name);
	cout << "\nEnter the student's email: ";
	cin >> studPtr->email;
	cout << "\nEnter the student's id: ";
	cin >> studPtr->id;
	cout << endl;
}

void printStudentInfo(const Student *studPtr)
{
	cout << "Student name: " << studPtr->name << endl;
	cout << "Student email: " << studPtr->email << endl;
	cout << "Student id: " << studPtr->id << endl;
}

int main()
{
	Student stud;
	Student* studPtr = nullptr;
	studPtr = &stud;
	getStudentInfo(studPtr);
	printStudentInfo(studPtr);

	return 0;
}

