#ifndef _SORTEDLISTCLASS_H_
#define _SORTEDLISTCLASS_H_

#include <iostream>

#include "LinkedNodeClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This sorted list template will be a doubly-linked-list of
//LinkNodeClass objects, each of which contains one element.

template <class T>
class SortedListClass
{
  private:
    //Points to the first node, NULL if list is empty
    LinkedNodeClass<T> * head;
    //Points to the last node, NULL if list is empty
    LinkedNodeClass<T> * tail;

  public:
    //Default ctor, initializes list to be empty
    SortedListClass();
    //Copy ctor, makes deep copy of list
    SortedListClass(
      const SortedListClass<T> &rhs);
    //Dtor, frees up the dynamic memory when the object gets destroyed
    ~SortedListClass();
    //Clears the list to an empty state without memory leak
    void clear();
    //Allows the user to insert a value into the ascending list
    void insertValue(
      const T &valToInsert);
    //Prints the list from head to tail
    void printForward() const;
    //Prints the list from tail to head
    void printBackward() const;
    //Removes tht front item and sets the reference parameter to the value
    //removed. Returns true if list is not empty
    bool removeFront(
      T &theVal);
    //Removes tht last item and sets the reference parameter to the value
    //removed. Returns true if list is not empty
    bool removeLast(
      T &theVal);
    //Returns the number of nodes contained in the list
    int getNumElems() const;
    //Provides the value stored in the indexed node
    //Returns true if index is in range
    bool getElemAtIndex(
      const int index,
      T &outVal) const;
};

#include "SortedListClass.inl"

#endif
