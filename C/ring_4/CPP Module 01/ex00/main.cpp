#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void){

	Zombie*	zombie = newZombie("Mike");

	zombie->announce();
	randomChump("Jesse");
	delete	zombie;
	return (0);

}