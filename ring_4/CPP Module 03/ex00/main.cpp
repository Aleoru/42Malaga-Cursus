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

int	main(void){

	ClapTrap	CT_01;
	ClapTrap	CT_02("CT_02");

	CT_01.attack("a robot around");
	CT_02.takeDamage(3);
	CT_02.attack("another robot");
	CT_02.beRepaired(2);
/* 	CT_01.info();
	CT_02.info(); */

	return 0;

}