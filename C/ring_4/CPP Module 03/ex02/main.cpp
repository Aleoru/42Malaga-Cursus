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

int	main(void){

	FragTrap	FT_01;
	FragTrap	FT_02("FT_02");

	FT_01.attack("someone not so cool");
	FT_02.takeDamage(30);
	FT_02.beRepaired(20);
	FT_02.highFiveGuys();
/* 	FT_01.info();
	FT_02.info(); */


	return 0;

}