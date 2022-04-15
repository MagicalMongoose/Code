//FIle:  main8a.cc
//This program demonstrates simple linked list manipulation.
//It shows how to insert at the end of a list and then print the list.

#include "structs.h"
#include "inlab8.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[])
{

    ListClass bankList;
    char EOLN;
    RecordType newRec;
    
    
    //Read all of the records from the file and insert them into the list.
    cin >> newRec.acctNum >> newRec.balance;
    cin.get(EOLN);
    while(cin)
    {
        bankList.insertAtEnd(newRec);
        cin >> newRec.acctNum >> newRec.balance;
        cin.get(EOLN);
    }

    //Print the list
    cout<<"The initial list is:\n"; 
    bankList.printList();
    return(0);
}

