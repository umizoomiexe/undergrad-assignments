//START OF MAIN.CPP FILE  
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

//You are given a function that creates a vector of
//characters with random size. You just need to put the
//following piece of code in your main.cpp file as is:
vector<char> createVector() {
  int vecSize = rand() % 26;
  char c = 'a';
  vector<char> vals;
  for(int i = 0; i < vecSize; i++)
    {
      vals.push_back(c);
      c++;
    }
  return vals;
}

// Passes in an index of type int and a vector of type T (T could be
// string, double, int or whatever). The function returns the index
// of the min value starting from "index" to the end of the "vector".
// PROFPAT: How do we define the "template" type T here?
unsigned min_index(const vector<T> &vals, unsigned index) {
  return 0;
}

// PROFPAT: Note that vals is passed by reference, but not const
// PROFPAT: reference.  So this function will change the vector
// PROFPAT: back in main when we call it
// Passes in a vector of type T and sorts them based on the selection
// sort method. This function should utilize the min_index function
// to find the index of the min value in the unsorted portion of the
// vector.
// PROFPAT: How do we define the "template" type T here?
void selection_sort(vector<T> &vals) {
}

// PROFPAT: I updated the argument passing to const&.  The function
// PROFPAT: returns a copy -- not what I would have picked (I would
// PROFPAT: return a const T& here), but hey Zybooks will do it Zybooks
// PROFPAT: way :-)
// 
// Passes in a vector of type T (T could be string, double or int) and
// an index of type int. The function returns the element located at
// the index of the vals.
// PROFPAT: How do we define the "template" type T here?
T getElement(const vector<T>& vals, int index) {
  // PROFPAT: This is a stub.  Just returns a default value of type T
  // PROFPAT: Should return the value or throw out_of_range.
  // PROFPAT: Question:  Should you use .at() or [] here?
  return T();
}

// PROFPAT: Make this and then run with % ./a.out < test.txt
// ZYBOOKS: You should write up a try catch block in main function 
// ZYBOOKS: so that when the index is out of the range of the
// ZYBOOKS: vector, the "std::outofrange" exception will be caught 
// ZYBOOKS: by the catch(const std::outofrange& excpt).
// ZYBOOKS: Once the exception is caught, it
// ZYBOOKS: should output "out of range exception occured" followed by a
// ZYBOOKS: new line.
// ZYBOOKS: 
// ZYBOOKS: You should come up with test harnesses to test your
// ZYBOOKS: selection_sort function.
int main() {
  // Seeding the random number generator so we get a different
  // run every time.
  srand(time(0));

  // Fill in a vector of some random size with some random
  // characters
  vector<char> vals = createVector();
  int numOfRuns = 10;
  while(--numOfRuns >= 0){
    cout << "Enter a number: " << endl;
    // PROFPAT: Just because zybooks doesn't think it is important
    // PROFPAT: to check inputs doesn't mean you should skip it
    int index;
    if (not (cin >> index)) {
      throw runtime_error("could not read the index");
    }

    // PROFPAT: We will use a try/catch block here to "protect"
    // PROFPAT: the call to getElement() otherwise the program
    // PROFPAT: will terminate on the throw.  Remember!  The
    // PROFPAT: throw happens where we detect the issue.  The
    // PROFPAT: try/catch occurs where we want to handle it!!!!
    char curChar = getElement(vals,index);
    cout << "Element located at " << index << ": is " << curChar << endl;
  }

  // PROFPAT:  You should test selection sort here!!!!
  return 0;
}
