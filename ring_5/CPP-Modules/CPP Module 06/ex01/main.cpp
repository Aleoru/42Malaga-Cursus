/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:47:04 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 20:30:23 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void){

	Data	something;

	something.num = 42;
	something.str = "Hi!";

	std::cout << "\033[33;1m[    ORIGINAL    ]\033[0m" << std::endl;
	std::cout << &something << std::endl;
	std::cout << something.num << std::endl;
	std::cout << something.str << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33;1m[   SERIALIZED   ]\033[0m" << std::endl;
	uintptr_t ref = Serializer::serialize(&something);
	std::cout << ref << std::endl;
	std::cout << something.num << std::endl;
	std::cout << something.str << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33;1m[  DESERIALIZED  ]\033[0m" << std::endl;
	Data	*ptr = Serializer::deserialize(ref);
	std::cout << ptr << std::endl;
	std::cout << ptr->num << std::endl;
	std::cout << ptr->str << std::endl;


}