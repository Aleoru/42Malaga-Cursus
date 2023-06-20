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

	ClapTrap	CT_01;
	ClapTrap	CT_02("CT_02");
	ScavTrap	ST_01;
	ScavTrap	ST_02("ST_02");

	CT_01.attack("a robot around");
	CT_02.takeDamage(3);
	CT_02.attack("another robot");
	CT_02.beRepaired(2);
	ST_01.attack("an intruder");
	ST_02.takeDamage(10);
	ST_02.attack("another intruder");
	ST_02.guardGate();
	ST_01.takeDamage(50);
	ST_01.beRepaired(20);

	return 0;

}