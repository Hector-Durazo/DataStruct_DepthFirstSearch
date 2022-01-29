// Assignment #7
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: Graph.h
//              The graph file has several functions. First it takes the linked list and inserts it into its corresponding place.
//              It can also print that graph. Additionally, it contains the methods DFT and DFS_VISIT where the Depth first search
//              computation is being done and prints that out as well.
//
//
#include <iostream>
#include "LinkedList.cpp"
#include "stack.h"

class Graph
{
public:
    // LinkedList* adjList;
    LinkedList *adjList;
    Stack *stack;
    Stack *tempStack;
    Stack *circuit;

    int m, n;
    int time = 0;
    Graph(int, int);
    void insertEdge(int, int, int);
    void printGraph();
    void DFS();
    void DFS_VISIT(Edge *);
};

Graph::Graph(int M, int N) // graph constructor
{
    m = M; // gets the size of the graph
    n = N;
    adjList = new LinkedList[n + 1]; // creates a new linkedlist object
    tempStack = new Stack();         // creates
    circuit = new Stack();
}

void Graph::insertEdge(int s, int e, int w) // insert all the adjacent vertext to an array/ making the graph
{
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            adjList[i].insertEdge(e, w, i);
        if (i == e)
            adjList[i].insertEdge(s, w, i);
    }
}

void Graph::printGraph() // print the graph
{
    cout << "The Graph contains:\n"
         << "-------------------";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nFrom: " << i << " with its degree " << adjList[i].sizeOfLinked() << endl;
        adjList[i].printList();
    }
}

void Graph::DFS() // this is a modified Depth Fist Search that goes to ever node
{
    for (int i = 1; i < n; i++)
    {
        if (adjList[i].head->notUsed) // if the adjList head has not been used
        {
            DFS_VISIT(adjList[i].head); // pass the head to DFS_VISIT
        }
    }
    cout << "The circuit is:\n";

    circuit->printFinal(); // print the final circuit
}

void Graph::DFS_VISIT(Edge *node)
{
    node->notUsed = false; // mark node as visited
    Edge *adjNode = adjList[node->edgeNum].search(node->parent); // find adj node using search

    adjNode->notUsed = false; // maked the node as visited
    vertex *newEdge = new vertex(); // create a new vertex
    newEdge->start = node->parent;  // set the new edge start to the nodes parent
    newEdge->end = node->edgeNum;   // set the new edge end to the nodes edgeNum
    newEdge->weight = node->weight; // set the new weight start to the nodes weight

    tempStack->push(newEdge->start, newEdge->end, newEdge->weight); // Push visited edge to stack

    cout << "Circuit: "; // print out the circuit
    circuit->printStack();
    cout << "Stack: "; // print out the stack
    tempStack->printStack();
    cout << "\n";

    Edge *adjHead = adjList[adjNode->parent].head; // create a new Edge adjHead that is equal to the prev head

    while (adjHead != nullptr) // travers through the adjHead
    {
        if (adjHead->notUsed) // if the adjHead has not been visited then
        {
            DFS_VISIT(adjHead); // recursive call
        }
        adjHead = adjHead->next;
    }

    vertex *ver = tempStack->pop(); // there are no more unused edges
    circuit->push(ver->start, ver->end, ver->weight);

    cout << "Circuit: "; // print out the circuit
    circuit->printStack();
    cout << "Stack: ";// print out the stack
    tempStack->printStack();
    cout << "\n";
}