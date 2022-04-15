// cla2c BY student name,  CSCI 2170-sec, Due: mm/dd/yyyy
// PROGRAM ID:  cla2c.cpp / Average of three test scores
// AUTHOR:  student name
// INSTALLATION:  MTSU
// REMARKS:  This program is supposed to determine the average
//           of three test scores.  However, it contains several
//           errors.  Look at the comments in the program to
//           determine the errors.
//            Here is our first error.  This comment is missing a slash.

#include <iostream>              //the 3 needs to be a pound symbol (#)

using namespace std;

int main() 
{
	// Variable declarations... 
	int test1;             //int is needed instead of the word integer
	int test2, test3; 
	float average;              //float is needed instead of the word real

	// Read in the three test scores
	cout << "Enter the first test score:  "; 
	cin >> test1;            //the double slash before cin needs to be removed.
	cout << "Enter the second test score:  "; 
	cin >> test2;           
	cout << "Enter the third test score:  "; 
	cin >> test3;               //tst3 needs to be replaced by test3          

	// calculate the average of the test scores
	average = (test1 + test2 + test3)/3;     //there needs to be a semicolon after the 3

	// Display the results
	cout << "The average of the three scores is:  "; 
	cout << average;                //cin needs to be changed to cout
	cout << endl; 

	return 0; 
} 
