/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 19:20:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	try {

		std::cout << "\033[33;1m[    TEST 1    ]\033[0m" << std::endl;
		Bureaucrat A("Eustaquio", 42);
		std::cout << A << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		Bureaucrat B("Eufrasio", 130);
		std::cout << B << std::endl;
		std::cout << "Decreasing grade by one..." << std::endl;
		B.decGrade();
		std::cout << B << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 3    ]\033[0m" << std::endl;
		Bureaucrat C("Ermenegildo", 145);
		std::cout << C << std::endl;
		std::cout << "Increasing grade by nine times..." << std::endl;
		for (int i = 0; i < 9; i++)
			C.incGrade();
		std::cout << C << std::endl;

	}
	catch (const Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}