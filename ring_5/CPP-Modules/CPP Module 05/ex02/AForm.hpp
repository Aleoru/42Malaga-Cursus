/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:25:27 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/05 17:17:49 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		AForm(void);

	public:
		AForm(std::string const name, int signGrade);
		AForm(std::string const name, int signGrade, int execGrade);
		AForm(const AForm &src);
		virtual ~AForm(void);

		AForm & operator=(AForm const & rhs);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		getSigned(void) const;
		void		beSigned(const Bureaucrat& Bureau);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade Too High"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade Too Low"; }
	};

	class IsNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Form is not sign"; }
	};

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif