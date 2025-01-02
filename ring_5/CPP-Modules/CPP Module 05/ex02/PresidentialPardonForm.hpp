/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:02:33 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/09 18:50:39 by aoropeza         ###   ########.fr       */
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

		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		void	execute(Bureaucrat const & executor) const;

};

#endif