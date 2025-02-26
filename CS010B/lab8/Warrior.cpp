//Warrior.cpp

#include <iostream> 
#include <iomanip>

#include "Warrior.h"

using namespace std;

// must call character(HeroType, const string &, double, double); to initialize warrior as character , allegiance is already part of warrior class so initialize as normal
Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance)
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance){ //ordermatters, do character first and tehn allegiance
}

const string Warrior::getAllegiance(){
    return allegiance; 
}

void Warrior::attack(Character &enemy) {
    
    if(enemy.getType() == WARRIOR) { // they could have same allegiance, check for that 
    //dynamic cast enemy ??? static cast enemy?? so getAllegiance iwll work 
    Warrior &opponent = dynamic_cast<Warrior&>(enemy); 
        if(opponent.getAllegiance() == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << enemy.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl; 
            return; 
        }
    }

    double initial_health = health /MAX_HEALTH;
    double damage = initial_health*attackStrength;

    
    // if((damage*100)%10 ==0){
    //     setprecision_num == 1
    // } ..checl if it even is decimal 


    cout << "Warrior " << getName() << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
    cout << enemy.getName() << " takes " << damage << " damage." << endl;

    enemy.damage(damage);
    
}
    
    