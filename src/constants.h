#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>
using namespace std;

//Created by: Shiyao Wang
//Date: April 10, 2020
//Constants: Used in the program that does an event-driven simulation
//on a one-day customer flow at an attraction of a theme park.

const int NUM_MAIN_INPUT = 1;
const int COMMAND_PROMPT = 0;

const int RANDOM_SEED = 567;

const int INITIALIZED_CUATOMER_ID = 0;

const int NUM_SEATS_ATTRACTION = 20;
const string ATTRACTION_NAME = "Space Mountain";

const int NUM_LINES = 3;
const int SUPER_FAST = 0;
const int FAST = 1;
const int STANDARD = 2;
const string LABEL_SUPER_FAST = "Super Fast Pass";
const string LABEL_FAST = "Fast Pass";
const string LABEL_STANDARD = "Standard Pass";

const int INVALID_MAIN_INPUT = 1;
const int FILE_NO_ACCESS = 2;

const int CUSTOMER_ARRIVAL = 0;
const int GIVE_RIDE = 1;

const int PERCENT_DENOMINATOR = 100;

const int DEFAULT_INT_INITIALIZED = -999;
const double DEFAULT_DOUBLE_INITIALIZED = -999.999;


#endif
