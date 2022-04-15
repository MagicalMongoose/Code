//File: storeClassa.h
//
//This is the specification file for a store class.
//Each store contains data members that contain 
//information about chairs and tables sold by the store
//as well as the name of the store.

#include <string>
using namespace std;

//prevent multiple inclusions
#ifndef STORE_CLASS_H
#define STORE_CLASS_H

class StoreClass
{
public:
	//You must declare the default constructor for the StoreClass.
	// Constructor declaration goes here.
	StoreClass()
	{
		totalTables = 0;
		totalChairs = 0;
		storeName = "";
	};

	//Read the data for a store from a file.  The name of the 
	//file is passed as an argument to this method
	void readFile (string filename);

	//print information about the store
	void PrintStore();

private:
	//define a struct for a Chair type
	struct Chair
	{
		string designer;   //chair designer's name
		bool cushion;      //does it have a cushion
		string material;   //type of material used in the chair
		string color;      //color of the chair
		int qty;           //quantity of this chair
	};

	//define a struct for a Table type
	struct Table
	{
		string designer;   //table designer's name
		bool glass;        //does the chair have glass
		string material;   //type of material used in the table
		string color;      //table's color
		int qty;           //quantity of this table
	};

	//data members in the store
	Chair chairArray[100];  //the store contains many chairs
	Table tableArray[100];  //and many tables
	int totalTables;        //number of tables
	int totalChairs;        //number of chairs
	string storeName;       //name of the store
};

#endif
