/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:25:27 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/24 20:07:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Form {

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		Form(void);

	public:
		Form(std::string const name, int signGrade);
		Form(const Form &src);
		~Form(void);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade Too High" }
	}

};

#endif