/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:46:00 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/17 13:46:00 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {

	std::cout << "Point Default constructor called" << std::endl;

}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()){

	std::cout << "Point Copy constructor called" << std::endl;

}

Point::Point(float const x, float const y) : _x(x), _y(y) {

	std::cout << "Point Parameterized constructor called" << std::endl;

}

Point::~Point(void){

	std::cout << "Point Destructor called" << std::endl;

}

Point & Point::operator=(Point const &rhs){

	//std::cout << "Point Assignation operator called" << std::endl;
	if (this != &rhs){
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return *this;

}

std::ostream & operator<<(std::ostream & o, Point const & rhs) {

	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return o;

}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}
