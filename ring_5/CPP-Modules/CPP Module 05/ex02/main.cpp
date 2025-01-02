/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 19:30:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {

	try {

		std::cout << "\033[33;1m[    TEST 1    ]\033[0m" << std::endl;
		Bureaucrat				A("Eufrasio", 130);
		ShrubberyCreationForm	D("42A");
		std::cout << A << std::endl;
		std::cout << D << std::endl;
		A.signForm(D);
		A.executeForm(D);
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		Bureaucrat			B("Ermenegildo", 42);
		RobotomyRequestForm	E("42B");
		std::cout << B << std::endl;
		std::cout << E << std::endl;
		B.signForm(E);
		B.executeForm(E);
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 3    ]\033[0m" << std::endl;
		Bureaucrat				C("Eustaquio", 5);
		PresidentialPardonForm	F("42C");
		std::cout << C << std::endl;
		std::cout << F << std::endl;
		C.signForm(F);
		C.executeForm(F);

	}
	catch (const Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}