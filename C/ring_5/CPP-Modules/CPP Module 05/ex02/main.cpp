/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 19:10:12 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {

	try {
		Bureaucrat	A("Eufrasio", 42);
		Bureaucrat	B("Ermenegildo", 150);
		ShrubberyCreationForm		C("42A");
		ShrubberyCreationForm		D("42B");

		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << D << std::endl;

		A.signForm(C);
		B.signForm(D);

		A.executeForm(C);
		B.executeForm(D);

	}
	catch (const Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}