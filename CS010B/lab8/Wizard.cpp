//Wizard.cpp

#include <iostream> 

#include "Wizard.h" 

using namespace std; 

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    : Character(WIZARD, name, health, attackStrength), rank(rank) {
    }

void Wizard::attack(Character &enemy) {
    if (enemy.getType() == WIZARD) {
        Wizard &opponent = dynamic_cast<Wizard&>(enemy);

        // damage based on the ratio of ranks
        double damage = attackStrength * (static_cast<double>(rank) / opponent.getRank());

        cout << "Wizard " << getName() << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() << " takes " << damage << " damage." << endl;

        //update damage 
        enemy.damage(damage);
    } 
    
    else {
        // regular attack without considering health
        double damage = attackStrength;

      
        cout << "Wizard " << getName() << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() << " takes " << damage << " damage." << endl;

        // Apply damage to the opponent
        enemy.damage(damage);
    }
}

int Wizard::getRank() const {
    return rank;
}

