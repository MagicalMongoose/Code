//FILE: cla12a.cc
//
//This program demonstrates the use of one-dimensional
//arrays.  An array of scores is read, printed, and
//the average of the scores is printed.

#include <iostream>
#include <fstream>
#include <stdlib.h>  //for the exit() function

using namespace std;

//function prototypes
void ReadInScores (int scores[], int& howMany);
float FindAverage(int scores[], int howMany);

//place the function prototype for PrintScores here
void PrintScores(int scores[], int& howMany);
void AboveAverage(int scores[], int&howMany, double avg);
//place the function prototype for LinearSearch here
int LinearSearch(int scores[], int max, int toFind);

int main()
{
    const int MAX_SCORES = 30;   //the array has at most 30 entries
    int scores [MAX_SCORES];     //an array of test scores with 30 entries
    int howMany;                 //the actual size of the array
    float averageScore;          //the average of the scores array

    //activate the function to read the scores
    ReadInScores(scores, howMany);

    //activate the function to print the scores
    PrintScores(scores, howMany);

    //Place your activation statement for FindAverage() here
	float avg = FindAverage(scores, howMany);
	cout << "Average: " << avg << endl;

    //Place your activation statement for AboveAverage() here
	AboveAverage(scores, howMany, avg);

    //Place your loop for the Linear Search here    
	int testNums[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter number [" << i << "]: ";
		cin >> testNums[i];
	}
	for (int j = 0; j < 5; j++)
	{
		int pos = LinearSearch(scores, MAX_SCORES, testNums[j]);
		if (pos != -1)
		{
			cout << testNums[j] << " found at index " << pos << endl;
		} else {
			cout << testNums[j] << " was not found." << endl;
		} 
	}

	return 0;

}

//Function:  ReadInScores()
//This function reads a set of scores from standard input.
//First the number of scores is read, then the scores.
void ReadInScores (int scores[], int& howMany)
{
    ifstream infile;            //our input file stream

    //open the file and check for success
    infile.open ("scores.dat");
    if (!infile)
    {
        cout << "Could not open scores.dat!!\n";
        exit(1);
    }

    //read the number of scores
    infile >> howMany;

    //now read the scores
    for (int i = 0; i < howMany; i++)
         infile >> scores[i];
}

//Your PrintScores() function definition should go here
void PrintScores (int scores[], int& howMany)
{
	for (int i = 0; i < howMany; i++)
	{
		cout << "score[" << i << "]: " << scores[i] << endl;
	}

	
}


//Function: FindAverage()
//This function is passed an array of scores and the
//number of scores.  It returns the average of the scores.
float FindAverage(int scores[], int howMany)
{
     float sum = 0;      //holds the sum of all the scores

     //determine the sum of all of the scores
     for (int i = 0; i < howMany; i++)
          sum = sum + scores[i];

     //return the average
     return float(sum)/howMany;
}

//Place your AboveAverage() function definition here
void AboveAverage(int scores[], int& howMany, double avg)
{
	for (int i = 0; i < howMany; i++)
	{
		if (scores[i] >= avg)
		{
			cout << "Above average: " << scores[i] << endl;
		}
	
	}
	
}



//Place your LinearSearch() function definition here
int LinearSearch(int scores[], int max, int ToFind)
{
	for (int i = 0; i < max; i++)
	{
		if (scores[i] == ToFind)
		{
			return i;
		}
		else if (scores[i] == -99)
		{
			return -1;
		}
	}
	return -1;
}
