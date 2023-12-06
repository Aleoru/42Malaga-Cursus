/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:46 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 19:16:30 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm{

	private:
		const std::string	_target;
		ShrubberyCreationForm(void);
	
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm & rhs);
		void	execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif