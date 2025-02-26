/*
Lab Specifications

Implement the function fileSum. fileSum is passed in a name of a file. 
This function should open the file, sum all of the integers 
within this file, close the file, and then return the sum.

If the file does not exist, this function should 
output an error message and then call the exit function to exit the 
program passing an error value of EXIT_FAILURE. The exit function and 
value EXIT_FAILURE is provided by the cstdlib library. 
Here is how you call the exit function.
exit(EXIT_FAILURE);
*/



#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string nameoffile){

   ifstream nameoffileFS; 
   int filenum;
   int sum = -1;

   nameoffileFS.open(nameoffile);

   if (nameoffileFS.is_open()) {
      while(nameoffileFS >> filenum){
          sum = sum + filenum;
      }
      sum = sum +1;
   }
   
   else{
      cout << "Error opening " << nameoffile << endl;
      exit(EXIT_FAILURE);
   }


   return sum;

}
int main() {

   
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here