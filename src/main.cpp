#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "constants.h"

#include "random.h"

#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "EventClass.h"
#include "CustomerClass.h"
#include "AttractionClass.h"
#include "SimulationClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This program will do an event-driven simulation on a one-day
//customer flow at an attraction.

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main(
  int argc, 
  char * argv[])
{
  setSeed(RANDOM_SEED);

  string fileName;
  int settingReturnVal = 0;
  int timeFirstArrival = 0;
  int timeFirstRide = 0;
  int rideRateMin = 0;
  int rideRateMax = 0;
  int numEvents = 0;
  EventClass eventToHandle;

  if(argc != NUM_MAIN_INPUT + 1)
  {
    cout << "Error: Invalid number of main input." << endl;
    cout << "Usage: " << argv[COMMAND_PROMPT];
    cout << " <simulationInfo.txt>" << endl;
    return INVALID_MAIN_INPUT;
  }
  else
  {
    cout << "Reading simulation setting from: ";
    cout << argv[NUM_MAIN_INPUT] << endl;

    fileName.append(argv[NUM_MAIN_INPUT]);

    SimulationClass themePark;

    settingReturnVal = themePark.readSetting(fileName);

    if(settingReturnVal != 0)
    {
      return settingReturnVal;
    }
    else
    {
      themePark.printHeader();

      rideRateMin = themePark.getRideRateMin();
      rideRateMin = themePark.getRideRateMax();

      timeFirstRide = getUniform(rideRateMin, rideRateMax);
      
      EventClass firstArrival(timeFirstArrival, CUSTOMER_ARRIVAL);
      EventClass firstRide(timeFirstRide, GIVE_RIDE);
      themePark.insertEventToList(firstArrival);
      themePark.insertEventToList(firstRide);
      numEvents = themePark.getNumEvents();

      while(numEvents != 0)
      {
        eventToHandle = themePark.getEventAtIndex(0);
        themePark.interpretEvent(eventToHandle);
        themePark.updateEventList();

        numEvents = themePark.getNumEvents();
      }

      themePark.printStatistics();

      return 0;
    }
  }  
}

#endif
