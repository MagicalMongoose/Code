//File: storeClassb.cc
//
//This is the implementation file for a store class.
//Each store contains data members that contain 
//information about chairs and tables sold by the store
//as well as the name of the store.

#include "storeClassb.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//This method receives the name of the file containig
//store data.  It reads all data about the store.
//The data file contains the name of the store followed
//by information about chairs and tables. If a chair's 
//information appears in the file, it is preceeded by
//the string "Chair".  If a table's information appears
//in the file, it is preceeded by the string "Table".
void StoreClass::readFile(string filename)
{
	string input;                 //input a string from the file
	ifstream myFile;              //input file stream
	totalChairs = 0;              //set the chair counter to 0
	totalTables = 0;              //set the table counter to 0

	//open the data file & check to make sure it opened
	myFile.open(filename.c_str());
	if (!myFile)
	{
		cerr << "Data file failed to open!\n";
		exit (0);
	}

	//read the store's name
	myFile >> input;

	//check for an empty file
	if(input!="")
	{
		//set the store's name
		storeName = input;

		//read in chairs & tables until end-of-file
		//read the type of the next item
		myFile >> input;
		while(myFile)
		{


			//the next item is a chair
			if(input == "Chair")
			{
				//create a Chair object and fill it with data
				Chair chair1;            
				myFile >> chair1.designer;
				myFile >> chair1.color;
				myFile >> chair1.material;
				
				//read a string to indicate whether the chair
				//has a cushion or not
				myFile >> input;
				if(input == "true")
				{
					chair1.cushion = true;
				}
				else
					chair1.cushion = false;
				myFile >> chair1.qty;
				
				//place the chair into the array of chairs
				chairArray[totalChairs] = chair1;
				totalChairs +=1;
			}
			//the next item is a table
			else if(input == "Table")
			{
				//create a Table object and fill it with data
				Table table1;
				myFile >> table1.designer;
				myFile >> table1.color;
				myFile >> table1.material;
				
				//read a string to indicate whether the table
				//has glass or not
				myFile >> input;
				if(input == "true")
				{
					table1.glass = true;
				}
				else
					table1.glass = false;
				myFile >> table1.qty;
				
				//place the chair into the array of tables
				tableArray[totalTables] = table1;
				totalTables+=1;
			}
			//read the type of the next item
			myFile >> input;

		}
	}
}

//This method prints all information about all tables
//and chairs in the store.
void StoreClass::printStore()
{
	//print all information about Chairs sold by
	//the store
	if (totalChairs > 0)
		cout << "Inventory of Chairs" << endl;
	else
		cout << "No chairs in Inventory" << endl;
	for(int i = 0; i < totalChairs; i++)
	{
		cout << chairArray[i].designer <<"\t";
		cout << chairArray[i].color << "\t";
		cout << chairArray[i].material << "\t";
		if(chairArray[i].cushion == true)
			cout << "Cushioned\t" <<endl;
		else
			cout << "Not Cushioned\t" << endl;
		cout << "Qty in Stock: " << chairArray[i].qty << endl;
	}

	//print all information about Tables sold by
	//the store
	if (totalTables > 0)
		cout << "\n\nInventory of Tables" << endl;
	else
		cout << "\n\nNo tables in Inventory" << endl;
	for(int i = 0; i < totalTables; i++)
	{
		cout << tableArray[i].designer <<"\t";
		cout << tableArray[i].color << "\t";
		cout << tableArray[i].material << "\t";
		if(tableArray[i].glass == true)
			cout << "Glass Top\t" <<endl;
		else
			cout << "No Glass Top\t" << endl;
		cout << "Qty in Stock: " << tableArray[i].qty << endl;
	}

}


