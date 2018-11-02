// Sue Ming Chun 
// 032343154

#include <iostream>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {
	SuperHero::SuperHero()  {
		super_bonus = 0;
		super_defend = 0;
	}

	SuperHero::SuperHero(const char * name, int health, int attack, int bonus, int defend) : Hero(name, health, attack) {
		super_bonus = bonus;
		super_defend = defend;
	}

	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() > 0)
			return (Hero::attackStrength() + super_bonus);
		else
			return 0;
	}

	int SuperHero::defend() const {
		if (super_defend > 0)
			return super_defend;
		else
			return 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero challenger = first;
		SuperHero defender = second;

		int rounds = 0;

		for (int i = 0; i < max_rounds && (challenger.isAlive() && defender.isAlive()); ++i)
		{
			challenger -= defender.attackStrength() - challenger.defend();
			defender -= challenger.attackStrength() - defender.defend();
			rounds = i + 1;
		}

		if (!challenger.isAlive() && !defender.isAlive()) {
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << first.getName() << " in " << rounds << " rounds." << endl;
			return first;
		}
		else if (!challenger.isAlive()) {
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << second.getName() << " in " << rounds << " rounds." << endl;
			return second;
		}
		else if (!defender.isAlive()) {
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << challenger.getName() << " in " << rounds << " rounds." << endl;
			return first;
		}
		else 
			return first;
	}
}
