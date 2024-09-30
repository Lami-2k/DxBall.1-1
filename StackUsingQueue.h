#include <iostream>
#include "QueueLinkedList.h"
using namespace std;

class Stack
{
private:
    
    //write your code here. Add additional private variables if necessary
    Queue* Q1= new Queue;
    Queue* Q2= new Queue;
    int currentSize;
    int capacity;

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
        currentSize = 0;
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
        capacity=initialCapacity;
    }

    // Destructor
    ~Stack()
    {
        Q1->clear();
        Q2->clear();
        delete Q1;
        delete Q2;
        currentSize=0;
        capacity=0;
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        Queue* temp= Q1;
        Q2->enqueue(x);
        while(!Q1->isEmpty())
        {
            int value= Q1->dequeue();
            Q2->enqueue(value);
        }
        Q1=Q2;
        Q2=temp;
        currentSize++;
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       if(Q1->isEmpty())
         return -1;
       currentSize--;
       return Q1->dequeue();
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        if(Q1->isEmpty())
            return -1;
        return Q1->peek();
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return currentSize;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        if(Q1->isEmpty())
            return true;
        else
            return false;
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        while(!isEmpty())
        {
            int value=Q1->dequeue();
        }
        currentSize=0;
    }
};
