/*
Name:  Drew Lickman c8055315
Course: 2170-001 Dr. Yang
CLA#: 1
Date: 9/29/21
Description: Input a string and output the string but the first character of each word is capitalized
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Method definition
string sentenceCapitalized(string str)
{	
	int pos = str.find(" ");
	str[0] = toupper(str[0]);
	while (pos != string::npos)
	{
		str[pos+1] = toupper(str[pos+1]);
		pos = str.find(" ", pos+1);
	}
	return str;
}

int main()
{
	cout << "Input a sentence, and this program will capitalize the first letter of each word" << endl;
	string str;
	getline(cin, str);
	cout << sentenceCapitalized(str) << endl;
	return 0;
}

