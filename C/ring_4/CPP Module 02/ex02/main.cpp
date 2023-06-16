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

# include <iostream>
#include "Fixed.hpp"

int	main(void){

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

 	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	//std::cout << Fixed::max( a, b ) << std::endl;

	return 0;

}
