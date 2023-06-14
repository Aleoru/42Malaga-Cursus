/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:50:59 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:51:00 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name){

	if (N > 0) {
		Zombie	*horde = new Zombie[N];

		for (int i = 0; i < N; i++)
			horde[i].set_name(name);
		
		return (horde);
	} else
		return NULL;
}
