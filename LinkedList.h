// Assignment #7
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: LinkedList.h
//              This is a header file for LinkedList, that instantiates variables and methods.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string> //to use strings
using namespace std;

struct Edge // struct Edge represents Edge info
{
    int edgeNum;
    int weight;
    int parent;
    int time;
    bool notUsed;
    struct Edge *next;

    Edge() // constructor to initialize Edge
    {
        parent = 0;
        time = 0;
        edgeNum = 0;
        weight = -1;
        notUsed = "1";
    }
};

class LinkedList // class LinkedList will contains a linked list of edges
{
public:
    LinkedList();
    ~LinkedList();

    struct Edge *head;
    Edge* search(int);
    void insertEdge(int edgeNum, int weight,int parent);
    int sizeOfLinked();
    void printList();
};

#endif