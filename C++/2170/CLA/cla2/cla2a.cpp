// cla2a BY student name,  CSCI 2170-sec, Due: mm/dd/yyyy
// PROGRAM ID:  cla2a.cpp / Landlord's earnings
// AUTHOR:  student name
// INSTALLATION:  MTSU
// REMARKS:  This program calculates a landlord's earnings on an
// apartment given the rent per month, the number of months rented,
// and a deduction for a 5% manager's commission.  

#include <iostream>
using namespace std;

int main()
{
	// Variable and constant declarations...
	const float RATE = 0.05;      // manager's commission rate
	float rent;                   // rent per month
	float numMonths;              // number of months rented
	float earnings;               // earnings on the apartment

	// Assign values and calculate earnings
	rent = 250;
	numMonths = 7;

	// Calculate earnings
	earnings = (1.0 - RATE) * rent * numMonths;

	// Display results
	cout << "The rent per month is: " << rent << endl;
	cout << "The apartment has been rented for ";
	cout << numMonths << " months." << endl;
	cout << "The manager receives a " << 100 * RATE;
	cout << "% commission rate. " << endl;
	cout << "The earnings were: " << earnings << endl;

	//exit
	return 0;
}
