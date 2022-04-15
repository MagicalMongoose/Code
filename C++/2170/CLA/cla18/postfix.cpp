/*
(a) Your name and C-number (Drew Lickman--c8055315)
(b) course ID, section number and professor's name (CSCI 2170-001 Dr. Xin Yang)
(c) the closed lab session number (CLA18: Programming Exericse 2)
(d) Program Description: Stack Exercise
(e) the date of the lab (e.g: Nov 22nd, 2021)
*/
#include<iostream>
#include<stack> // stack container
#include<fstream> // file processing
#include<cctype> // isdigit()
#include<string>
using namespace std;

bool isNum(string check)
{
	for(int i = 0; i < check.length(); i++)
	{
		if(!isdigit(check[i]))
		{
			return false;
		}
	}
	return true;
}

void getNums(int &first, int &second, stack<int> &stk)
{
	second = stk.top();
	stk.pop();
	first = stk.top();
	stk.pop();
}

int postfix(stack<int> &stk, string e)
{
	int solution = 0;
	int first, second;
	int temp;
	string check;
	int pos = e.find(" ");
	while(pos != string::npos)
	{
		check = e.substr(0, pos);
		if(isNum(check)) 
		{	
			stk.push(stoi(check));
		}
			else if(check == "+")
			{
				getNums(first, second, stk);
				stk.push(first + second);
			}	
			else if(check == "-")
			{
				getNums(first, second, stk);
				stk.push(first - second);
			}	
			else if(check == "*")
			{
				getNums(first, second, stk);
				stk.push(first * second);
			}	
			else if(check == "/")
			{
				getNums(first, second, stk);
				stk.push(first / second);
			}	
		e = e.substr(pos+1);
		pos = e.find(" ");
	}
	solution = stk.top();
	return solution;
}

int main()
{
	stack<int> stk;
	string expression;
	cout << "Please enter your postfix expression: \n";
	getline(cin, expression);
	expression = expression + " ";
	cout << "Result = " << postfix(stk, expression) << endl;
	return 0;
}
