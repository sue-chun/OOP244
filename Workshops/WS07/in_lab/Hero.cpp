// Sue Ming Chun 
// 032343154

#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"

using namespace std;

namespace sict {
	Hero::Hero() {
		hero_name[0] = '\0';
		hero_health = 0;
		hero_attack = 0;
	}

	Hero::Hero(const char* new_name, int new_health, int new_attack) {
		if (new_name != nullptr && new_name[0] != '\0') {
			strncpy(hero_name, new_name, 40);
			hero_health = new_health;
			hero_attack = new_attack;
		}
		else
			*this = Hero();
	}

	void Hero::operator-=(int new_attack) {
		if (new_attack > 0 && hero_health > 0) {
			hero_health -= new_attack;
			if (hero_health < 0)						// if hero_health became negative, set it to 0 
				hero_health = 0;
		}
	}

	bool Hero::isAlive() const {
		if (hero_health > 0)
			return true;
		else
			return false;
	}

	int Hero::attackStrength() const {
		if (hero_attack > 0)
			return hero_attack;
		else
			return 0;
	}

	const char* Hero::getName() const {
		return hero_name;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.hero_name[0] != '\n' && hero.isAlive() && hero.attackStrength() > 0)
			os << hero.hero_name;
		else
			os << "No hero";				// if hero is empty, output "No hero" 
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero challenger = first, defender = second;
		int rounds = 0;

		for (int i = 0; i < max_rounds && challenger.isAlive() && defender.isAlive(); ++i) {
			challenger -= defender.attackStrength();
			defender -= challenger.attackStrength();
			rounds = i+1;				// +1 because arrays start at 0 but rounds start at 1 
		}

		if (!challenger.isAlive()) {
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << second.getName() << " in " << rounds << " rounds." << endl;
			return second;
		}

		else if (!defender.isAlive()) {
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << first.getName() << " in " << rounds << " rounds." << endl;
			return first;
		}

		else if (!challenger.isAlive() && !defender.isAlive()) {
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << first.getName() << " in " << rounds << " rounds." << endl;
			return first;
		}
		else 
			return first;
	}
}