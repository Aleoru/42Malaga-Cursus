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

	ClapTrap	CT_01("CT_01");
	ClapTrap	CT_02("CT_02");

	CT_01.attack(CT_02.getName());
	CT_02.takeDamage(CT_01.getAttackDamage());
	CT_02.attack(CT_01.getName());
	CT_02.beRepaired(2);

	return 0;

}