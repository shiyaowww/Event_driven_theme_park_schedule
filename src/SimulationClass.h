#ifndef _SIMULATIONCLASS_H_
#define _SIMULATIONCLASS_H_

#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"

#include "random.h"

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

class SimulationClass
{
  private:
    int closingTime;
    int arrivalRateMean;
    double arrivalRateStdev;
    int rideRateMin;
    int rideRateMax;
    int percentSuperFastPass;
    int percentFastPass;
    int numRidesGiven;
    string priorityLabel[NUM_LINES];
    int numInLine[NUM_LINES];
    int numCustomerServed[NUM_LINES];
    int maxWaitingTime[NUM_LINES];
    int summedWaitingTime[NUM_LINES];
    int averageWaitingTime[NUM_LINES];
    int summedPercentFilled;
    double averagePercentFilled;
    AttractionClass spaceMountain;
    SortedListClass<EventClass> eventList;
    FIFOQueueClass<CustomerClass> linesArray[NUM_LINES];
    //Enqueue a customer in line, update statistics and print customer info
    void enqueueCustomer(
      EventClass &inArrivalEvent);
    //Give a ride to certain numbers of customers of each priority in line
    void giveRide(
      EventClass &inRideEvent);
    //Regenerate an arrival event with the time of the handled arrival event
    EventClass regenerateArrivalEvent(
      int &inTime);
    //Regenerate a ride event with the time of the handled ride event
    EventClass regenerateRideEvent(
      int &inTime);
    //Judge whether there are any customers waiting in line
    bool customerWaiting();
    //Print numbers of customers of each priority in line
    void printNumInLine();
    //Print priority labels
    void printPriorityLabels();
    
  public:
    //Default ctor that initializes attributes as default
    SimulationClass();
    //Read simulation info from a text file and return error if necessary
    int readSetting(
      string &fileName);
    //Take an event from the event list and handle it
    void interpretEvent(
      EventClass &inEvent);
    //Update the event list after an event gets handled
    void updateEventList();
    //Print simulation header at the beginning
    void printHeader();
    //Print statistics after all events in the event list are handled
    void printStatistics(); 
    //Get attribute arrivalRateMean
    int getArrivalRateMean() const;
    //Get attribute arrivalRateStdev
    double getArrivalRateStdev() const;
    //Get attribtue rideRateMin
    int getRideRateMin() const;
    //Get attribute rideRateMax
    int getRideRateMax() const;
    //Get number of elements in the eventList
    int getNumEvents() const;
    //Get event at index of the eventList and returns false 
    //when list is empty
    EventClass getEventAtIndex(
      int index);
    //Insert Event to the eventList
    void insertEventToList(
      EventClass &inEvent);
};

#endif
