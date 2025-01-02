/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:33:27 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/28 00:33:27 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* mike = new Character("mike");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	mike->equip(tmp);
	tmp = src->createMateria("cure");
	mike->equip(tmp);

	ICharacter* bob = new Character("bob");

	mike->use(0, *bob);
	mike->use(1, *bob);

	delete bob;
	delete mike;
	delete src;

	return 0;
}