#include<iostream>
#include"sList.h"
#include<iomanip>
#include<string>
using namespace std;

//Constructor
sList::sList()
{

}


//~Destructor
sList::~sList()
{
	Node *cur = head;
	while(cur != nullptr)
	{
		//delete the Node pointed to by head
		head = head->next; // move head to the next Node
		cur->next = nullptr; 
		delete cur; //deallocate memory
		cur = head; //make cur point to the new Node
	}
}
		
	/*insertAtEnd()
	Function purpose: Append a song object to the end of the song list
	Expected input: Song object
	Expected return: N/A
	*/
void sList::insertAtEnd(SongType song)
{
	//create a new Node to hold the data
	Node *newSong = new Node;
	newSong->song = song;

	newSong->next = nullptr;
	Node *tail = head;
	// if the list is empty
	if (head == nullptr)
	{
		//make the new node as the head
		head = newSong;
		tail = head;
	}
	else if (tail != nullptr)
	{ 
		//insert the new node to the end of the List
		while(tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = newSong;
		tail = newSong;
	}

}

	/*insertAtEnd()
	Function purpose: Append a song object to the end of the song list, but takes manual user input
	Expected input: User input as directed by console 
	Expected return: Text prompts for user to input data
	*/
void sList::insertAtEnd()
{
	SongType song;
	//Get user input for new song
	cout << "Enter the song's rank: ";
	getline(cin, song.rank);
	cout << "Enter the song's artist ";
	getline(cin, song.singer);
	cout << "Enter the song's title ";
	getline(cin, song.song);
	cout << "Enter the song's year ";
	getline(cin, song.year);

	Node *newSong = new Node;
	newSong->song = song;
	
	newSong->next = nullptr;
	Node *tail = head;
	if (head == nullptr)
	{ 
		head = newSong;
	}
	else
	{
		while(tail->next != nullptr)
		{
			tail = tail->next;
		}	
		tail->next = newSong;
		tail = newSong;
	}
}

	/*deleteSong()
	Function purpose: Deletes song from songlist
	Expected input: Song title string
	Expected return: N/A, deletes song from song list
	*/
void sList::deleteSong(string songname)
{
	//cur will point to the item to delete
	Node* cur = head; 
	//prev will point to the item before cur
	Node* prev; 
	int i = 1;
	if(head == nullptr)
	//if the list is empty
	{
		// Not enough items in List.
		cout << "Not enough items in list\n";
	}
	else
	{	//Traverse the list to find the song
		//Delete the song if it is found
		while(cur->song.song != songname && cur->next != nullptr)
		{
			prev = cur;
			cur = cur->next;
			i++;
		}
		if(cur->song.song == songname)
		{
			prev->next = cur->next;
			delete cur;
		}
		else
		{
			cout << songname << " is not in this list.\n";
		}
	}
}

	/*displayList()
	Function purpose: Displays all songs in a given year
	Expected input: Year number as a string
	Expected return: Displays all songs in a given year
	*/
void sList::displayList(string year)
{
	//print the songs in given year
	cout << "--------------------------------\n";
	cout << "The song list for " << year << endl;
	
	Node *cur = head;
	int i = 1;
	while(cur != nullptr)
	{
		if (cur->song.year == year)
		{
			cout << i << ". " << cur->song.singer << " \"" <<  cur->song.song << "\"" << endl;
		}
		i++;
		cur = cur->next;
	}
}

	/*lookUpArtist()
	Function purpose: Displays all songs from the given artist
	Expected input: Song artist as a string
	Expected return: Displays all songs from the given artist
	*/
void sList::lookUpArtist(string artist)
{
	cout << "The search results for " << artist << endl;
	cout << "-------------------------------\n";
	//use while loop to search the artist 
	Node *cur = head;
	while(cur != nullptr)
	{ 
		if (cur->song.singer == artist)
		{
			//display all songs of the artist
			cout << cur->song.year << " " << left << setw(30) << cur->song.song << " " << cur->song.rank << endl;
		}	
		cur = cur->next;	
		
	}
	
}
