#include <iostream>

int	main(int argc, char **argv) {

	int		i;
	int		j;

	i = 1;
	if (argc > 1) {	
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
				std::cout << (char)toupper(argv[i][j++]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}