// obstacleDataSample.cpp

#include "obstacleDataSample.h"
#include "project1.h"
#include "filter.h"

vector<obstacleDataSample> oDataSample(string fileIn){

	// declare a vector of the structure type obstacleDataSample to store input data
	vector<obstacleDataSample> obstaclesFromFile;
	// declare input stream variable
	ifstream inputFS;
	// open input file
	inputFS.open(fileIn);

	// declare necessary variables for temporary storage for time, distance, angle
    double t, d, a;
    int n = 0;
    char delim = ',';

	// check to see if the file is open
	if (inputFS.is_open()) {
    	cout << "The file, " << fileIn << " is open!" << endl;

    	// declare stringstream for reading each line of the file
    	stringstream sLine;
    	// declare a string to store each line as we go
    	string currentLine;

    	// loop through the following until we get to the end of the file
    	while (!inputFS.eof()) {
    		// if the data is good continue, else skip line
			if(inputFS.good()){
				//cout << "The line is good! and n = " << n << endl;
				// extract the line from the file and put into variable currentLine
      			getline(inputFS, currentLine);
      			// clear the string stream
      			sLine.clear();
      			// load the string stream with the currentLine
      			sLine.str(currentLine);
      			// extract data from the line
      			// cout << "The currentline is: " << currentLine << endl;
      			sLine >> t >> delim >> d >> delim >> a;

      			obstacleDataSample thisData;

      			// move data from the line we just read into an object from the structure
      			thisData.timestamp = t;
      			thisData.distance = d;
      			thisData.angle = a;
      			/*
      			cout << "item in temporary structure: " << endl;
				cout << "n:  " << n << "   ts: " << thisData.timestamp << "  d: " << thisData.distance;
     			cout << "  a: "<< thisData.angle << endl;
     			*/
      			// add this obstacle to vector of obstacles
      			obstaclesFromFile.push_back(thisData);
      			/*
      			cout << "item in structure in vector: " << endl;
      			cout << "n:  " << n << "   ts: " << obstaclesFromFile.at(n).timestamp << "  d: " << obstaclesFromFile.at(n).distance;
     			cout << "  a: "<< obstaclesFromFile.at(n).angle << endl;
     			*/
      			n++;
      		}else{
      			cout << "The line is BAD! and n = " << n << endl;
      		}
   		}

   		cout << n << " lines have been read from the file" << endl;
   	}
   	else{
   		cout << "Could not open file inputFile1.txt."<< endl;
   		// close the input file and abort
   		inputFS.close();
   		abort();
   	}
   
	// If end-of-file not reached, then an error occurred
	if (!inputFS.eof()) {
   		cout << "Error reading inputFile1.txt." << endl;
   		cout << "Did not reach EOF" << endl;
   		cout << "line number = " << n << endl;
   		exit(EXIT_FAILURE);
	}
   	
   	// Close file when done reading
   	inputFS.close();

	return obstaclesFromFile;
}


void writeToOutput(vector<obstacleDataSample> obstacle, string fileOut){
	int numLines = 0;
//  cout << "FIXME: writing to output" << endl;
  // declare variable for output stream
  ofstream outFS;

  //open the output file to write to
  //outFS.open("data.txt");
  outFS.open(fileOut);

  // check to make sure the file opened
  if (!outFS.is_open()) {
    cout << "Could not open file data.txt." << endl;
    return;
  }
  cout << "Output file has been opened." << endl;
  // declare output string stream for formatting purposes
  stringstream outLine;
  // loop through vector of obstacles to print and label
  for(int i = 0; i < obstacle.size(); ++i){
  	//cout << "in the i loop" << endl;
  	// Clear outLine characters
  	outLine.str(""); 
  	outLine << numLines << "    ";
  	outLine << fixed << setprecision(6);
  	outLine << obstacle.at(i).timestamp << ", ";
  	outLine << obstacle.at(i).distance << ", ";
  	outLine << obstacle.at(i).angle << ", ";

  	switch(obstacle.at(i).status){
   		case UNDEFINED:
   			outLine << "UNDEFINED" << endl;
  			break;
   		case VALID:
   			outLine << "VALID" << endl;
   			break;
   		case FILTERED:
   			outLine << "FILTERED" << endl;
   			break;
   		case ANGLE_RESET:
   			outLine << "ANGLE_RESET" << endl;
   			break;
   		case DISTANCE_RESET:
   			outLine << "DISTANCE_RESET" << endl;
   			break;
   		default:
   			outLine << "NO LABEL" << endl;
   			break;
   	}
  	outFS << outLine.str();
  	numLines++;
  }

  cout << "There are " << obstacle.size() << " obstacles." << endl;
  cout << numLines << " lines have been written to the output file." << endl;

  outFS.close();
  return;
}

