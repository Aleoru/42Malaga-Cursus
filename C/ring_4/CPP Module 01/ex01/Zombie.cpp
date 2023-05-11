#include "Zombie.hpp"

Zombie::Zombie(std::string str)	{

	this->_name = str;

}

Zombie::Zombie(void){

	this->_name.assign("nameless");

}

Zombie::~Zombie(void){

	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl; 

}

void	Zombie::announce(void){

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

void	Zombie::set_name(std::string name){

	this->_name = name;

}