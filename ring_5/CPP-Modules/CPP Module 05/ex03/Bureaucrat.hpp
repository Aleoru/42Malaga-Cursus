/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:39 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 19:09:30 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class	Bureaucrat {

	private:
		std::string const	_name;
		int					_grade;
		Bureaucrat(void);

	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void	incGrade(void);
		void	decGrade(void);
		void	signForm(AForm &Form);
		void	executeForm(AForm const & form) const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual	const char* what() const throw() { return "Grade Too High"; }
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual	const char* what() const throw() { return "Grade Too Low"; }
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif