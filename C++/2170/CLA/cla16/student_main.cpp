/*
Name: Drew Lickman c8055315
Course: CSCI 2170-001 Dr. Xin Yang
CLA Session: CLA16
Due: Nov 12th 2021
Description: Create 3 student objects of the Student class, and use different constructor types for each.
*/

#include "Student.h"
using namespace std;

int main()
{
	Student stu1;
	stu1.setStudent("Bill Gates", 8294600);
	stu1.createScoresArray();
	stu1.displayInfo();

	Student stu2("Ada Love", 8292600);
	stu2.displayInfo();

	Student stu3 = stu1;
	stu3.displayInfo();
	return 0;
}
