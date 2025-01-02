/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:46 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/02 13:36:47 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thirst.hpp"

int	main(int argc, char **argv){

	if (argc != 4){
		std::cout << "Faltan o sobran parámetros" << std::endl;
		return (2);
	}
	else {

		Thirst	thirst(argv[1]);

		thirst.replace(argv[2], argv[3]);

	}
	return (0);

}
