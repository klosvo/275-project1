// obstacleDataSample.h

//#ifndef OBSTACLEDATASAMPLE_H
//#define OBSTACLEDATASAMPLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

#include "project1.h"
#include "filter.h"

using namespace std;

// This enumerated type provides entries for each of the
// potential labels attached to a sample
typedef enum FilterStatus { UNDEFINED=-1, VALID, FILTERED, ANGLE_RESET, DISTANCE_RESET } FilterStatus;

// This struct is used to print out the filtered data
// (and can also be used to store data from the read files)
// N.B. a previous version of this struct used float rather than 
// double values: if you had trouble with truncating data points, 
// change ALL of your variables that used to be float to be double
typedef struct obstacleDataSample_struct {
    double timestamp;
    double distance;
    double angle;
    FilterStatus status;
} obstacleDataSample;


// Declare functions for obstacleDataSample.cpp
vector<obstacleDataSample> oDataSample(string fileIn);
void writeToOutput(vector<obstacleDataSample> obstacle, string fileOut);
void filter(vector<obstacleDataSample>& obstacles); 

//#endif

