/*
(a) Your name and C-number (Drew Lickman--c8055315)
(b) course ID, section number and professor's name (CSCI 2170-001 Dr. Xin Yang)
(c) the closed lab session number (CLA18: Programming Exericse 1)
(d) Program Description: Stack Exercise
(e) the date of the lab (e.g: Nov 22nd, 2021)
*/
#include<iostream>
#include<stack> // stack container
#include<fstream> // file processing
#include<string>
using namespace std;

int main()
{
//s_reverse is used to hold the list of names in reverse order
//s_orig is used to hold the list of names in original order
stack<string> s_reverse, s_orig; 

ifstream inFile;
inFile.open("names.dat");
if(!inFile)
{
	cout << "File NOT Found!" << endl;
	exit(EXIT_FAILURE);
}

//Your code to read the list of names and push to the stack s_orig
//(1)prime reading using getline
string name; 
getline(inFile, name);
//(2)push the name to the stack s_orig
s_reverse.push(name);
//(3)while loop to check end-of-file
while(!inFile.eof())
	{	
		//a. read the next name in the file
      	getline(inFile, name);
		//b. push the name to the stack s_orig
		s_reverse.push(name);
	}
cout << "The names in reverse order:\n";
cout << "================================\n"; 
//Your code to print out the list of names in reverse order
while(!s_reverse.empty())
	{
		cout << s_reverse.top() << endl;
		s_orig.push(s_reverse.top());
		s_reverse.pop();
	}
//Note: you may push the names of s_orig to the s_reverse before you pop 
//Your code to print out the lsit of names in orginal order	 
cout << "The names in original order:\n";
cout << "================================\n"; 
while(!s_orig.empty())
	{
		cout << s_orig.top() << endl;
		s_reverse.push(s_orig.top());
		s_orig.pop();
	}
inFile.close();
return 0;      
}
