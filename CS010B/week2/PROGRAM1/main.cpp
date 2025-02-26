#include <iostream> 
#include <vector> // for storing
#include <string> //for reading in data originally 
#include <fstream> // for readData function to read from external file (file inoutput)
#include <cstdlib> //it was included in past labs? 

using namespace std;

//1 
void readData(const string &filename, vector<double> &angles, vector<double> &lifts){

    ifstream inputFS;
    inputFS.open(filename);

    if (!inputFS.is_open()) {
        cout << "Error opening " << filename << endl; // why not printing filename???
        exit(EXIT_FAILURE);
    }
    else { 
        double pathangle;
        double colift;

        while (inputFS >> pathangle >> colift) {
            angles.push_back(pathangle);
            lifts.push_back(colift);
        }
        
    inputFS.close();
    }
}

//2 - unit test not passing, issue with this function 
double interpolation(double angle, const vector<double> &angles, const vector<double> &lifts){

        
    if(angle < angles.front() || angle > angles.back()){
        cout << "angle out of bounds.";
        return 0.0;
    }

        
   unsigned star = 0;

    while((star+1) < angles.size() && angles.at(star) < angle){
        star++;
    }

    if(angles.at(star) == angle){
        return lifts.at(star);
    }
   

        double a = angles[star-1];
        double c = angles[star];
        double lift_a = lifts[star-1];
        double lift_c = lifts[star];
        
        double solution = lift_a + ((angle - a) / (c - a)) * (lift_c - lift_a);

        return solution;
}

//3
bool isOrdered(const vector<double> &inputvector){

   for (unsigned int i = 1; i < inputvector.size(); i++) {
        if (inputvector[i] < inputvector[i - 1]) {
            return false;
        }
    }
    return true;
}

//4
void reorder(vector<double> &angles, vector<double> &lifts){
    
    int vector_size = angles.size();
    

    for (int i = 0; i < vector_size - 1; i++) {

        for (int j = 0; j < vector_size - i - 1; j++) {

            if (angles[j] > angles[j + 1]) {

                double temp1 = angles[j];
                angles[j] = angles[j + 1];
                angles[j + 1] = temp1;

                double temp2 = lifts[j];
                lifts[j] = lifts[j + 1];
                lifts[j + 1] = temp2; // I WAS OVERWRITING THEM IT WAS SWAPPED PREVIOUSLY!!!! 

            }
        }
    }
}


// must use all 4 in main//


int main(int argc, char*argv[]) { 
    //definitions
    vector<double> flightpath_angles;
    vector<double> co_lift;
    string filename;

    // use arg command and directly get from command prompt
    filename = argv[1];

    // USED 1 //
    readData(filename, flightpath_angles, co_lift);

    // USED 3 & 4 //
    if (!isOrdered(flightpath_angles)) {   //checking for order (must be in order for interpolation to work)
        reorder(flightpath_angles, co_lift);
    }

    
    while (true) {  //infinite for loop until user says to end (N) 
        double inputangle;
        double lift;
        string yesorno;

        cout << "flight-path angle: "; // idk if i need this 
        cin >> inputangle;

        // USED 2 //
        lift = interpolation(inputangle, flightpath_angles, co_lift);
        cout << "Coefficient of lift: " << lift << endl;

        cout << "another flight-path angle? (Y/N): ";
        cin >> yesorno;
        cout << endl;
        if (toupper(yesorno[0]) != 'Y') { //cause what if user puts lowercase y
            break;
        }
    }

    return 0;
}



