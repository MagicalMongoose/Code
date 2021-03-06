// Drew Lickman -- c8055315
// CSCI 2170-001 Dr. Xin Yang
// CLA1
// 8/25/21
// yardage BY Drew Lickman,  CSCI 2170-001, Due: 08/23/21
// PROGRAM ID:  yardage.cpp / The Property Yardage Calculator Program
// AUTHOR:  Drew Lickman
// INSTALLATION:  MTSU
// REMARKS:  This program is used in calculating how many square yards
// comprise a square property measured by the side of the square in
// whole number mile units.

#include <iostream>
using namespace std;

const int SQ_YARDS_PER_SQ_MILE = 1760*1760; // conversion factor

int main()
{

	int side;    // Side of property, in miles
	int area;    // Area of property, in square yards
	float price; // Price per square yard, in dollars
	float cost;  // Total cost of the property
	
	// Obtain input
	cout << "Enter side of property (in miles): ";
	cin >> side;
	cout << "Enter price per square yard (in dollars): ";
	cin >> price;


	// Calculate area of property, in square yards
	area = side * side * SQ_YARDS_PER_SQ_MILE;

	// Determine cost of the property
	cost = area * price;

	cout << "The square yardage is " << area << endl;
	cout << "The cost is $" << cost << endl;

	return 0;
}	
