#include "SortedListClass.h"

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This sorted list template will be a doubly-linked-list of
//LinkNodeClass objects, each of which contains one element.

template <class T>
SortedListClass<T>::SortedListClass()
{
  head = 0;
  tail = 0;
}

template <class T>
SortedListClass<T>::SortedListClass(
  const SortedListClass<T> &rhs)
{
  head = 0;
  tail = 0;
  int i = 0;
  T valInNewNode;
  int numElemsRhs = rhs.getNumElems();
  LinkedNodeClass<T> * newNode = 0;

  for(i = 0; i < numElemsRhs; i++)
  {
    rhs.getElemAtIndex(i, valInNewNode);
    if(i == 0)
    {
      newNode = new LinkedNodeClass<T>(
        0,
        valInNewNode,
        0);
      head = newNode;
      tail = newNode;
    }
    else 
    {
      newNode = new LinkedNodeClass<T>(
        tail,
        valInNewNode,
        0);
      tail = newNode;
      newNode->setBeforeAndAfterPointers();
    }      
  }
}

template <class T>
SortedListClass<T>::~SortedListClass()
{
  clear();
}

template <class T>
void SortedListClass<T>::clear()
{
  T theVal;

  while(head != 0)
  {
    removeFront(theVal);
  }
}

template <class T>
void SortedListClass<T>::insertValue(
  const T &valToInsert)
{
  LinkedNodeClass<T> * temp = head;
  LinkedNodeClass<T> * newNode = 0;

  if(temp == 0)
  { 
    newNode = new LinkedNodeClass<T>(
      0,
      valToInsert,
      0);
    head = newNode;
    tail = newNode;
  }
  else
  {
    while(temp != 0 && temp->getValue() <= valToInsert)
    {
      temp = temp->getNext();
    }

    if(temp == 0)
    {
      newNode = new LinkedNodeClass<T>(
        tail,
        valToInsert,
        0);
      tail = newNode;
    }
    else if(temp->getPrev() == 0)
    {
      newNode = new LinkedNodeClass<T>(
        0,
        valToInsert,
        head);
      head = newNode;
    }
    else 
    {
      temp = temp->getPrev();

      newNode = new LinkedNodeClass<T>(
        temp,
        valToInsert,
        temp->getNext());
    }

    newNode->setBeforeAndAfterPointers();
  }
}

template <class T>
void SortedListClass<T>::printForward() const
{
  LinkedNodeClass<T> * temp = head;

  cout << "Forward List Contents Follow:" << endl;

  while(temp != 0)
  {
    cout << "  " << temp->getValue() << endl;
    temp = temp->getNext();
  }

  cout << "End of List Contents" << endl;
}

template <class T>
void SortedListClass<T>::printBackward() const
{
  LinkedNodeClass<T> * temp = tail;

  cout << "Forward List Contents Follow:" << endl;

  while(temp != 0)
  {
    cout << "  " << temp->getValue() << endl;
    temp = temp->getPrev();
  }

  cout << "End of List Contents";
}

template <class T>
bool SortedListClass<T>::removeFront(
  T &theVal)
{
  bool isNotEmpty = true;
  LinkedNodeClass<T> * temp = head;

  if(temp == 0)
  {
    isNotEmpty = false;
  }
  else if(temp->getNext() == 0)
  {
    theVal = temp->getValue();
    head = 0;
    tail = 0;
  }
  else
  {
    theVal = temp->getValue();
    head = temp->getNext();
    head->setPreviousPointerToNull();
  }

  delete temp;
  return isNotEmpty;
}

template <class T>
bool SortedListClass<T>::removeLast(
  T &theVal)
{
  bool isNotEmpty = true;
  LinkedNodeClass<T> * temp = tail;

  if(temp == 0)
  {
    isNotEmpty = false;
  }
  else if(temp->getPrev() == 0)
  {
    theVal = temp->getValue();
    head = 0;
    tail = 0;
  }
  else
  {
    theVal = temp->getValue();
    tail = temp->getPrev();
    tail->setNextPointerToNull();
  }

  delete temp;
  return isNotEmpty;
}

template <class T>
int SortedListClass<T>::getNumElems() const
{
  int numElems = 0;
  LinkedNodeClass<T> * temp = head;

  while(temp != 0)
  {
    numElems++;
    temp = temp->getNext();
  }

  return numElems; 
}

template <class T>
bool SortedListClass<T>::getElemAtIndex(
  const int index,
  T &outVal) const
{
  int i = 0;
  bool isInRange = false;
  LinkedNodeClass<T> * temp = head;

  while(temp != 0 && i < index)
  {
    temp = temp->getNext();
    i++;
  }

  if(temp != 0)
  {
    outVal = temp->getValue();
    isInRange = true;
  }

  return isInRange; 
}
