#ifndef _CUSTOMERCLASS_H_
#define _CUSTOMERCLASS_H_

#include <iostream>

#include "constants.h"

#include "random.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This customer class will be the data type for a customer 
//with an id and a priority level.

class CustomerClass
{
  private:
    //Customer id increments every time the value ctor is used
    static int id;
    int priorityLevel;
    int timeArrival;
    //Ransomly initializes priority with uniform distribution
    void setPriority(
      int inPercentSuperFastPass,
      int inPercentFastPass);

  public:
    //Default ctor that initializes all attributes to default int
    CustomerClass();
    //Value ctor that initializes a customer with time  arrival
    CustomerClass(
      int inTime,
      int inPercentSuperFastPass,
      int inPercentFastPass);
    //Return customer id
    int getId() const;
    //Return customer priority
    int getPriority() const;
    //Return time arrival
    int getTimeArrival() const;
    //Print detailed customer info
    void printCustomer();
};

//Overloaded << as a global function to add customer id to ostream
ostream& operator<<(
  ostream &os,
  const CustomerClass &inCustomer);

#endif