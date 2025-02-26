#include <iostream>
#include <string>
using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipStringhlpr(string &s, int start, int end) {
    if (start >= end) {
        // base case
        return;
    }
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    flipStringhlpr(s, start + 1, end - 1);
}

void flipString(string &s) {
    int length = s.size();
   //  int middle = length / 2;

    flipStringhlpr(s, 0, length - 1);
}
   






