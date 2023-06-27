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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){

	DiamondTrap	DT_01;
	DiamondTrap	DT_02("DT_02");

	DT_01.attack("bad guys");
	DT_02.takeDamage(30);
	DT_02.beRepaired(20);
	DT_01.whoAmI();
	DT_02.whoAmI();
/* 	DT_01.info();
	DT_02.info(); */

	return 0;

}