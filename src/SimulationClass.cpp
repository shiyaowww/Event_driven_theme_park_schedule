#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"

#include "random.h"

#include "SimulationClass.h"

#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "EventClass.h"
#include "CustomerClass.h"
#include "AttractionClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This simulation class will be the data type for a simulation
//on a one-day customer flow at an attraction.

SimulationClass::SimulationClass():
  closingTime(DEFAULT_INT_INITIALIZED),
  arrivalRateMean(DEFAULT_INT_INITIALIZED),
  arrivalRateStdev(DEFAULT_DOUBLE_INITIALIZED),
  rideRateMin(DEFAULT_INT_INITIALIZED),
  rideRateMax(DEFAULT_INT_INITIALIZED),
  percentSuperFastPass(DEFAULT_INT_INITIALIZED),
  percentFastPass(DEFAULT_INT_INITIALIZED),
  numRidesGiven(0),
  summedPercentFilled(0),
  averagePercentFilled(DEFAULT_DOUBLE_INITIALIZED)
{
  int i = 0;
  priorityLabel[SUPER_FAST] = LABEL_SUPER_FAST;
  priorityLabel[FAST] = LABEL_FAST;
  priorityLabel[STANDARD] = LABEL_STANDARD;

  for(i = 0; i < NUM_LINES; i++)
  {
    numInLine[i] = 0;
    numCustomerServed[i] = 0;
    maxWaitingTime[i] = DEFAULT_INT_INITIALIZED;
    summedWaitingTime[i] = 0;
    averageWaitingTime[i] = DEFAULT_DOUBLE_INITIALIZED; 
  }  
}

int SimulationClass::readSetting(
  string &fileName)
{
  ifstream inFile;
  inFile.open(fileName.c_str());

  if(inFile.fail())
  {
    cout << "Error: Unable to open the file." << endl;
    cout << "No access to the file or the file doesn't exit." << endl;

    return FILE_NO_ACCESS;
  }

  inFile >> closingTime;
  inFile >> arrivalRateMean;
  inFile >> arrivalRateStdev;
  inFile >> rideRateMin;
  inFile >> rideRateMax;
  inFile >> percentSuperFastPass;
  inFile >> percentFastPass;
  spaceMountain.setNumIdealSeats(inFile);

  inFile.close();
  
  return 0;
}

void SimulationClass::interpretEvent(
  EventClass &inEvent)
{
  if(inEvent.getEventType() == GIVE_RIDE)
  {
    giveRide(inEvent);
  }
  else
  {
    enqueueCustomer(inEvent);
  }
}

void SimulationClass::printStatistics()
{
  int i = 0;

  cout << "**************************************************" << endl;
  cout << "At the end of the day: " << endl;

  averagePercentFilled = double(summedPercentFilled) 
    / double(numRidesGiven);
  
  cout << numRidesGiven << " rides are given at ";
  cout << spaceMountain.getName() << " with ";
  cout << spaceMountain.getNumSeats() << " seats." << endl;
  cout << "Average percent filled on the train: ";
  cout << averagePercentFilled  << "%" << endl;
  cout << "**************************************************" << endl;

  for(i = 0; i < NUM_LINES; i++)
  {
    averageWaitingTime[i] = double(summedWaitingTime[i]) 
      / double(numCustomerServed[i]);

    cout << "For priority level: " <<  priorityLabel[i] << endl;
    cout << "Number of customers served: " << numCustomerServed[i] << endl;
    cout << "Average waiting time: ";
    cout << averageWaitingTime[i] << endl;
    cout << "Max waiting time of customer: " << maxWaitingTime[i] << endl;
    cout << "**************************************************" << endl;
  }
}

void SimulationClass::enqueueCustomer(
  EventClass &inArrivalEvent)
{
  int inArrivalTime = 0;
  int customerPriority = 0;

  inArrivalTime = inArrivalEvent.getEventTime();

  CustomerClass newCustomer(
    inArrivalTime,
    percentSuperFastPass,
    percentFastPass);

  customerPriority = newCustomer.getPriority();
  linesArray[customerPriority].enqueue(newCustomer);
  numInLine[customerPriority]++;
  newCustomer.printCustomer();
  printNumInLine();
}

