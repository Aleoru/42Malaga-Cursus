/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/09 19:00:15 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {

	try {
		Bureaucrat	A("Eufrasio", 150);
		Bureaucrat	B("Ermenegildo", 80);
		Bureaucrat	C("Eustaquio", 50);
		ShrubberyCreationForm		D("42A");
		RobotomyRequestForm			E("42B");
		PresidentialPardonForm		F("42C");

		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << D << std::endl;
		std::cout << E << std::endl;
		std::cout << F << std::endl;

		A.signForm(D);
		B.signForm(E);
		C.signForm(F);

		A.executeForm(D);
		B.executeForm(E);
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