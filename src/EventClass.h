#ifndef _EVENTCLASS_H_
#define _EVENTCLASS_H_

#include <iostream>

#include "constants.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This event class will be the data type for an event 
//scheduled to happen.

class EventClass
{
  private:
    int eventTime;
    int eventType;

  public:
    //Default ctor that initializes an event 
    EventClass();
    //Value ctor that initializes an event with given time and type
    EventClass(
      int inTime,
      int inType);
    //Return the time attribute
    int getEventTime() const;
    //Return the type attribute
    int getEventType() const;
    //Overloaded <= as a method of EventClass
    bool operator<=(
      const EventClass &rhs);
};

#endif
