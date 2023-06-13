/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:54:37 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 11:54:39 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
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
