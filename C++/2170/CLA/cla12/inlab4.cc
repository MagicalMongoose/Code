//File:        inlab4.cc
//Programmer:
//Class:       CSCI 2170
//
//This program reads and prints information related to videos
//owned by Movie Rent Video Store.  
//
//The program reads data from the data files, inlab4.dat and 
//inlab4b.dat.  The data in inlab4.dat contains information about
//videos including the name of a video, the number of copies of a
//particular video, and the video type.  You will add code to this
//program to read information about the video store's customers
//from inlab4.dat.
//
//The user is allowed to select from a menu of options that includes:
// 1) Print a list of all videos owned by the Movie Rent Video Store
// 2) Print a list of all customers
// 3) Print out a list of rental information by video titles
// 0) Exit this program

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//maximum number of videos owned by the store
const unsigned int MAX_VIDEOS = 100;

//maximum number of customers
const unsigned int MAX_CUSTOMERS = 20;

//Definition of a Video structure
struct Video
{
	string movieTitle;         //name of movie
	unsigned int numberCopies; //number of copies
	string videoType;          //type of video
};

//Definition of a customerType structure
struct customerType
{
       //Exercise 3 goes here
	string name;
	int id;
	string movieTitle;
	string returnDate;
};

//function prototypes
int menuSelection();
void getVideo (Video&, ifstream&);
void printVideo (Video);
void getCustomer(customerType&, ifstream&);
void printCustomer(customerType);
void printRentalInfo(customerType[], string , int);
bool numberInSet(int x);

int main ()
{
	//variables
	Video videoInfo;               //used to read in video information
	Video allVideos[MAX_VIDEOS];   //an array of videos owned by the store
	customerType customer;         //one customer's check out information
	customerType allCustomers[MAX_CUSTOMERS]; //array of customer check out info
	ifstream videoIn;              //input stream for video information
	ifstream customerIn;           //input stream for customer info
	int numVideos=0;               //how many videos? 
	int numCustomers=0;            //how many customers?
	int choice;                    //user's menu choice

	//open the files and check for file failure
	videoIn.open ("inlab4.dat");
	if (!videoIn)
	{
		cerr << "inlab4.dat could not be opened!";
		exit (0);
	}
	customerIn.open("inlab4b.dat");
	if (!customerIn)
	{
		cerr << "inlab4b.dat could not be opened!";
		exit (0);
	}

	//input all videos owned by the video store
	getVideo(allVideos[numVideos], videoIn);
	while (videoIn)
	{
		numVideos++;
		getVideo(allVideos[numVideos], videoIn);
	}

	getCustomer(allCustomers[numCustomers], customerIn);
	while (customerIn)
	{
		printCustomer(allCustomers[numCustomers]);
		numCustomers++;
		getCustomer(allCustomers[numCustomers], customerIn);
	}


	//get the user's choice from the menu
	choice = menuSelection();

	//loop until the user decides to quit
	while (choice != 0)
	{
		switch (choice)
		{
		//print all videos owned by the store
		case 1: {	
			      for (int i=0; i< numVideos; i++)
				    printVideo(allVideos[i]);
			      break;
			    }
		//print all store customers
	 	case 2: {
			      for (int j=0; j< numCustomers; j++)
			         printCustomer(allCustomers[j]);
			      break;
			    }
		//print out a list of rental information by video titles
		case 3: {
			      for (int k=0; k< numVideos; k++)
			      {
				     printVideo(allVideos[k]);
				     printRentalInfo(allCustomers, allVideos[k].movieTitle,numCustomers);
			      }
			      break;
		        } 
		};
		choice = menuSelection();
	}
	return 0;
}

//This method prints a menu, gets the user's selection and returns it.
int menuSelection()
{       
	int choice;          //the user's menu selection

	//print the menu and make the user enter a valid menu selection
	do
	{
		cout <<"\n\n\n\n\n\n\nWelcome to Movie Rent Video Store Information";
		cout <<"\n\n 1----Print out list of all owned videos";
		cout <<"\n\n 2----Print out list of all customers";
		cout <<"\n\n 3----Print out list of rental information by video titles";
		cout <<"\n\n 0----Exit this program";
		cout <<"\n\n\n\nPlease enter choice and hit <ENTER>:";
		cin >> choice;
	}
	while (!numberInSet(choice));
	return choice;
}

//This function determines whether the argument x is in 
//a valid range.  If it is, true is returned; otherwise
//return false.
bool numberInSet(int x)
{
	if ( x>3 || x< 0)
		return false;
	else
		return true;
}

//This function reads information about a video from the file
//myIn.
void getVideo (Video& oneVideo, ifstream& myIn)
{
	char endOfLine;        //used to remove the end of line character

	//get the video information
	getline(myIn, oneVideo.movieTitle);
	myIn >> oneVideo.numberCopies;
	myIn.get(endOfLine);
	getline (myIn, oneVideo.videoType);
}

//Print out the information about a video.
void printVideo (Video oneVideo)
{
	cout << "\n\nName of video:\t\t" << oneVideo.movieTitle << endl;
	cout << "Number of copies:\t" << oneVideo.numberCopies << endl;
	cout << "Video type:  \t\t" << oneVideo.videoType << endl;
}

//Read information about one customer from myIn.
void getCustomer(customerType& person, ifstream& myIn)
{
	char endOfLine;        //used to remove the end of line character 
    //Exercise 4 goes here
	getline(myIn, person.name);
	myIn >> person.id;
	myIn.get(endOfLine);
	getline(myIn, person.movieTitle);
	getline(myIn, person.returnDate);
}

//This function receives an array of check out information for
//all customers, the title of a movie that has been checked out,
//and the number of customers.  The function prints a list of all
//the names of customers who have rented the video indicated in
//the movie title.
void printRentalInfo (customerType people[], string title, int numCustomers)
{
	//Exercise 7 goes here
	for (int i = 0; i < numCustomers; i++)
	{
		if(people[i].movieTitle == title)
		{
			cout << people[i].name << endl;
		}
	}
}

//This function prints one person's check out information.
void printCustomer(customerType person)
{
	//Exercise 8 goes here
	cout << "Name: " << person.name << endl;
	cout << "ID: " << person.id << endl;
	cout << "Movie rented: " << person.movieTitle << endl;
	cout << "Return date: " << person.returnDate << endl;
}
