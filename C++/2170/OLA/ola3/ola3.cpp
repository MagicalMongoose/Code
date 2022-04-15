/*
Title: Equilateral Triangle Drawing App
Author: Drew Lickman
Professor: Dr. Yang
Class: CSCI 2170 - 001
Due: Sep 27, 2021 23:59 PM (Monday)
Description: Create an equilateral triangle using ASCII and 
also display how many total dots there are.
*/
#include <iostream>
using namespace std;

int main()
{
	int min = 1;
	int max = 50;
	bool cont = true; //can't use continue because that's a keyword
	cout << "========================================================\n";
	cout << "Welcome to the Equilateral Triangle Drawing App\n";
	cout << "========================================================\n";
	
	do
	{
		int num;
		int total = 0;
		char response;
		cout << "How large would you like your equilatteral triangle to be?\n";
		cin >> num;

		/*
		for (int c = 0; c < num; c++)
		{
			total += c+1;
		}*/
		total = (num*(num+1)/2); //Formula from calculus
		if (num < min)
		{	
			cout << "Minimum size is " << min << endl;
			return 0;
		}
		if (num > max)
		{
			cout << "Maximum size is " << max << endl;
			return 0;
		}
		
		for (int i = 0; i < num+1; i++)//Maximum number of dots per line
		{
			for (int j = num-i; j > 0; j--)
			{
				cout << " ";
			}
			for (int k = i; k > 0; k--)//Print each dot
			{	
				cout << "* ";
			}	
			cout << endl;
		}	
	
		cout << "Total dots: " << total << endl;
		cout << "========================================================\n";
		cout << "Do you want to continue? (Y|N)\n";
		cout << "========================================================\n";
		cin >> response;
		if (response != 'Y' &&  response != 'y')
		{
			cont = false;
			cout << "========================================================\n";
			cout << "Thank you for checking out the Triangle Drawing App!\n";
			cout << "========================================================\n";
		}
	} while (cont);
	
	return 0;
}
