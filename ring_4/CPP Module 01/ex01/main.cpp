/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:50:50 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:50:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name);

int	main(void){

	int		n = -10;
	Zombie	*horde = zombieHorde(n, "Bob");

	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete	[]	horde;
	return (0);

}
