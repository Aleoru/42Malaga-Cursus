/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:39:24 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/02 13:39:25 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
