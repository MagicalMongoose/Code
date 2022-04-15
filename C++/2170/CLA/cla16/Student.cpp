#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

Student::Student()
{
	name = "";
	id = 0;
	scores = nullptr;
}

Student::Student(string name, int id)
{
	this->name = name;
	this->id = id;
	createScoresArray();
}


Student::Student(const Student &obj) //double check this is copy constructor
{
	this->name = obj.name;
	this->id = obj.id;
	this->scores = new double[numScores];
	for(int i = 0; i < numScores; i++)
	{
		this->scores[i] = obj.scores[i];
	}
	
}


void Student::createScoresArray()
{	
	this->scores = new double[numScores];
	for (int i = 0; i < numScores; i++)
	{
		cout << "Please enter a score: " << endl;
		cin >> this->scores[i];
	}
}


void Student::setStudent(string name, int id)
{
	this->name = name;
	this->id = id;
}


void Student::displayInfo()
{
	cout << "=====================" << endl;
	cout << "Name: " << this->name << endl;
	cout << "ID: " << this->id << endl << "Scores: ";
	for (int i = 0; i < numScores; i++)
		cout << this->scores[i] << " ";
	cout << endl << "=====================" << endl;
}


Student::~Student()
{
	delete [] scores;
}


