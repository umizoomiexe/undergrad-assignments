#include <string>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD}; //type that can be WIZARD ELF OR WARRIOR 

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType, const string &, double, double);
 	HeroType getType() const;
 	const string & getName() const;
 	int getHealth() const;
 	void damage(double d);
 	bool isAlive() const;
 	virtual void attack(Character &) = 0;
 };

#endif