/*
Implement the function charCnt. 
charCnt is passed in a name of a file and 
a single character (type char). This function should open the file,
 count the number of times the character is found within the file, 
 close the file, and then return the count.

If the file does not exist, this function should output an error message
 and then call the exit function to exit the program with an error value of 1.
*/


#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (string nameoffile, char inputchar){
   ifstream charfileFS;
   int charamt = -1;
   char filechar = 'a';

   charfileFS.open(nameoffile);

   if(charfileFS.is_open()){
      while(charfileFS.get(filechar)){
         if(filechar == inputchar){
             charamt = charamt +1;
         }
      }
      charamt = charamt + 1;
   }
   
   else{ 
      cout << "Error opening " << nameoffile << endl;
      exit(EXIT_FAILURE);
   }

   return charamt;
}

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
