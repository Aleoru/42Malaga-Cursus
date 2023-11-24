/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/23 19:37:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	try {
		Bureaucrat A;
		Bureaucrat B("Eufrasio", 130);
		Bureaucrat C("Ermenegildo", 145);

		std::cout << A << std::endl;
		std::cout << B << std::endl;
		B.decGrade();
		std::cout << B << std::endl;
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