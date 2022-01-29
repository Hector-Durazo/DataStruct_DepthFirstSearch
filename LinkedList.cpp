// Assignment #7
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: LinkedList.cpp
//              In this file we created a LinkedList data structure that contains nodes with an adjacency vertex, and weight.
//              The linked list has functions such as printList, insertEdge, and sizeOfLinked. The insertEdge method also inserts
//              the nodes in order of node number and its weight.
//
//

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() // Constructor to initialize the linked list
{
    head = NULL;
}

// Destructor
LinkedList::~LinkedList() // Deallocates memory for the node object;
{
    Edge *next = head;

    while (next)
    {
        Edge *del = next;
        next = next->next;
        delete del;
    }
}

int LinkedList::sizeOfLinked()
{
    int count = 0;        // Initialize count
    Edge *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::insertEdge(int edgenum, int Weight, int parent) // inserter the new node in order
{
    try // try and catch for when there is no memory to create a new project
    {
        Edge *newEdge = new Edge;

        newEdge->weight = Weight;   // assigning the new edge a weight
        newEdge->edgeNum = edgenum; // assigning the new edge a number
        newEdge->parent = parent;   
        newEdge->next = NULL;       // assigning the next edge to NULL

        Edge *ptr = head;  // create an edge pointer
        Edge *ptr2 = head; // another edge pointer
        int temp;          // create a tmep int

        if (head == NULL || head->edgeNum >= newEdge->edgeNum) // if that checks if the head is null or if the head is greater than the new edge
        {
            newEdge->next = head; // edge.nexty is = to head
            head = newEdge;       // head becomes the new node
            return;
        }

        while (ptr->next != NULL && ptr->next->edgeNum < newEdge->edgeNum) // while the ptr is not Null and the nodeNum is less than the new edge
        {
            ptr = ptr->next; // list will travers to the next node
        }
        newEdge->next = ptr->next;
        ptr->next = newEdge;

        while (ptr2->next != NULL) // this will sort the nodes by their weight
        {
            if (ptr2->edgeNum == ptr2->next->edgeNum)
            {
                if (ptr2->weight > ptr2->next->weight)
                {
                    temp = ptr2->weight;
                    ptr2->weight = ptr2->next->weight;
                    ptr2->next->weight = temp;
                }
            }
            ptr2 = ptr2->next;
        }
    }
    catch (bad_alloc &badAlloc) // will catch out of memory error
    {
        std::cerr << "Not enough memory! " << badAlloc.what() << endl;
        return;
    }
}

Edge* LinkedList::search(int adj) //returns nonvisted adj node
{
	Edge* temp = head;
	while(temp != nullptr)
	{
		if(temp->edgeNum == adj && temp->notUsed)
		{
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}


void LinkedList::printList() // Prints the entire linked list
{
    Edge *pointer = new Edge;
    pointer = head;
    // traverses through all nodes in the linked list
    if (pointer == NULL)
    {
        cout << "No adjacent Vertex" << endl;
    }
    while (pointer != NULL)
    {
        cout << "To: " << pointer->edgeNum << " with weight " << pointer->weight << endl;
        pointer = pointer->next;
    }
}