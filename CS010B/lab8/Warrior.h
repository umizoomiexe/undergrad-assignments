//Warrior.h
/*Stores the warrior's allegiance as a string.

The warrior does not attack warriors that have the same allegiance.

The damage done by the warrior is the percentage of the warrior's health remaining
(health / MAX_HEALTH) multiplied by the warrior's attack strength.*/

#include <iostream> 
#include <string>

#include "Character.h"

using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Character { 
    private: 
        string allegiance; 

    public: 
        //constructor
        Warrior(const string &name, double health, double attackStrength, const string &allegiance);
        void attack(Character &enemy) override; // ovveride the initial one in character
        const string getAllegiance(); 

};

#endif