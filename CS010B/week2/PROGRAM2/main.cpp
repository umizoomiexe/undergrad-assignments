#include <iostream>
#include <string>
#include <vector>// needed to make vectors
#include <cctype> // for tolower function

using namespace std;


class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const string &mn, unsigned d, unsigned y);
    void printNumeric() const;
    void printAlpha() const;

private:
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth(unsigned m, unsigned y) const;
    string name(unsigned m) const;
    unsigned number(const string &mn) const;
};


// creates the date January 1st, 2000. Default constructor
   Date::Date() {
      vector<string> monthName_vector = {"January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
      month = 1;
      day = 1;
      year = 2000;
   }

   Date::Date(unsigned m, unsigned d, unsigned y){
      this->monthName = "December";

      if((m < 1 || m > 12)&& (d < 1 || d > daysPerMonth(m,y))) {
         if(d> daysPerMonth(m,y)) {
            d = daysPerMonth(m,y);
            }

         if(d <1){
            d =1;
            }

         if (m > 12){
            m = 12;
            }
         
         if(m<1){
            m =1;
            }
            cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
      }
      else if(m < 1 || m > 12){
         if (m > 12){
            m = 12;
            }
         
         if(m<1){
            m =1;
            }
         cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
      }

      else if(d < 1 || d > daysPerMonth(m,y)){
         if(d> daysPerMonth(m,y)) {
            d = daysPerMonth(m,y);
            }

         if(d <1){
            d =1;
         }
         cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;

      }
      else{
         monthName = name(m);
         }
      month = m;
      day = d;  
      year = y;
   }
   //choice 2 uses this
   Date::Date(const string &mn, unsigned d, unsigned y){

      unsigned m = number(mn);

      if(m==0){
         m = 1;
         d = 1;
         y = 2000;
         cout << "Invalid month name: the Date was set to " << m << "/" << d << "/" << y << "." << endl;
      }
      else if(d> daysPerMonth(m,y)) {
         d = daysPerMonth(m,y);
         cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
      }
      else if(d <1){
         d = 1;
         cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
      }

      month = m;
      day = d;
      year = y;
      monthName = mn;
   }


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void Date::printNumeric() const{
      cout << month << '/' << day << '/' << year;
   }


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void Date::printAlpha() const{
      string monthAsString = name(month);
      cout << monthAsString << ' ' << day << ", " << year;
   }

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool Date::isLeap(unsigned y) const{
      if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
         return true;
      } 
      else {
        return false;
      }
   }


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
      if (m == 2) {
         if (isLeap(y)) {
            return 29;
            } 
        else {
            return 28;
            } 
      }
      if (m == 4 || m == 6 || m == 9 || m == 11) {
         return 30;
         } 
      return 31;
        
   }

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string Date::name(unsigned m) const{

      vector<string> monthNames = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", 
        "November", "December" };

      if (m >= 1 && m <= 12) {
         return monthNames[m - 1];  // Adjust for 0-based vector index
      }
      else {
        return "Invalid Month";
      }

   }

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned Date::number(const string &mn) const{

      vector<string> monthNames = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", 
        "November", "December" };

       string lowerMn = mn;
       unsigned int i;
         for(i=0; i< lowerMn.length(); ++i){ 
            tolower(lowerMn.at(i));
         } 

         lowerMn.at(0) = toupper(lowerMn.at(0));

         for( i=0; i< monthNames.size(); ++i){ 
            if (lowerMn == monthNames.at(i)) {
               return i + 1;
            }
         }
         
   
      return 0; 
   }





// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
