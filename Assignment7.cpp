// Assignment #7
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: Assignment7.cpp
//              This file is the main file to execute commands, it will read the input of the file "graph.txt" using ifstream.
//              The first line it reads is the number of nodes and the number of edges in the graph. Then the rest of the numbers
//              will be information about where the edge starts, ends, and its weight.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;
int main()
{
    ifstream inFile; // ifstream to read the file
    int w, s, e;     // w = weight, s = start,e = end
    int m, n;        // m = number of edges and n = number of nodes

    inFile.open("graph.txt"); // open the file
    inFile >> n;              // sets the first number equal to n
    inFile >> m;              // set the second number equal to m

    Graph *graph = new Graph(m, n); // make a graph object

    while (inFile >> s >> e >> w) // while loop that reads every line from the files
    {
        graph->insertEdge(s, e, w); // takes all the read information from the file and insertes it to the graph
        // stack->push(vert, s, e, w);
    }
    graph->printGraph(); // calls the print graph to run


    cout <<endl<< "Computing its circuit .....\n"<< endl;
    graph->DFS(); // Calls the DFS function to run

    inFile.close(); // closes the file reader
}