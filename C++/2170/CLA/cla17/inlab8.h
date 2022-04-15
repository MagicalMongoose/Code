//FILE:  inlab8.h

#ifndef LIST_CLASS_H
#define LIST_CLASS_H

struct Record;
typedef Record RecordType;
struct Node;
typedef Node* NodePtrType;
typedef Node NodeType;

class ListClass
{
public:
    //constructor
    ListClass();

    //destructor
    ~ListClass();

    //insertion operations for the linked list
    void insertAtEnd(RecordType);
    
    void insertAtHead(RecordType);

    void insertInMiddle(RecordType, int);

    void insertInOrder(RecordType);

    //function to print out records in the list
    void printList();

    //function to count the number of items in a list
    int countItems();

    //deletion operations for the linked list
    void deleteAtHead();

    void deleteAtEnd();

    void deleteIthNode(int);

    void deleteItem(RecordType);
private:
    NodePtrType head;   //points to beginning of the list
};
#endif
