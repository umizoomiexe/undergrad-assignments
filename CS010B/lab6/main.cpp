// main.cpp

#include <iostream> 
#include "IntVector.h" 

using namespace std; 

int main() {
    IntVector vec1(10,3);

    for(unsigned int i=0; i< vec1.size(); ++i){
        cout << vec1.at(i) << " " ;
    }
    cout << endl;
    vec1.resize(15);

    for(unsigned int i=0; i< vec1.size(); ++i){
        cout << vec1.at(i) << " ";
    }

    
    



    return 0;
}





