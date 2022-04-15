/*
    Drew Lickman
    CSCI 3110-001
    Project #2
    Due: 02/10/22
*/

#include "intsllist.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Step 1: Read input file named "ints.txt"
    ifstream infile;
	infile.open("ints.txt");
	int inputInt;
    char inputChar;

    IntSLList list;
    

    while (infile >> inputInt >> inputChar)
    {
        cout << "(" << inputChar << ")" << inputInt << " ";
        if (inputChar == 'a')
        {
            //Add the integer to the list
            //list->IntSLList::insertInOrder(inputInt);
        }
        else if (inputChar == 'd')
        {
            //Remove a single instance of the integer from the list
        }
        else if (inputChar == 'D')
        {
            //Remove all instances of the integer from the list
        }
        list.printAll();
    }
    return 0;
}
