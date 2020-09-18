#ifndef _FIFOQUEUECLASS_H_
#define _FIFOQUEUECLASS_H_
 
#include <iostream>

#include "LinkedNodeClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This template will store a simple fisrt-in-first-out 
//data structure.

template <class T>
class FIFOQueueClass
{
  private:
    //Points to the first node in a queue, NULL if queue is empty
    LinkedNodeClass<T> * head;
    //Points to the last node in a queue, NULL if queue is empty
    LinkedNodeClass<T> * tail;
    
  public:
    //Default ctor, initializes queue to be empty
    FIFOQueueClass();
    //Dtor, frees up dynamic momory when the object gets destroyed
    ~FIFOQueueClass();
    //Inserts the value provided to the front of the queue
    void enqueue(
      const T &newItem);
    //Takes an item from the end of the queue and sets the reference
    //parameter to the removed item. Returns true if queue is not empty  
    bool dequeue(
      T &outItem);
    //Prints the contents of the queue
    void print() const;
    //Clears the queue to an empty state without memory leak
    void clear();
};

#include "FIFOQueueClass.inl"

#endif

