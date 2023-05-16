#include "Harl.hpp"

int	main(void) {

	Harl		harl;
	std::string	input;

	while (input.compare("EXIT") != 0){

		std::cout << "Enter a level: ";
		std::cin >> input;
		harl.complain(input);

	}
	return (0);
}