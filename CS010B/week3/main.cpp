
#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
   
};

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {}
Rational::Rational(int num) : numerator(num), denominator(1) {}
Rational::Rational() : numerator(0), denominator(1) {}

Rational Rational::add(const Rational& B) const {
   int a = numerator;
   int b = denominator;
   int c = B.numerator;
   int d = B.denominator;
   int solution_numer = (a*d)+(b*c);
   int solution_denom = (b*d);
   return Rational(solution_numer, solution_denom);
}
Rational Rational::subtract(const Rational& B) const {
   int a = numerator;
   int b = denominator;
   int c = B.numerator;
   int d = B.denominator;
   int solution_numer = (a*d)-(b*c);
   int solution_denom = (b*d);
   return Rational(solution_numer, solution_denom);
}
Rational Rational::multiply(const Rational& B) const {
   int a = numerator;
   int b = denominator;
   int c = B.numerator;
   int d = B.denominator;
   int solution_numer = (a*c);
   int solution_denom = (b*d);
   return Rational(solution_numer, solution_denom);
}
Rational Rational::divide(const Rational& B) const {
   int a = numerator;
   int b = denominator;
   int c = B.numerator;
   int d = B.denominator;
   int solution_numer = (a*d);
   int solution_denom = (b*c);
   return Rational(solution_numer, solution_denom);
}
void Rational::simplify() {
   int a = numerator;
   int b = denominator;
   while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int simplify_num = a;
    numerator /= simplify_num;
    denominator /= simplify_num;
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string&, const Rational&, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}






