// Sue Ming Chun 
// 032343154

#ifndef OOP244_SUPERHERO_H
#define OOP244_SUPERHERO_H

#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int super_bonus;
		int super_defend;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defend);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif