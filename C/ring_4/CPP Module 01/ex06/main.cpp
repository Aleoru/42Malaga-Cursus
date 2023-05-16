#include "Harl.hpp"

int	main(int argc, char	**argv) {

	Harl		harl;
	std::string	input;

	if (argc < 2) {
		std::cout << "This program needs a parameter" << std::endl;
	}
	harl.complain(argv[1]);
	return (0);
}