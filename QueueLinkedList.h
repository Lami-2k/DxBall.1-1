#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    int currentSize;
    Node *lastNode;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        currentSize = 0;
        lastNode = nullptr;
    }

    // Enqueue an element onto the queueu
    void enqueue(int x)
    {
       // write your code here. Create a new node with the value x and enqueue it onto the queue
       // update the peekNode and currentSize
       Node *newNode = new Node(x);
       if(currentSize==0)
            peekNode=newNode;
       else
            lastNode->next=newNode;
       lastNode = newNode;
       currentSize++;
    }

    // Remove and return the peek element
    int dequeue()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // dequeue the peek element and return it
        // update the peekNode and currentSize
        // delete the node that was dequeued
        if(isEmpty())
            return -1;
        else
        {
            int value=peekNode->data;
            Node* tempNode = peekNode->next;
            delete peekNode;
            peekNode = tempNode;
            currentSize--;
            return value;
        }
    }

    // Return the peek element without removing it
    int peek()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // return the peek element
        if(isEmpty())
            return -1;
        else
            return peekNode->data;
    }

    // Return the number of elements in the queueu
    int length()
    {
        // write your code here. Return the number of elements in the queueu
        return currentSize;
    }

    // Check if the queueu is empty
    bool isEmpty()
    {
        // write your code here. Return true if the queueu is empty, false otherwise
        if(currentSize == 0)
            return true;
        else 
            return false;
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};