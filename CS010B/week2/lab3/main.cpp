/*
This program should

get names of input and output files from command line (NOT from user input)
read in integers from a csv (comma-separated values) file into a vector
compute the integer average of all of the values
convert each value in the vector to the difference between the original value and the average
write the new values into a csv file
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
const char* inputFile;
const char* outputFile;



   if (argc != 3) {
      cout << "error" << endl;
      return 1; // 1 indicates error
   }
   
// Assign to inputFile value of 2nd command line argument
// Assign to outputFile value of 3rd command line argument

   vector<int> inputints;
   unsigned int i;

   inputFile = argv[1];
   outputFile = argv[2];
   
// Create input stream and open input csv file.

   ifstream inputFS;
   inputFS.open(inputFile);

// Verify file opened correctly.
// Output error message and return 1 if file stream did not open correctly.

   if(!inputFS.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   
// Read in integers from input file to vector.
   string number;
   while (getline(inputFS, number, ',')) {
    int infile = stoi(number); // stoi function converts strings with digits into ints 
    inputints.push_back(infile);
   }

// Close input stream.

   inputFS.close();


// Get integer average of all values read in.

   int totalsum = 0;

   for(i =0; i< inputints.size(); ++i){
      totalsum = totalsum + inputints.at(i);
   }
 
   int average = totalsum/inputints.size();

// Create output stream and open/create output csv file.

   ofstream convertedvaluesFS;
   convertedvaluesFS.open(outputFile);

// Verify file opened or was created correctly.
// Output error message and return 1 if file stream did not open correctly.

   if(!convertedvaluesFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   
// Convert each value within vector to be the difference between the original value and the average.
   vector<int> outputvector;
   
   for(i =0; i< inputints.size(); ++i){
    int newvalue = inputints.at(i) - average;
    outputvector.push_back(newvalue);
   }
   
// Write converted values into ouptput csv file, each integer separated by a comma.

  for (i = 0; i < outputvector.size(); ++i) {
    if (i != 0) {
        convertedvaluesFS << ",";
    }
    convertedvaluesFS << outputvector.at(i);
   }
   convertedvaluesFS << "\n"; // used newline instea dof endline? hopefully it works 
   cout << inputints.size();

// Close output stream.
   convertedvaluesFS.close();

   return 0;
}