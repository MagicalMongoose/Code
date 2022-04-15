/*Please develop a Rock Paper Scissor game for two players.
Please complete this starter file according to the corresponding instructions.
Author: Drew Lickman
Date: 9/27/21
Professor: Dr. Yang
*/

#include<iostream>
#include<cstdlib> // for rand() and srand() function
#include<ctime> // for time()
using namespace std;

//Global Constant Variables
const int ROCK = 1;
const int PAPER = 2;
const int SCISSOR = 3;
const int PERSON_WIN = 1;
const int COMPUTER_WIN = 2;
const int DRAW = 0;

//function prototypes
//(1)
void welcomeMenu();
//(2)
void printWord(int opt);
//(3)
int rockPaperScissor(int person, int computer);
//(4)
int getUserInput();

//Main function
int main()
{
    srand(time(NULL)); //this is for rand number

    //(1) declare an integer variable named userScore initialized with 0;
	int userScore = 0;
    //(2) declare an integer variable named computerScore initialied with 0;
	int computerScore = 0;
    //(3) Declare a character variable named response
	char response;
    //(4) Call the Welcome Menu Function
	welcomeMenu();
    do
    {
        //(5) Please declare an integer variable named userInput
        // and assign the value returned by calling the function getUserInput() to userInput;
		int userInput = getUserInput();
        //(6) declare an integer variable named computerInput
        // and assign a random number (1,2,3) generated using the rand() function to computerInput;
		int computerInput = rand()%3+1; 
              cout << "-----------------------------" << endl;
              cout << "    User chose: ";
        //(7) Please call function printWord to print user's chose with userInput as input
		printWord(userInput);
              cout << "Computer chose: ";
        //(8) Please call function printWord to print computer's chose with computerInput as input
		printWord(computerInput);
        //(9) Please declare an integer variable named result
        //and assign the returned value by calling function rockPaperScissor
        //The inputs for the function rockPaperScissor is: userInput and computerInput
		int result = rockPaperScissor(userInput, computerInput);
              if(result == DRAW) //(10) if the result is draw
           //(11) print out it is a draw
           cout << "It is a draw this round." << endl;
        else if(result == PERSON_WIN) //(12) if the result is person wins
        {
            //(13) Print out person wins this round.
			cout << "Player won this round!" << endl;
            //(14) update userScore by using increment operator
			userScore++;
        }
        else if(result == COMPUTER_WIN) // (15) if the result is computer wins
        {
            //(16) Print out computer wins this round.
			cout << "Computer won this round!" << endl;
            //(17) update computerScore by using increment operator
			computerScore++;
        }

        cout << "-----------------------------" << endl;
        cout << "Total scores: " << endl;
        cout << "               User score: " << userScore << endl;
        cout << "           Computer score: " << computerScore << endl;
        cout << "-----------------------------" << endl;

        cout << "If you want to continue please enter Y/y." << endl;
        cout << "Please enter N/n to terminate." << endl;
        //(18) user enter character from the keyboard.
		cin >> response;
    }while(response == 'Y' || response == 'y' );//(19) The program will terminate if the user enter 'N/n'
    //end of while

    cout << "=========================================" << endl;
    cout << "Final Score: " << endl;
    cout << "               User score: " << userScore << endl;
    cout << "           Computer score: " << computerScore << endl << endl;

    if(userScore == computerScore) //(20) if userScore is equal to computerScore
        //(21) print out the game is a draw
		cout << "The game is a draw!" << endl;
    else if(userScore > computerScore)//(22) if userScore is larger than computerScore
        //(23) print out user wins the game.
		cout << "The player wins the game!" << endl;
    else
        //(24)print out computer wins the game.
		cout << "The computer wins the game!" << endl;

    cout << "Thank you!" << endl;
    cout << "=========================================" << endl;
    return 0;
}

//Function Name: rockPaperScissor
//Purpose: Compare the rock paper scissor result with two players
//Input: person's option, and computer's option
//Output: PERSON_WIN or COMPUTER_WIN, or Draw
int rockPaperScissor(int person, int computer)
{
    //Please use ROCK, PAPER, SCISSOR here instead of 1, 2, 3

    int result = 0;

    if(person == ROCK && computer == PAPER)//(1) if person is ROCK and computer is PAPER
        //(2) computer wins
        result = COMPUTER_WIN;
    else if(person == ROCK && computer == SCISSOR)//(3) if person is ROCK and computer is SCISSOR
        //(4) person wins
		result = PERSON_WIN;
    else if(person == PAPER && computer == ROCK)//(5) if person is PAPER and computer is ROCK
        //(6) person wins
		result = PERSON_WIN;
    else if(person == PAPER && computer == SCISSOR)//(7) if person is PAPER and computer is SCISSOR
        // (8) computer wins;
		result = COMPUTER_WIN;
    else if(person == SCISSOR && computer == ROCK)//(9) if person is SCISSOR and computer is ROCK
        //(10) computer wins
		result = COMPUTER_WIN;
    else if(person == SCISSOR && computer == PAPER)//(11) if person is SCISSOR and computer is PAPER
       //(12) person wins
		result = PERSON_WIN;
    else
       //(13) it is a draw
       result = DRAW;

    return result;
}

//Function Name: getUserInput
//Purpose: ask the user to enter the options from the keyboard
//Input: empty
//Output: user's options: 1 or 2 or 3
int getUserInput()
{
    int choice;
    do{
            cout << "1. Rock " << endl;
            cout << "2. Paper " << endl;
            cout << "3. Scissor " << endl;
            //(1) prompt the user to enter options 1, or 2 or 3
			cout << "Enter your choice: ";
            //(2) user enter a number to choice
			cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3);//(4) the while loop continue if the user did not enter 1 or 2 or 3

    return choice;
}

//Function Name: printWord
//Purpose: print out Rock Paper Scissor based on the number option
//Input: option number 1 or 2 or 3
//Output: Rock or Paper or Scissor
void printWord(int opt)
{
    //(1) if opt is 1
	//(2) print out Rock
	if (opt == 1)
	{ cout << "Rock" << endl; }
    //(3) else if opt is 2
    //(4) print out Paper
	if (opt == 2)
	{ cout << "Paper" << endl; }
    //(5) else print out Scissor
	else 
	{ cout << "Scissor" << endl; }
}

//Function Name: welcomeMenu
//Purpose: prompt the program welcome message
//Input: empty
//Output: void
void welcomeMenu()
{
	cout << "==========================" << endl;
	cout << "Welcome to Rock Paper Scissors" << endl;
	cout << "==========================" << endl; 
}

