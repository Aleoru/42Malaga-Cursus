#include "Zombie.hpp"

Zombie::Zombie(std::string str){

	this->_name.assign(str);

}

Zombie::~Zombie(void){

	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl; 

}

void	Zombie::announce(void){

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}