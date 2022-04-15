//File: storeClassb.h
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
	//Read the data for a store from a file.  The name of the 
	//file is passed as an argument to this method
	void readFile (string filename);

	//print information about the store

	//You should define 3 printStore overloaded functions:
	//One printStore requires a string as a parameter.
	//One printStore requires an integer as a parameter.
	//One printStore requires both an integer and a string 
	//as a parameter.
	void printStore();
	void printStore(string s);
	void printStore(int x);
	void printStore(string s, int x);

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
