#ifndef _LINKEDNODECLASS_H_
#define _LINKEDNODECLASS_H_

#include <iostream>

using namespace std;

//Created by: Shiyao Wang 
//Date: April 10, 2020
//Purpose: This list node template will be the data type for individual 
//nodes of a doubly-linked list data structure.

template <class T>
class LinkedNodeClass
{
  private:
    //Points to the node that comes before this node
    //NULL if this is the first node
    LinkedNodeClass<T> * prevNode;
    //Value of the node
    T nodeVal;
    //Points to the node that follows this node
    //NULL if this is the last node
    LinkedNodeClass<T> * nextNode;

  public:
    //The only value ctor
    LinkedNodeClass(
      LinkedNodeClass<T> * inPrev,
      const T &inval,
      LinkedNodeClass<T> * inNext);
    //Returns the value stored within this node
    T getValue() const;
    //Returns the address of the node that follows this node
    LinkedNodeClass<T> * getNext() const;
    //Returns the address of the node that comes before this node
    LinkedNodeClass<T> * getPrev() const;
    //Sets the object's next node pointer to NULL
    void setNextPointerToNull();
    //Sets the object's previous node pointer to NULL
    void setPreviousPointerToNull();
    //Edits the previous and the next nodes so that they point
    //to this node appropriately
    void setBeforeAndAfterPointers();
};

#include "LinkedNodeClass.inl"

#endif
