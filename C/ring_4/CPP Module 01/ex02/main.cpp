/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:37 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:51:39 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){

	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "string address: " << &string << std::endl;
	std::cout << "PTR address: " << stringPTR << std::endl;
	std::cout << "REF address: " << &stringREF << std::endl;
	std::cout << "string value: " << string << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;

}
