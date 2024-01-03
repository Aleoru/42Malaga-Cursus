/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:00:59 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/03 14:00:59 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {

	try {

		int	array[] = {23, 51, 42, 124, 7};

		std::list<int>	A(array, array + sizeof(array) / sizeof(int));
		int	res;
		res = easyfind(A, 42);
		std::cout << res << std::endl;

	} catch (const OutOfRangeException &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}