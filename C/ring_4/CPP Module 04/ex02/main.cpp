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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void){

	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	delete j;
	delete i;

	system("leaks ex02");

	const AAnimal	*array[4];

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
	
	//It contains abstract methods, so it became an abstract class and we can't declare a new AAnimal
	//const AAnimal a = new AAnimal();

	system("leaks ex02");

	return 0;

}