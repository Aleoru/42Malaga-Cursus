/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:25:27 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/27 19:51:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		Form(void);

	public:
		Form(std::string const name, int signGrade);
		Form(std::string const name, int signGrade, int execGrade);
		Form(const Form &src);
		~Form(void);

		Form & operator=(Form const & rhs);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		getSigned(void) const;

		void	beSigned(const Bureaucrat& Bureau);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade Too High"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade Too Low"; }
	};

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif