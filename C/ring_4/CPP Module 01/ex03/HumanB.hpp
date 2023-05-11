#ifndef HUMAN_B
#define HUMAN_B

#include <iostream>
#include "Weapon.hpp"

class HumanB{

	public:

		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &weapon);
		void	attack();

	private:

		std::string	_name;
		Weapon		*_weapon;

};

#endif