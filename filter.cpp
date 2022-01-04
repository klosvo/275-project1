// filter.cpp
#include "obstacleDataSample.h"
#include "project1.h"
#include "filter.h"
#include <cmath>

void filter(vector<obstacleDataSample>& obstacle) {
	double defaultAngle = -M_PI/2;
  double maxDistance = 81.0;
  double angleTolerance = 15*M_PI/180;
  double distanceTolerance = 0.1;
  double sum, filteredAvg;
  int validDist;
  int n=0, i, j, filteredOne, maxIndex, leftovers=0;
  int angleDifference = 0, distDifference = 0, numFilterWindows = 0;

  	// loop through vector of obstacles to print and label
  	//for(i = 0; i < obstacle.size(); ++i){
    //  	cout << "i:  " << i << "   ts: " << obstacle.at(i).timestamp << "  d: " << obstacle.at(i).distance;
   	//	cout << "  a: "<< obstacle.at(i).angle << endl;
  	//}
 // cout << "Obstacle size is " << obstacle.size() << endl;
/*
  if(obstacle.size() < 180){
  	cout << "Whole window is not available. Filter will not run." << endl;
  	return;
  }
  */

  // determine how many valid filter windows are there?
  numFilterWindows = obstacle.size()/11;
  leftovers = 11+obstacle.size()%11;
  maxIndex = obstacle.size() - leftovers;
  //cout << "maxIndex is " << maxIndex << endl;
  //cout << "numFilterWindows = " << numFilterWindows << endl;

	// if it's the first one, set status to UNDEFINED
	obstacle.at(0).status = (FilterStatus) -1;

  // itereate through the number of filter windows
  for(i = 1; i < maxIndex; ++i){
  	// set or reset individual window variables to 0
  	validDist = 0;
  	sum = 0.0;
  	filteredAvg = 0.0;
    //cout << "before j loop, i = " << i << ", j = " << j << endl;
	  // iterate through the filter window
 		for(j = i; j < 11; ++j){
      n = i+5;

      angleDifference = abs(obstacle.at(j).angle - obstacle.at(j-1).angle);
      distDifference = abs(obstacle.at(j).distance - obstacle.at(j-1).distance);
 			// if the distance is the maxDistance, do not filter, set status to UNDEFINED
      //cout << "i = " << i << ", j = " << j << endl;
 			if(obstacle.at(j).distance == maxDistance){
 				//obstacle.at(n).status = FilterStatus(-1);
  			 obstacle.at(j).status = (FilterStatus) -1;
  		
  			// if the angle is equal to the default angle, set status to UNDEFINED
  		}

      else if(obstacle.at(j).angle == defaultAngle){
  				//obstacle.at(n).status = FilterStatus(-1);
  				obstacle.at(j).status = (FilterStatus) -1;
  		
  			// if the angle difference is greater than the tolerance, set status to ANGLE_RESET
  		}
      else if(angleDifference >= angleTolerance){
  				//obstacle.at(n).status = FilterStatus(2);
  				obstacle.at(j).status = (FilterStatus) 2;
  		
  			// if the distance difference is greater than the tolerance, set status to DISTANCE_RESET
  		}
      else if(distDifference >= distanceTolerance){
  				//obstacle.at(n).status = FilterStatus(3);
  				obstacle.at(j).status = (FilterStatus) 3;
  			
			// if it passes all the above tests, set the status to VALID and include the distance value in the filter
			}
      else if(j == n){
          obstacle.at(j).status = (FilterStatus) -1;
      }else{
  				//obstacle.at(n).status = FilterStatus(0);
  				obstacle.at(j).status = (FilterStatus) 0;
  				// add the distance to the sum to be used in the filter
 				sum += obstacle.at(j).distance;
 				validDist++;
			}	
     // cout << "after if-else, i = " << i << ", j = " << j << endl;
    }
		// if there is more than 0 valid datums, calculate the filter for the window
  	 if(validDist > 0){
        filteredOne = i+6;
  			filteredAvg = sum/validDist;		
  			// set the middle window distance to the filtered value
  			obstacle.at(filteredOne).distance = filteredAvg;
  			// set the middle window status to FILTERED
  			//obstacle.at(filteredOne).status= FilterStatus(1);
  			obstacle.at(filteredOne).status= (FilterStatus) 1;
  	 }else{
  		//	cout << endl << "NOT valid distance. i = " << i+1 << endl;
  	 }
  }
/*
  	for(int i = n; i < obstacle.size(); ++i){
  		obstacle.at(i).status = (FilterStatus) -1;
  	}
    */

/*
  cout << "Checking all" << endl;
  for(i = 0; i < obstacle.size(); ++i){
      	cout << "line number:  " << i << "   ts: " << obstacle.at(i).timestamp << "  d: " << obstacle.at(i).distance;
   		cout << "  a: "<< obstacle.at(i).angle << " status: ";
   		switch(obstacle.at(i).status){
   			case UNDEFINED:
   				cout << "UNDEFINED"  << endl;
   				break;
   			case VALID:
   				cout << "VALID"  << endl;
   				break;
   			case FILTERED:
   				cout << "FILTERED"  << endl;
   				break;
   			case ANGLE_RESET:
   				cout << "ANGLE_RESET"  << endl;
   				break;
   			case DISTANCE_RESET:
   				cout << "DISTANCE_RESET"  << endl;
   				break;
   			default:
   				cout << "NO LABEL"  << endl;
   				break;
   		}   		 
  }
*/


  	// end function, return to main
  	return;
}


