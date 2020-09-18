#include <iostream>

#include "constants.h"

#include "random.h"

#include "CustomerClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This customer class will be the data type for a customer
//with an id and a priority level.

int CustomerClass::id = INITIALIZED_CUATOMER_ID;

CustomerClass::CustomerClass():
  priorityLevel(DEFAULT_INT_INITIALIZED),
  timeArrival(DEFAULT_INT_INITIALIZED)
{}

CustomerClass::CustomerClass(
  int inTime,
  int inPercentSuperFastPass,
  int inPercentFastPass):
  priorityLevel(inTime)
{
  timeArrival = inTime;
  setPriority(
    inPercentSuperFastPass, 
    inPercentFastPass);
  id++;
}

void CustomerClass::setPriority(
  int inPercentSuperFastPass,
  int inPercentFastPass)
{
  int randResult = 0;
  randResult = getUniform(0, PERCENT_DENOMINATOR);
  if(randResult >= 0 && randResult < inPercentSuperFastPass)
  {
    priorityLevel = SUPER_FAST;
  } 
  else if(randResult < (inPercentSuperFastPass + inPercentFastPass))
  {
    priorityLevel = FAST;
  }
  else
  {
    priorityLevel = STANDARD;
  }
}

int CustomerClass::getId() const
{
  return id;
}

int CustomerClass::getPriority() const
{
  return priorityLevel;
}

int CustomerClass::getTimeArrival() const
{
  return timeArrival;
}

void CustomerClass::printCustomer()
{
  cout << "At time " << timeArrival << ", ";
  cout << "customer no." << id;
  cout << " of priority " << priorityLevel << " arrives." << endl;
}

ostream& operator<<(
  ostream &os,
  const CustomerClass &inCustomer)
{
  os << inCustomer.getId();
  return os;
}

