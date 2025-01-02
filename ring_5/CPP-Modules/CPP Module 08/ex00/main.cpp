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
		int	res;
		std::cout << "Number array used: ";
		for (int i = 0; i < 5; i++)
			std::cout << array[i] << ", ";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 1    ]\033[0m" << std::endl;
		std::list<int>	A(array, array + sizeof(array) / sizeof(int));
		res = easyfind(A, 42);
		std::cout << "List A: " << res << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		std::vector<int>	B(array, array + sizeof(array) / sizeof(int));
		res = easyfind(B, 51);
		std::cout << "Vector B: " << res << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 3    ]\033[0m" << std::endl;
		std::deque<int>	C(array, array + sizeof(array) / sizeof(int));
		res = easyfind(C, 7);
		std::cout << "deque C: " << res << std::endl;

	} catch (const OutOfRangeException &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}