#ifndef HUMAN_A
#define HUMAN_A

#include <iostream>
#include "Weapon.hpp"

class HumanA{

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	setWeapon(Weapon weapon);
		void	attack(void);

	private:

		std::string	_name;
		Weapon		&_weapon;

};

#endif