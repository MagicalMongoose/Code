/*
Author: Drew Lickman c8055315
Professor: Dr. Yang
Class: 2170-001
Lab: CLA13: Programming Exercise 2)
Due: 10/20/21
Description: Input students from students.txt and output them from the vector
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

struct Student
{
	string name;
	string major;
	double gpa;
};

void getStudentInfo(Student &stud, ifstream &inFile)
{
		string junk;
		getline(inFile, stud.name);
		getline(inFile, stud.major);
		inFile >> stud.gpa;
		getline(inFile, junk);
}

void printStudentInfo(const vector<Student> &students)
{
	for (int i = 0; i < students.size(); i++)
	{
		cout << "Student name: " <<  fixed << setw(20) << left << students[i].name;
		cout << "Student major: " << fixed << setw(20) << left << students[i].major;
		cout << "Student GPA: " <<  fixed << setw(20) << left << setprecision(2) << students[i].gpa << endl;
	}
}


int main()
{
	Student stud;
	vector<Student> students;

	ifstream inFile;
	inFile.open("students.txt");
	if(!inFile)
	{
		cout << "File does not exist." << endl;
		exit(EXIT_FAILURE);
	}
	while(inFile)
	{
		getStudentInfo(stud, inFile);
		students.push_back(stud); 
	}
	printStudentInfo(students);
	inFile.close();
	return 0;
}

