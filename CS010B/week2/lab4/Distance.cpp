#include "Distance.h"
#include <cstdlib> // for abs value cause my negatoves arent working 


Distance::Distance(){
    _inches = 0.0;
    _feet = 0;
}
   /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
Distance::Distance(unsigned ft, double in){
    if (in < 0.0) {
        in = abs(in);
    }

    // Add extra feet if inches are greater than or equal to 12
    while (in >= 12.0) {
        ft++;
        in -= 12.0;
    }

    _feet = ft;
    _inches = in;

    init(); // Call init to adjust values if necess
}


   /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
  //GGF
Distance::Distance(double in){
   
    unsigned feet = 0;
    if (in < 0.0) {
        in = abs(in);
    }

    while (in >= 12.0) {
        feet++;
        in -= 12.0;
    }

    this->_feet = feet;    
    this->_inches = in; 

    init();
}



   /* Returns just the feet portion of the Distance
   */
unsigned Distance::getFeet() const{
    return _feet;
}


   /* Returns just the inches portion of the Distance
   */
   double Distance::getInches() const{
        return _inches;
   }


   /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
   */
   double Distance::distanceInInches() const{
        double inchesF = _feet*12;

        return inchesF + _inches;
   }


   /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
   */
   double Distance::distanceInFeet() const{
        double feetIn = _inches/12;

        return feetIn + _feet;
   }


   /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
   */
   double Distance::distanceInMeters() const{
        double meters_in = _inches*0.0254;
        double meters_feet = _feet*12*0.0254;

        return meters_in + meters_feet;
   }


   /* Returns the sum of 2 Distances. GGF
   */
   Distance Distance::operator+(const Distance &rhs) const{
        unsigned totalFeet = this->getFeet() + rhs.getFeet();
        double totalInches = this->getInches() + rhs.getInches();


    return Distance(totalFeet, totalInches);
    }
   


   /* Returns the difference between 2 Distances.
   */
   Distance Distance::operator-(const Distance &rhs) const{

    return Distance( this->getInches() - rhs.getInches());
}



   


   /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
   */
  //GGF
   ostream & operator<<(ostream &out, const Distance &rhs){ //'operator<<'
    out << rhs.getFeet() << "'" << " " << rhs.getInches() <<'"';
    return out; 
   }


   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */
   void Distance::init(){
    if (getInches() < 0.0) {
        _inches = -getInches();
    }

    // Adjust inches if they are greater than or equal to 12
    if (getInches() >= 12.0) {
        double extraFeet = getInches() / 12.0;
        double remaining = getInches() - (extraFeet*12);
        _feet = _feet + extraFeet;
        _inches = remaining;
   }
   }
   
    

