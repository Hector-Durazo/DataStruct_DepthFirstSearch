README

Assignment7.cpp
    This file is the main file to execute commands, it will read the input of the file "graph.txt" using ifstream. 
    The first line it reads is the number of nodes and the number of edges in the graph. Then the rest of the numbers
    will be information about where the edge starts, ends, and its weight.

LinkedList.h
    This is a header file for LinkedList, that instantiates variables and methods.

LinkedList.cpp 
    In this file we created a LinkedList data structure that contains nodes with an adjacency vertex, and weight.
    The linked list has functions such as printList, insertEdge, and sizeOfLinked. The insertEdge method also inserts
    the nodes in order of node number and its weight.

Graph.h
    The graph file has several functions. First it takes the linked list and inserts it into its corresponding place.
    It can also print that graph. Additionally, it contains the methods DFT and DFS_VISIT where the Depth first search
    computation is being done and prints that out as well.

stack.h
    This file consturts a Stack data structure containing Edges with two vewrtices and wight using an array. This specific
    stack was mad using LIFO (last in first out) feature. This will be used to keep track of the circuit and a temp stack. 

Makefile
    The Makefile compiles Assignment7.cpp, LinkedList.cpp, Graph.h, and stack.h