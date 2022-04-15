//File:        clab14a.cc
//Author:
//Purpose:     This program reads data for a computer science
//             closed lab section.
//Input:       Input for this program is from the external data
//             file labscores.dat.  The first two entries in the file
//             are the number of students in the class and the number
//             of closed labs the class has finished.
// 
//             For each student, their closed labs are input from the
//             following lines of the file.   
//
//Limitations: It is assumed that there will be no more than
//             MAX_STUDENTS students in the class and there will be
//             no more than MAX_LABS labs.

//include files...
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//global constants...
const int MAX_STUDENTS=40;          //maximum number of students
const int MAX_LABS=14;              //maximum number of closed labs

//function prototypes...
//function to read labs from the data file
void ReadScores(int labScores[][MAX_LABS], int& numStudents,
                int& numLabs, ifstream& myin);

//your function prototypes should go here!!!
void printScores(int labScores[][MAX_LABS], int numStudents, int numLabs);

void studentAvg(int labScores[][MAX_LABS], int numStudents, int numLabs);

void labAvg(int labScores[][MAX_LABS], int numStudents, int numLabs);

int main()
{
	//local declarations...
	int numStudents;                          //how many students are in the class
	int numLabs;                              //how many closed labs
	ifstream myin;                            //input file stream
	int labScores[MAX_STUDENTS][MAX_LABS];    //holds lab scores

	myin.open ("labscores.dat");              //open the file for input
	if (!myin)
	{
    	cout << "Could not open labscores.dat\n";
    	return 1;
	}

	//read in the data for all students in the class
	ReadScores(labScores, numStudents, numLabs, myin);

	//print the data for all students in the class
	//your print function should be called here!!!!!
	printScores(labScores, numStudents, numLabs);

	//find each student's lab average -- use the StudentAvg()
	//function here.
	studentAvg(labScores, numStudents, numLabs);

	//find and print the average score made on each individual lab
	//use your LabAvg() function here
 	labAvg(labScores, numStudents, numLabs);

	//end of main...
	return 0;
}

//Function:    ReadScores()
//Purpose:     This function reads data for students in a closed
//             lab class.  Data is read from the input file stream
//             myin.  The number of students in the lab and the
//             number of closed labs finished by each student are read
//             first.  Next, for each student, their closed labs
//             are read into the two-d array labscores.
//Assumption:  MAX_LABS is a global constant which has been defined
//             previously.

void ReadScores(int labScores[][MAX_LABS],  //OUT: Holds the lab scores
                int& numStudents,           //OUT:  # of students
                int& numLabs,               //OUT: Number of Labs
                ifstream& myin)             //IN: Input file stream 
         
{
   //local declarations...
   int student;                            //controls which student's labs are read
   int lab;                                //controls which lab is being read

   //get the number of students in the class
   myin >> numStudents >> numLabs;

   //outer loop controls which student(row) is being read
   for (student = 0; student < numStudents; student++)
   {
      //inner loop controls which lab(column) is being read
      for (lab = 0; lab < numLabs; lab++)
         myin >> labScores[student][lab];
   }
   return;
}

//Place the definition of your function to print the scores here
void printScores(int labScores[][MAX_LABS], int numStudents, int numLabs)
{
	for(int i = 0; i < numStudents; i++)
	{
		cout << "Student " << i+1 << ": ";
		for(int j = 0; j < numLabs; j++)
		{
			cout << fixed << setw(2) << labScores[i][j]  << " ";
		}
		cout << endl;
	}
}

//Place the definition of the StudentAvg() function here
void studentAvg(int labScores[][MAX_LABS], int numStudents, int numLabs)
{
	int sum = 0;
	float avg = 0;
	for(int i = 0; i < numStudents; i++)
	{
		for(int j = 0; j < numLabs; j++)
		{
			sum += labScores[i][j];
		}	
		avg = (float)sum/numLabs;
		cout << "Student " << i+1  << " Average: " << fixed << setprecision(2) << avg << endl;
		//reset numbers for next student
		sum = 0;
		avg = 0;
	}
}

//Place the definition of the LabAvg() function here
void labAvg(int labScores[][MAX_LABS], int numStudents, int numLabs)
{
	int sum = 0;
	float avg = 0;
	for(int i = 0; i < numLabs; i++)
	{
		for(int j = 0; j < numStudents; j++)
		{
			sum += labScores[j][i];
		}
		avg = (double)sum/numStudents;
		cout << "Lab " << i+1 << " Average: " << fixed << setprecision(2) << avg << endl;
		//reset numbers for next student
		sum = 0;
		avg = 0;
	}
}	
