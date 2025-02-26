//Elf.cpp

#include <iostream> 

#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
    : Character(ELF, name, health, attackStrength), family(family) {

    }

void Elf::attack(Character &enemy) {
    if (enemy.getType() == ELF) {
        Elf &opponent = dynamic_cast<Elf&>(enemy);
        if (family == opponent.family) {
            cout << "Elf " << getName() << " does not attack " << "Elf " << enemy.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    }

    
    double initial_health = health /MAX_HEALTH;
    double damage = initial_health*attackStrength;

    

    cout << "Elf " << getName() << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
    cout << enemy.getName() << " takes " << damage << " damage." << endl;
    enemy.damage(damage);
}