//This method receives the type of product that the user
//wishes information about.  All products of that type
//are printed.
void StoreClass::printStore(string type)
{
	//if the type was "Chair", then print all inventory
	//pertaining to chairs
	if(type == "Chair")
	{
		if (totalChairs > 0)
			cout << "Inventory of Chairs" << endl;
		else
			cout << "No chairs in Inventory" << endl;
		for(int i = 0; i < totalChairs; i++)
		{
			cout << chairArray[i].designer <<"\t";
			cout << chairArray[i].color << "\t";
			cout << chairArray[i].material << "\t";
			if(chairArray[i].cushion == true)
				cout << "Cushioned\t" <<endl;
			else
				cout << "Not Cushioned\t" << endl;
			cout << "Qty in Stock: " << chairArray[i].qty << endl;
		}
	}
	else if (type == "Table")
	{
		if (totalTables > 0)
			cout << "\n\nInventory of Tables" << endl;
		else
			cout << "\n\nNo tables in Inventory" << endl;
		for(int i = 0; i<  totalTables; i++)
		{
			cout << tableArray[i].designer <<"\t";
			cout << tableArray[i].color << "\t";
			cout << tableArray[i].material << "\t";
			if(tableArray[i].glass == true)
				cout << "Glass Top\t" <<endl;
			else
				cout << "No Glass Top\t" << endl;
			cout << "Qty in Stock: " << tableArray[i].qty << endl;
		}
	}
}

//This method receives the type of product that the user
//wishes information about.  It also receives an integer
//quantity and prints all items of the given type that
//need to be reordered.  An item needs to be reordered
//if the store contains a quantity of that item less than
//the quantity received.
void StoreClass::printStore(string type,int qty)
{
	int count = 0;
	string temp = "";

	//if the type desired is a Chair
	if(type == "Chair")
	{
		cout << "Chairs to be Re-Ordered: " << endl;
		for(int i =0; i < totalChairs; i++)
		{
			//if a chair needs to be reordered print it
			if(chairArray[i].qty < qty)
			{
				cout << chairArray[i].designer <<"\t";
				cout << chairArray[i].color << "\t";
				cout << chairArray[i].material << "\t";
				if(chairArray[i].cushion == true)
					cout << "Cushioned\t" <<endl;
				else
					cout << "Not Cushioned\t" << endl;
				cout << "Qty in Stock: " << chairArray[i].qty << endl;
			}
		}
	}
	//if the type desired is a table
	else if(type == "Table")
	{
		cout << "Tables to be Re-Ordered" << endl;
		temp = tableArray[0].designer;
		for(int i =0;i<totalTables;i++)
		{
			//if a table needs to be reordered print it
			if(tableArray[i].qty < qty)
			{
				cout << tableArray[i].designer <<"\t";
				cout << tableArray[i].color << "\t";
				cout << tableArray[i].material << "\t";
				if(tableArray[i].glass == true)
					cout << "Glass Top\t" <<endl;
				else
					cout << "No Glass Top\t" << endl;
				cout << "Qty in Stock: " << tableArray[i].qty << endl;
			}
		}
	}
			
}

//This method receives an integer quantity and prints 
//all items that need to be reordered.  An item needs to be 
//reordered if the store contains a quantity of that item
//less than the quantity received.
void StoreClass::printStore(int qty)
{
	//print all chairs that need to be reordered
	cout << "Chairs to be Re-Ordered" << endl;
	for(int i =0;i<totalChairs;i++)
	{
		if(chairArray[i].qty < qty)
		{
			cout << chairArray[i].designer <<"\t";
			cout << chairArray[i].color << "\t";
			cout << chairArray[i].material << "\t";
			if(chairArray[i].cushion == true)
				cout << "Cushioned\t" <<endl;
			else
				cout << "Not Cushioned\t" << endl;
			cout << "Qty in Stock: " << chairArray[i].qty << endl;
		}
	}

	//print all tables that need to be reordered
	cout << "\nTables to be Re-Ordered" << endl;
	for(int i =0;i<totalTables;i++)
	{
		if(tableArray[i].qty < qty)
		{
			cout << tableArray[i].designer <<"\t";
			cout << tableArray[i].color << "\t";
			cout << tableArray[i].material << "\t";
			if(tableArray[i].glass == true)
				cout << "Glass Top\t" <<endl;
			else
				cout << "No Glass Top\t" << endl;
			cout << "Qty in Stock: " << tableArray[i].qty << endl;
		}
	}
}
