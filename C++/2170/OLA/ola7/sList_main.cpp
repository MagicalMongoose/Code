#include<iostream>
#include<fstream>
#include<string>
#include"sList.h"
using namespace std;

//prototypes
void readSong(SongType &, ifstream &);
void mainMenu();

int main()
{
	cout << "Welcome to Billboard Top Song (2015-2020) App\n\n";
	ifstream inFile;
	inFile.open("topsongs.dat");
	
	if(!inFile)
	{
		cout << "File Not Found!" << endl;
		exit(EXIT_FAILURE);
	}

	sList songList;
	SongType song;	

	//prime reading
	readSong(song,inFile); // read the first song from the datafile
	while(inFile)
	{	
		// insert the song to the end of songList
		songList.insertAtEnd(song);
		readSong(song,inFile);
	}
	
	char choice;	
	do
	{
		string reply;
		mainMenu();
		cout << "Enter your choice: ";
		string junk;
		cin >> choice;
		getline(cin, junk);
		switch(choice)
		{
		case '1':
			//prompt the user to enter a new song (singer, song, year, rank)
			readSong(song, inFile);
			//call the insertAtEnd method to insert the song to the end of the songList
			songList.insertAtEnd();
			break;
		case '2': 
			//prompt the user to enter the song to delete
			cout << "Please enter the song to delete: \n";
			getline(cin, reply);
			//call the deleteSong method to delete the song
			songList.deleteSong(reply);
			break;
		case '3':
			//prompt the user to enter the artist name 
			cout << "Please enter the artist name: \n";
			getline(cin, reply);
			//call the lookUpArtist method to search for the songs for artist
			songList.lookUpArtist(reply);	
			break;
		case '4':
			//prompt the user to enter the year
			cout << "Please enter the year: \n";
			cin >> reply;
			//call the displayList method to search for the songs for year
			songList.displayList(reply);
			break;
		case '5':
			cout << "Thank you!" << endl;
			break;
		default:
			cout << "Invalid Option." << endl;
			break;
		}
	}while(choice != '5');

	inFile.close();

	return 0;
}

	/*readSong()
	Function purpose: Take the input from a data file and save them to a song object (function used in loop)
	Expected input: The file to read data from and the object to store the data in
	Expected return: N/A
	*/
void readSong(SongType &song,ifstream &inFile)
{
	getline(inFile, song.rank);
	getline(inFile, song.singer);
	getline(inFile, song.song);
	getline(inFile, song.year);
}

	/*mainMenu()
	Function purpose: Show the user the main menu
	Expected input: N/A
	Expected return: Console output of text menu display
	*/
void mainMenu()
{
	//display the menu to ther user
	cout << "-------------------------------\n";
	cout << endl;
	cout << "1. Add a song\n"; //1 --> readSong()
	cout << "2. Delete a song\n";
	cout << "3. Look Up an Artist\n";
	cout << "4. Display all songs by year\n";
	cout << "5. Exit\n";
}

