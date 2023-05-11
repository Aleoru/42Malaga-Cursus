#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name);

int	main(void){

	int		n = 10;
	Zombie	*horde = zombieHorde(n, "Bob");

	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete	[]	horde;
	return (0);

}