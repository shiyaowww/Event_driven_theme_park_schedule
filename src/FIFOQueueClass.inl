#include "FIFOQueueClass.h"

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This template will store a simple fisrt-in-first-out 
//data structure.

template <class T>
FIFOQueueClass<T>::FIFOQueueClass()
{
  head = 0;
  tail = 0;
}

template <class T>
FIFOQueueClass<T>::~FIFOQueueClass()
{
  clear();
}

template <class T>
void FIFOQueueClass<T>::enqueue(
  const T &newItem)
{
  LinkedNodeClass<T> * newNode = 0;
  
  if(head == 0)
  {  
    newNode = new LinkedNodeClass<T>(
      0,
      newItem,
      0);
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode = new LinkedNodeClass<T>(
      0,
      newItem,
      head);
    head = newNode;
    newNode->setBeforeAndAfterPointers();
  } 
}

template <class T>
bool FIFOQueueClass<T>::dequeue(
  T &outItem)
{
  bool isNotEmpty = true;
  LinkedNodeClass<T> * temp = tail;

  if(temp == 0)
  {
    isNotEmpty = false;
  }
  else if(temp->getPrev() == 0)
  {
    outItem = temp->getValue();
    head = 0;
    tail = 0;
  }
  else
  { 
    outItem = temp->getValue();
    tail = temp->getPrev();
    tail->setNextPointerToNull();
  }

  delete temp;
  return isNotEmpty;
}

template <class T>
void FIFOQueueClass<T>::print() const
{
  LinkedNodeClass<T> * temp = head;

  while(temp != 0)
  {  
    cout << temp->getValue() << " ";
    temp = temp->getNext();
  }

  cout << endl;
}

template <class T>
void FIFOQueueClass<T>::clear()
{
  T outItem;

  while(tail != 0)
  {
    dequeue(outItem);
  }    
}
