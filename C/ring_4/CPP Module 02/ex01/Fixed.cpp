/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:36:19 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/14 14:36:21 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _n(0){

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(const int n) : _n(n << this->_bits){

	std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed(const float f) : _n(std::roundf(f * (1 << this->_bits))){

	std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed(Fixed const & src){

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

}

Fixed::~Fixed(void){

	std::cout << "Destructor called" << std::endl;

}

Fixed & Fixed::operator=(Fixed const & rhs){

	std::cout << "Assignation operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return *this;

}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){

	o << rhs.toFloat();
	return o;

}

int	Fixed::getRawBits() const {

 	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);

}

void	Fixed::setRawBits(int const raw){

	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;

}

float	Fixed::toFloat(void) const{

	return (static_cast<float>(this->_n) / (1 << this->_bits));

}

int	Fixed::toInt(void) const{

	return (this->_n >> this->_bits);
	
}
