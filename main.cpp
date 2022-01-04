#include "obstacleDataSample.h"
#include "project1.h"
#include "filter.h"

int main(int argc, char* argv[]) {
  string fileInput; // string to store the input word 
  string fileOutput;
  bool validInput = true; //the program expects 1 word at time we need to validate that. 

  if(!(argc == 3)){
    validInput = false;
  }
  
  if(validInput){

    fileInput= argv[1];
    cout << "fileInput file is " << fileInput << endl;
    fileOutput= argv[2];
    cout << "fileOutput file is " << fileOutput << endl;

  }else{
    cout << "Error! Input did not match input format."<< endl;
    return 0;
  }

  vector<obstacleDataSample> obs;

  //cout << "Please enter the filename for the file you would like to read." << endl;
  //cin >> fileInput;
  obs = oDataSample(fileInput);

  filter(obs);

  writeToOutput(obs, fileOutput);
  
  return 0;
}
