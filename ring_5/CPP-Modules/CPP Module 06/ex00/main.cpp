/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:09:08 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/19 19:04:53 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{

	try {

		if (argc == 2)
			ScalarConverter::convert(argv[1]);
		else
			std::cout << "usage: ./convert [number]" << std::endl;

		return 0;

	} catch (ScalarConverter::ScalarConverterException &e) {
		return 1;
	}

}