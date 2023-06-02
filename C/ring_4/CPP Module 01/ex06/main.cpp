/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:41:31 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/02 13:41:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
