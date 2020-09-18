#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"

#include "AttractionClass.h"

#include "CustomerClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This attraction class will be the data type for an attraction
//which gives customers ride.

AttractionClass::AttractionClass():
  attractionName(ATTRACTION_NAME),
  numSeats(NUM_SEATS_ATTRACTION)
{
  int i = 0;

  for(i = 0; i < NUM_LINES; i++)
  {
    numIdealSeats[i] = DEFAULT_INT_INITIALIZED;
  }
}

void AttractionClass::setNumIdealSeats(
  ifstream &inFile)
{
  inFile >> numIdealSeats[SUPER_FAST];
  inFile >> numIdealSeats[FAST];
  numIdealSeats[STANDARD] = 
    numSeats - numIdealSeats[SUPER_FAST] - numIdealSeats[FAST];
}

int AttractionClass::loadCar(
  int numInLine[], 
  int numBoard[])
{
  int i = 0;
  int summedNumBoard = 0;
  int percentFilled = 0;

  if(numInLine[SUPER_FAST] < numIdealSeats[SUPER_FAST])
  {
    if(numInLine[FAST] < 
      (numIdealSeats[SUPER_FAST] + numIdealSeats[FAST] 
      - numInLine[SUPER_FAST]))
    {
      if(numInLine[STANDARD] <
        (numSeats - numInLine[SUPER_FAST] - numInLine[FAST]))
      {
        for(i = 0; i < NUM_LINES; i++)
        {
          numBoard[i] = numInLine[i];
        }
      }
      else
      {
        numBoard[SUPER_FAST] = numInLine[SUPER_FAST];
        numBoard[FAST] = numInLine[FAST];
        numBoard[STANDARD] = numIdealSeats[STANDARD];
      } 
    }
    else
    {
      if(numInLine[STANDARD] < numIdealSeats[STANDARD])
      {
        numBoard[SUPER_FAST] = numInLine[SUPER_FAST];
        numBoard[FAST] = numIdealSeats[SUPER_FAST] + 
          numIdealSeats[FAST] - numInLine[SUPER_FAST];
        numBoard[STANDARD] = numInLine[STANDARD];
      }
      else
      {
        numBoard[SUPER_FAST] = numInLine[SUPER_FAST];
        numBoard[FAST] = numIdealSeats[SUPER_FAST] + 
          numIdealSeats[FAST] - numInLine[SUPER_FAST];
        numBoard[STANDARD] = numIdealSeats[STANDARD];
      }    
    } 
  }
  else
  {
    if(numInLine[FAST] < numIdealSeats[FAST])
    {
      if(numInLine[STANDARD] < 
        (numIdealSeats[FAST] + numIdealSeats[STANDARD] 
        - numInLine[FAST]))
      {
        numBoard[SUPER_FAST] = numIdealSeats[SUPER_FAST];
        numBoard[FAST] = numInLine[FAST];
        numBoard[STANDARD] = numInLine[STANDARD];
      }
      else
      {
        numBoard[SUPER_FAST] = numIdealSeats[SUPER_FAST];
        numBoard[FAST] = numInLine[FAST];
        numBoard[STANDARD] = numIdealSeats[FAST] + 
          numIdealSeats[STANDARD] - numInLine[FAST];
      } 
    }
    else
    {
      if(numInLine[STANDARD] < numIdealSeats[STANDARD])
      {
        numBoard[SUPER_FAST] = numIdealSeats[SUPER_FAST];
        numBoard[FAST] = numIdealSeats[FAST];
        numBoard[STANDARD] = numInLine[STANDARD];
      }
      else
      {
        for(i = 0; i < NUM_LINES; i++)
        {
          numBoard[i] = numIdealSeats[i];
        }
      }     
    }
  }  

  for(i = 0; i < NUM_LINES; i++)
  {
    summedNumBoard += numBoard[i];
  }

  percentFilled = summedNumBoard * PERCENT_DENOMINATOR / numSeats;
  
  return percentFilled;
}

string AttractionClass::getName() const
{
  return attractionName;
}

int AttractionClass::getNumSeats() const
{
  return numSeats;
}