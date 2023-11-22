/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/22 18:43:08 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	try {
		Bureaucrat A;
		Bureaucrat B("Eufrasio", 130);
		Bureaucrat C("Ermenegildo", 145);

		std::cout << A.getName() << std::endl;
		std::cout << A.getGrade() << std::endl;
		std::cout << B.getName() << std::endl;
		std::cout << B.getGrade() << std::endl;

		B.decGrade();

		for (int i = 0; i < 9; i++)
			C.decGrade();

		std::cout << C.getName() << std::endl;
		std::cout << C.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);

}