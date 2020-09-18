#include <iostream>

#include "constants.h"

#include "EventClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This event class will be the data type for an event
//scheduled to happen.

EventClass::EventClass():
  eventTime(DEFAULT_INT_INITIALIZED),
  eventType(DEFAULT_INT_INITIALIZED)
{}

EventClass::EventClass(
  int inTime,
  int inType):
  eventTime(inTime),
  eventType(inType)
{}

int EventClass::getEventTime() const  
{
  return eventTime;
}

int EventClass::getEventType() const
{
  return eventType;
}

bool EventClass::operator<=(
  const EventClass &rhs)
{
  return eventTime <= rhs.getEventTime();
}

