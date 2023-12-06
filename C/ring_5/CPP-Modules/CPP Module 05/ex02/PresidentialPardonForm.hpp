/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:02:33 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 20:10:07 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm{

	private:
		const std::string	_target;
		PresidentialPardonForm(void);
	
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm & rhs);
		void	execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif