/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:13:33 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/17 16:13:33 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){

	ScavTrap	ST_01;
	ScavTrap	ST_02("ST_02");

	ST_01.attack("an intruder");
	ST_02.takeDamage(10);
	ST_02.attack("another intruder");
	ST_02.guardGate();
	ST_01.takeDamage(50);
	ST_01.beRepaired(20);
	ST_01.info();
	ST_02.info();

	return 0;

}