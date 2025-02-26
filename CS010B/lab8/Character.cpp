//Character.cpp file (main class)

#include <iostream> 

#include "Character.h"

using namespace std;

/*protected:

HeroType type;
string name;
double health;
double attackStrength; */

 //public:

Character::Character(HeroType type, const string &name, double health, double attackStrength)
  : type(type), name(name), health(health), attackStrength(attackStrength) { // initializes everything without having to type out 
}
HeroType Character::getType() const{
    return type; 
}
const string & Character::getName() const{
    return name; 
}
int Character::getHealth() const{
    return static_cast<int>(health); 
}
void Character::damage(double d){
    health -= d;
    if(health < 0.0){
        health = 0.0;
    }
}
bool Character::isAlive() const{
    if(getHealth() > 0){
        return true;
    }
    return false; 
    
}
//virtual void attack(Character &) = 0;