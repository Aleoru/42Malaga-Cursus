/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:41:10 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:32:50 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("(default)"){
	//std::cout << "Bureaucraft Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target){
	//std::cout << "Bureaucraft Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const{

	if(!this->getSigned())
		throw AForm::IsNotSignedException();
	else if(executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

		std::cout << executor.getName() << " executed " << this->getName() << std::endl;

		std::cout << "Bzzz... Bzzzzzzzz... Bz!! Bzzz..." << std::endl;

		srand(time(NULL));

		int	random = rand();
		if (random % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;


}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs) {

	if (this != &rhs) {
		(void)rhs;
	}
	return *this;

}