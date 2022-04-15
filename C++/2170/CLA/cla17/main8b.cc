//File: main8b.cc.cc
//This program demonstrates simple linked list manipulation.
//It shows how to insert items into a list in sorted order.

#include "structs.h"
#include "inlab8.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[])
{

	ListClass bankList;
	char EOLN;
	RecordType newRec;
	
	
	//Read all of the records from the file and insert them into the list.
	cout << "Inserting data in ascending order by account number.\n";
	cin >> newRec.acctNum >> newRec.balance;
	cin.get(EOLN);
	while(cin)
	{
		bankList.insertInOrder(newRec);
		cin >> newRec.acctNum >> newRec.balance;
		cin.get(EOLN);
	}
	

	//Print the list
	bankList.printList();
	return(0);
}
