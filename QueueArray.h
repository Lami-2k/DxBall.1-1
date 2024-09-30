#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary
    int queueLen;
    int capacity;

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        //write your code here. Initialize additional private variables if necessary
        queueLen=-1;
        capacity = 1;
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        queueLen = -1;
        capacity = initialCapacity;
    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array

        //write your code here. Copy the elements from the old array to the new array

         for(int i=0;i<=(queueLen);i++)
        {            
            newArray[i]= array[i];
        }

        delete[] array; // Free old memory

        //write your code here. Update the capacity and array pointers
        array = newArray;
        capacity = newCapacity;
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        queueLen++;
        array[queueLen]=x;
        
        if ((queueLen+1)>=(capacity))
        {
            resize((capacity)*2);
        }
    }

    // Remove and return the peek element
    int dequeue()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if(isEmpty())
            return -1;
       //remove the peek element and return it
        int value= array[0];
        int *newArray = new int[capacity];
        for(int i=0;i<=(queueLen-1);i++)
        {            
            newArray[i]= array[i+1];
        }
        delete[] array;
        array = newArray;
        queueLen--;
       //resize the array if necessary
       if(queueLen>0 && (queueLen+1)<(capacity/4))
        {
            resize((capacity)/2);
        }
        else if(queueLen==0)
        {
            resize(2);
        }
        else if(queueLen<0)
        {
            resize(1);
        }
        return value;
    }

    // Return the peek element without removing it
    int peek()
    {
        //write your code here. Check if the queue is empty and return -1 if it is.
        if(isEmpty())
            return -1;
        //return the peek element
        else
            return array[0];
    }

    // Return the number of elements in the queue
    int length()
    {
        //write your code here. Return the number of elements in the queue
        return (queueLen+1);
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        //write your code here. Return true if the queue is empty, false otherwise
        if(queueLen<0)
            return true;
        else
            return false;
    }

    // Clear the queue
    void clear()
    {
        //write your code here. Clear the queue. resize the array to 1
        while(queueLen!=-1)
        {
            int val=dequeue();
        }
        resize(1);
    }
};
