/*
Name: Drew Lickman c8055315
Course: CSCI 2170-001 Dr. Yang
Session#: 3
Date: 9/29/21
Description: Calculate average, lowest, and largest from a datafile
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void dataProcessing(ifstream &inFile, double &average, double &lowest, double &highest)
{	
	
	int total = 0;
	double num;
	lowest = 100000;
	highest = -100000;
	while(!inFile.eof())
	{
	 	inFile >> num;
		cout << num << endl;

		average += num;
		total += 1;

		if (num > highest)
		{
			highest = num;
		}
		if (num < lowest)
		{
			lowest = num;
		}
	}
	cout << "Average: " << average << " total: " << total << endl; //debug
	average = average/total;
	cout << "Got to end of data processing" << endl;
}

int main()
{
	ifstream inFile;
	inFile.open("scores.txt");
	double average;
	double lowest;
	double highest; 
	dataProcessing(inFile, average, lowest, highest);
	cout << "Average: " << average << endl;
	cout << "Lowest: " << lowest << endl;
	cout << "Highest: " << highest << endl;
	return 0;
}

