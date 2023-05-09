#include <iostream>
#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	pb;

	while (input.compare("EXIT") != 0)
	{
		std::cout << "Phone Book: ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			pb.add_contact();
		else if (input.compare("SEARCH") == 0)
			pb.search_contact();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}