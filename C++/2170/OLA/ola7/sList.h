#ifndef SLIST_H
#define SLIST_H

#include<string>
using namespace std;

//Please declare the struct type 
//SongType
struct SongType
{
	string singer;
	string song;
	string year;
	string rank;
	
};

class sList
{
	private:
		//Declaration a structure of the Nodes
		struct Node
		{
			SongType song;
			Node *next;
		};
		// List head Pointer
		Node *head = nullptr;

	public:
		//Constructor
		sList();
		//~Destructor
		~sList();
		
		//Linked List Operations 
		//Insertion Operations for the linked list
		void insertAtEnd(SongType song);
		//Get user input to append to songList 
		void insertAtEnd(); 
		//Print out data in the list
		void displayList(string year);
		//Search for the artist
		void lookUpArtist(string artist);
		//deletion oprations for the linked list
		void deleteSong(string songname);
};
#endif
