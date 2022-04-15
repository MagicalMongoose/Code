#include "intsllist.h"
#include <iostream>
using namespace std;


void IntSLList::insertInOrder(int)
{
    //Adds each value to the list in ascending order. 
    //In the event of duplicate values are added to the list, 
    //the newly added node must come after those with the same value already in the list 
    //cout << "Adding " << " to the list\n";
    //IntSLLNode newNode = num;
}

int IntSLList::deleteVal(int)
{
    //This function removes the first node instnace having the specified value from the list. 
    //In the event items having the same value are in the list, 
    //this function should only remove the first instance of the value. 

    return -1; //this should return the deleted value
};

void IntSLList::deleteAllVal(int el)
{
    //This function must remove all instances of nodes having the specified value from the list.

};

void IntSLList::clearList()
{
    
};

