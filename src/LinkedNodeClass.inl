#include "LinkedNodeClass.h"

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This list node template will be the data type for individual
//nodes of a doubly-linked list data structure.

template <class T>
LinkedNodeClass<T>::LinkedNodeClass(
  LinkedNodeClass<T> * inPrev,
  const T &inVal,
  LinkedNodeClass<T> * inNext)
  {
    prevNode = inPrev; 
    nodeVal = inVal; 
    nextNode = inNext; 
  }

template <class T>
T LinkedNodeClass<T>::getValue() const
{
  return nodeVal;
}

template <class T>
LinkedNodeClass<T> * LinkedNodeClass<T>::getNext() const
{
  return nextNode;
}

template <class T>
LinkedNodeClass<T> * LinkedNodeClass<T>::getPrev() const
{
  return prevNode;
}

template <class T>
void LinkedNodeClass<T>::setNextPointerToNull()
{
  nextNode = 0;
}

template <class T>
void LinkedNodeClass<T>::setPreviousPointerToNull()
{
  prevNode = 0;
}

template <class T>
void LinkedNodeClass<T>::setBeforeAndAfterPointers()
{
  if(prevNode != 0)
  {
    prevNode->nextNode = this;
  }
  
  if(nextNode != 0)
  {
    nextNode->prevNode = this;
  } 
}

