// Sue Ming Chun 
// 032343154

#ifndef OOP244_HERO_H
#define OOP244_HERO_H

namespace sict {
	const int max_rounds = 100;

	class Hero {
		char hero_name[41];
		int hero_health;
		int hero_attack;
	public: 
		Hero();
		Hero(const char* name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* getName() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif