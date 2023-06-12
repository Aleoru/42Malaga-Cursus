#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _n(0){

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(const int n){

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(const int n){

	std::cout << "Default constructor called" << std::endl;

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

	o << rhs.getRawBits();
	return o;

}

int	Fixed::getRawBits() const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);

}

void	Fixed::setRawBits(int const raw){

	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;

}

float	Fixed::toFloat(void) const{



}

int	Fixed::toInt(void) const{


	
}