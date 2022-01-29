// Assignment #7
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: stack.h
//              This file consturts a Stack data structure containing Edges with two vewrtices and wight using an array. This specific
//              stack was mad using LIFO (last in first out) feature. This will be used to keep track of the circuit and a temp stack.
//
#include <iostream>
using namespace std;

struct vertex // vertext struct that contains the start, end, and weight
{
    int start;
    int end;
    int weight;
};

class Stack // Stack class variables and method instantiation
{
private:
    int top;
    int m;
    vertex **verStack;

public:
    Stack();
    ~Stack();
    vertex *pop();
    void push(int, int, int);
    void printStack();
    void printFinal();
};

Stack::Stack() // stack class constructor
{
    m = 100;
    verStack = new vertex *[m];
    top = 1;
}

void Stack::push(int s, int e, int w) // push method that adds a node to the top of the stack
{
    vertex *newVert = new vertex();
    newVert->start = s;
    newVert->end = e;
    newVert->weight = w;
    if (top >= m) // if at max campacity
        return;
    else
    {
        verStack[top] = newVert;
        top++; // adds to remember place in stack
    }
}

vertex *Stack::pop()
{
    if (top == 1) // If empty
    {
        cout << "Stack is empty \n";
        return NULL;
    }
    // Get top edge
    vertex *edge = verStack[--top];
    // Swap vertices and recorrect for 0 index

    int temp = edge->start;
    edge->start = edge->end;
    edge->end = temp;

    return edge; // Returns top edge and decrements.
}

void Stack::printStack() // method that prints the stack
{
    if (top == 1) // if the stack is empty print "stack is empty"
        cout << "Empty" << endl;
    else // traverses through the stack and prints every element in it
    {
        for (int i = 1; i < top; i++)
        {
            cout << "(" << verStack[i]->start << "," << verStack[i]->end << ") ";
        }
        cout << endl;
    }
}

void Stack::printFinal() //print the final circuit
{
    for (int i = 1; i < top; i++)
    {
        cout << "(" << verStack[i]->start << "," << verStack[i]->end << ") ";
        cout << endl;
    }
}
