//*************************** Open Lab Assignment #5***************************
// FILE: ola5.cpp
// AUTHOR: Written by Drew Lickman.
// INSTRUCTOR: Dr. Xin Yang
// COURSE: CSCI 2170
// DUE DATE: Oct 25th, 2021
// DESCRIPTION: This program will take a products.dat file and output visualized tables of the ingredients and products.
// INPUT: File that includes an array size, the 2d array, and prices on the right side of the array
// OUTPUT: Visualized table showing the amounts of ingredients for each product, and the prices. 
//****************************************************************************

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//Global CONSTANTS
const string FOOD_NAMES[] = {"Donut", "Bagel", "White Bread", "Kaiser Roll", "King Cake", "Apple Pie", "Cherry Wafer"};
const int MAX_INGREDIENTS = 30;
const int MAX_PRODUCTS = 24;

//Defining functions above main() because I don't like function prototypes
//function to open data file
void openFile(ifstream &inFile)
{
	/*
	Purpose: Read an input file name interactively and open the file.
		If file does not exist, print error message, and keep asking
		the user to enter another file name.
	Parameters: Input file stream call by reference
	Pre-condition: Input file stream has been filled.
	Post-condition: Display File open successfully or File Open Error
	*/

	string fileName;
	do 
	{
		cout << "Enter the data file\n";
		cin >> fileName;
		inFile.open(fileName);
		if (!inFile)
		{
			cout << fileName << " not found! Please try again.\n\n";
		}
	}
	while (!inFile);
	cout << "Opened " << fileName << " successfully\n\n";
}

//function to read products info from file
void readFile(ifstream &inFile, int& products, int& ingredients, double ingPrice[], int amounts[][MAX_PRODUCTS]) //Need to grab the 2d array 
{
	/*
	Purpose: Read the products.dat file and output a table
	Parameters: Reference variables for the file, products, ingredients, and array variables for ingredient prices and ingredient amounts.
	Pre-condition: The first two integers of products.dat will be read seperately as to save the table's x and y size.
	Post-Condition: Display the table where the ingredients are the rows and products are the columns.
	*/
	//Read the table's x and y size in the file
	inFile >> ingredients >> products; 

	cout << "*****************************************************************************\n";
	cout << setw(12) << left << "Product";
	for (int h = 0; h < products; h++)
	{
		cout << setw(14) << FOOD_NAMES[h];
	}
	cout << "Ingredient Price\n";
	cout << "-----------------------------------------------------------------------------\n";
	for (int i = 0; i < ingredients; i++)
	{
		cout << "Ingredient" << i+1 << " ";
		for (int j = 0; j < products; j++)
		{	
			//Print ingredient amount
			inFile >> amounts[i][j];
			cout << fixed << setw(14) << left << amounts[i][j];
		}
		inFile >> ingPrice[i];
		//Print Ingredient Price
		cout << "$" << setprecision(2) << ingPrice[i] << endl;
	}
	cout << endl;
		
}
//function to calc product price
void calcProductPrices(int& products, int& ingredients, double ingPrice[], double prdctPrice[], int amounts[][MAX_PRODUCTS])
{
	/*
	Purpose: Calculate the sum of each product's ingredients, and save to prdctPrice[]. 
	Parameters: Reference variables for products, ingredients, and array variables for ingredient prices, product prices, and ingredient amounts.
	Pre-condition: The amounts[][] array must have been filled out before proper math can be accomplished.
	Post-Condition: The prdctPrice[] array will be filled with the sum of each product's ingredients. 
	*/
	double sum;
	for (int i = 0; i < products; i++)
	{
		sum = 0;
		for (int j = 0; j < ingredients; j++)
		{
			sum += (amounts[j][i]*ingPrice[j]);
		}
		prdctPrice[i] = sum;
	}
}
//function to display cost of products table
void displayProductTable(int& products, int& ingredients, double prdctPrice[], int amounts[][MAX_PRODUCTS])
{
	/*
	Purpose: Take the ingredient amounts and flip the table's axis so that the products are the rows and the ingredients are the columns,
		so that the product prices can be displayed on the right side.
	Parameters: Reference variables for products, ingredients, and array variables for product prices, and ingredient amounts. 
	Pre-condition: amounts[][] array must be filled.
	Post-Condition: Displays the table where the products are the rows and the ingredients are the columns. 
	*/
	cout << "*****************************************************************************\n";
	cout << setw(16) << left << "Product";
	for (int h = 0; h < ingredients; h++)
	{
		cout << "Ing" << h+1 << "            ";
	}
	cout << "Product Price\n";
	cout << "-----------------------------------------------------------------------------\n";
	for (int i = 0; i < products; i++)
	{
		cout << i+1 << " ";
		cout << setw(14) << FOOD_NAMES[i];
		for (int j = 0; j < ingredients; j++)
		{
			//Print ingredient amount
			cout << fixed << setw(16) << left << amounts[j][i];
		}
		//Print Product Price
		cout << "$" << fixed << setw(7) << setprecision(2) <<  prdctPrice[i] << endl;
	}
	cout << endl;

}
//function to find most expensive product
double mostExpensive(int& products, double prdctPrice[])
{
	/*
	Purpose: Calculate which product is the most expensive
	Parameters: Reference variable for products, and array variable for product prices.
	Pre-condition: The product prices array must be filled.
	Post-Condition: Return the number that references the global array of FOOD_NAMES[] for the product with the highest price. 
	*/
	double max = prdctPrice[0];
	int temp = 0;
	for (int i = 1; i < products; i++)
	{
		if (prdctPrice[i] > max)
		{
			max = prdctPrice[i];
			temp = i;
		}
	}
	return temp;
}

int main()
{
	ifstream inFile;
	int products;
	int ingredients;
	int amounts[MAX_INGREDIENTS][MAX_PRODUCTS];
	double ingPrice[MAX_INGREDIENTS];
	double prdctPrice[MAX_PRODUCTS];
	openFile(inFile);
	readFile(inFile, products, ingredients, ingPrice, amounts);
	calcProductPrices(products, ingredients, ingPrice, prdctPrice, amounts);
	displayProductTable(products, ingredients, prdctPrice, amounts);
	int expensiveFood = mostExpensive(products, prdctPrice);
	cout << "Product " << expensiveFood+1 << ": " << FOOD_NAMES[expensiveFood] << " is the most expensive product." <<  endl;
	inFile.close();
	return 0;
	}
