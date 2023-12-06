/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:02:28 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 20:06:04 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cmath>
# include <ctime>

class RobotomyRequestForm : public AForm{

	private:
		const std::string	_target;
		RobotomyRequestForm(void);
	
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(RobotomyRequestForm & rhs);
		void	execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif