//This is the structure of the records that will be stored in the list.
#ifndef STRUCTS_H
#define STRUCTS_H

struct Record
{
    int acctNum;
    float balance;
};
typedef Record RecordType;

//This is the structure of one node in the linked list.
struct Node
{
    RecordType data;
    Node* next;
};
typedef Node NodeType;
typedef Node* NodePtrType;
#endif