void SimulationClass::giveRide(
  EventClass &inRideEvent)
{
  int i = 0;
  int j = 0;
  int timeRide = 0;
  int outCustomerWaitingTime = DEFAULT_INT_INITIALIZED;
  CustomerClass outCustomer;
  int numBoard[NUM_LINES];

  numRidesGiven++;
  timeRide = inRideEvent.getEventTime();
  
  for(i = 0; i < NUM_LINES; i++)
  {
    numBoard[i] = 0;
  }
  
  summedPercentFilled += spaceMountain.loadCar(numInLine, numBoard);
  
  for(i = 0; i < NUM_LINES; i++)
  {
    for(j = 0; j < numBoard[i]; j++)
    {
      linesArray[i].dequeue(outCustomer);

      outCustomerWaitingTime = timeRide - outCustomer.getTimeArrival();

      if(outCustomerWaitingTime > maxWaitingTime[i])
      {
        maxWaitingTime[i] = outCustomerWaitingTime;
      }

      summedWaitingTime[i] += outCustomerWaitingTime;
      
      numCustomerServed[i]++;

      numInLine[i]--;
    }
  }

  cout << "At time: " << timeRide;
  cout << ", ride no." << numRidesGiven << " is given, taking ";
  for(i = 0; i < NUM_LINES; i++)
  {
    cout << numBoard[i] << " ";
  }
  cout << "customers of ";
  printPriorityLabels();
  cout << "respectively.";
  cout << endl;
  printNumInLine();
}


EventClass SimulationClass::regenerateArrivalEvent(
  int &inTime)
{
  int timeNewArrival = 0;
  int arrivalInterval = 0;

  arrivalInterval = getNormal(arrivalRateMean, arrivalRateStdev);
  timeNewArrival = arrivalInterval + inTime;

  EventClass newArrivalEvent(timeNewArrival, CUSTOMER_ARRIVAL);
 
  return newArrivalEvent;
}


EventClass SimulationClass::regenerateRideEvent(
  int &inTime)
{
  int timeNewRide = 0;
  int rideInterval = 0;

  rideInterval = getUniform(rideRateMin, rideRateMax);
  timeNewRide = rideInterval + inTime;

  EventClass newRideEvent(timeNewRide, GIVE_RIDE);

  return newRideEvent;
}


void SimulationClass::updateEventList()
{
  int handledTime = 0;
  int handledType = 0;
  int timeNewEvent = 0;
  bool hasCustomer = false;
  EventClass handledEvent;
  EventClass newEvent;

  eventList.removeFront(handledEvent);

  handledTime = handledEvent.getEventTime();
  handledType = handledEvent.getEventType();

  if(handledType == CUSTOMER_ARRIVAL)
  {
    newEvent = regenerateArrivalEvent(handledTime);
    timeNewEvent = newEvent.getEventTime();

    if(timeNewEvent < closingTime)
    {
      eventList.insertValue(newEvent);
    }
  }
  else
  {
    hasCustomer = customerWaiting();
    if(handledTime < closingTime || hasCustomer == true) 
    {
      newEvent = regenerateRideEvent(handledTime);
      eventList.insertValue(newEvent);
    }
  } 
}

bool SimulationClass::customerWaiting()
{
  int i = 0;
  bool allVoid = true;

  for(i = 0; i < NUM_LINES; i++)
  {
    allVoid *= (numInLine[i] == 0);
  } 

  return !allVoid;
}

int SimulationClass::getArrivalRateMean() const
{
  return arrivalRateMean;
}

double SimulationClass::getArrivalRateStdev() const
{
  return arrivalRateStdev;
}

int SimulationClass::getRideRateMin() const
{
  return rideRateMin;
}

int SimulationClass::getRideRateMax() const
{
  return rideRateMax;
}

int SimulationClass::getNumEvents() const
{
  return eventList.getNumElems();
}

EventClass SimulationClass::getEventAtIndex(
  int index)
{
  EventClass outEvent;
  eventList.getElemAtIndex(index, outEvent);

  return outEvent;
}

void SimulationClass::insertEventToList(
  EventClass &inEvent)
{
  eventList.insertValue(inEvent);
}

void SimulationClass::printNumInLine()
{
  int i = 0;

  cout << "Now there are ";
  for(i = 0; i < NUM_LINES; i++)
  {
    cout << numInLine[i] << " "; 
  }
  cout << "customers waiting in line of ";
  printPriorityLabels();
  cout << "respectively." << endl;
  cout << "**************************************************" << endl;
}

void SimulationClass::printHeader()
{
  cout << "This simulation will be a one-day customer flow ";
  cout << "at an attraction of a theme park with ";
  cout << NUM_LINES;
  cout << " priority levels of pass: ";
  printPriorityLabels();
  cout << "**************************************************" << endl;
}

void SimulationClass::printPriorityLabels()
{
  int i = 0;

  for(i = 0; i < NUM_LINES; i++)
  {
    cout << priorityLabel[i] << ", ";
  }
}