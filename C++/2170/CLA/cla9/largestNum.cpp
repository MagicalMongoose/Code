/*
Name: Drew Lickman c8055315
Course: 2170-001 Dr. Yang
CLA#: 1
Date: 9/29/21
Description: Input 3 numbers and output the greatest
*/

#include <iostream>
using namespace std;

int maxAmongThree(int a, int b, int c)
{
	int max = a;
	if (b > a)
	{
		max = b;
		if (c > b)
		{
			max = c;
		}
	}
	return max;
}

int main()
{
	int a, b, c;
	cout << "Input your numbers, press enter after each input: " << endl;
	cin >> a >> b >> c;
	cout << "The largest number is " << maxAmongThree(a, b, c) << endl;
}
