/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:36:38 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/14 14:36:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point a, Point b, Point c, Point point);

int	main(void){

	Point	A(1, 5);
	Point	B(3, 1);
	Point	C(5, 5);
	Point	P1(3, 3);
	Point	P2(B);

	std::cout << "Triangle's vertex are: ";
	std::cout << A << " " << B << " " <<  C << std::endl;
	std::cout << "Point 1 is " << P1 << std::endl;
	std::cout << "Point 2 is " << P2 << std::endl;

	if (bsp(A, B, C, P1) == true)
		std::cout << "The point 1 is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point 1 is OUTSIDE the triangle" << std::endl;
	
	if (bsp(A, B, C, P2) == true)
		std::cout << "The point 2 is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point 2 is OUTSIDE the triangle" << std::endl;

	return 0;

}
