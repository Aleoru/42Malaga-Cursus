/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:02:41 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:47:18 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class	Intern {

	private:

	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(std::string name, std::string target);

	class	FormDoesNotExistException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Form Does Not Exist"; }
	};

};

#endif