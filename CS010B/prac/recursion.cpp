#include <iostream>
#include <string> 

using namespace std; 



// class Solution {
// public:
    bool isValid(string s) {
        if(s.length()==0){
            return true;
        }
        if(s.length()%2 == 1){
            return false; 
        }

       
        if(s[0] != s[1]){
           return false; 
        }

        s.erase(0);
        s.erase(1);
        isValid( s);

         return true;
    }   
// };

int main() {
    string test1 = "()";

    isValid(test1);
    

}