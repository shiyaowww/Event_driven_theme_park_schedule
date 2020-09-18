#ifndef _ATTRACTIONCLASS_H_
#define _ATTRACTIONCLASS_H_

#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"

#include "CustomerClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Purpose: This attraction class will be the data type for an attraction 
//which gives customers ride.

class AttractionClass
{
  private:
    string attractionName;
    int numSeats;
    int numIdealSeats[NUM_LINES];

  public:
    //Default ctor that initializes attributes to default
    AttractionClass();
    //Set numIdealSeats[NUM_LINES] with infile stream
    void setNumIdealSeats(
      ifstream &inFile);
    //Calculate numbers of customers from each priority level boarding 
    //the car and returns the percentage of seats filled 
    int loadCar(
      int numInLine[], 
      int numBoard[]);
    //Gets the attraction name
    string getName() const;
    //Gets the number of seats
    int getNumSeats() const;
};

#endif
