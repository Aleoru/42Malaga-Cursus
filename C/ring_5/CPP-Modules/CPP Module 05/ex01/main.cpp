/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 19:27:01 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	try {

		std::cout << "\033[33;1m[    TEST 1    ]\033[0m" << std::endl;
		Bureaucrat	A("Eufrasio", 42);
		Form		C("42A", 42);
		std::cout << A << std::endl;
		std::cout << C << std::endl;
		A.signForm(C);
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		Bureaucrat	B("Ermenegildo", 100);
		std::cout << B << std::endl;
		Form		D("150B", 90);
		std::cout << D << std::endl;
		B.signForm(D);

	}
	catch (const Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}