#include "thirst.hpp"

int	main(int argc, char **argv){

	if (argc != 4){
		std::cout << "Faltan o sobran parámetros" << std::endl;
		return (2);
	}
	else {

		Thirst	thirst(argv[1]);

		thirst.replace(argv[2], argv[3]);

	}
	return (0);

}