/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:38:46 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 18:38:46 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void){

	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;
	delete i;

	const Animal	*array[4];

	std::cout << std::endl;

	for(int i = 0; i < 2; i++){
		array[i] = new Dog();
	}

	for(int i = 2; i < 4; i++){
		array[i] = new Cat();
	}

	for(int i = 0; i < 4; i++){
		delete array[i];
	}
	
	return 0;

}