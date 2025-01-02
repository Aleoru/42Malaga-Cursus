/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:48:36 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/23 20:08:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {

	int	num[] = {1, 2, 3, 4, 5};

	std::cout << "Iter of 5 int" << std::endl;
	::iter(num, 5, &printany);
	std::cout << std::endl;

	float	fnum[] = {1.6f, 2.2f, 3.35f, 4.2f, 5.0f, 6.85f};

	std::cout << "Iter of 6 float" << std::endl;
	::iter(fnum, 6, &printany);
	std::cout << std::endl;

	char	str[] = {'a', 'b', 'c'};

	std::cout << "Iter of 3 char" << std::endl;
	::iter(str, 3, &printany);

	return (0);
}