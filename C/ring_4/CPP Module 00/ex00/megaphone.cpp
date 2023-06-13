/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:51:33 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 11:51:37 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {

	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	if (argc > 1) {	
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
				std::cout << (char)toupper(argv[i][j++]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
