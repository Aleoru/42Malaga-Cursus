#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

std::string	Contact::get_firstName(){
	return	(this->_firstName);
}

std::string	Contact::get_lastName(){
	return	(this->_lastName);
}

std::string	Contact::get_nickname(){
	return	(this->_nickname);
}

std::string	Contact::get_phoneNumber(){
	return	(this->_phoneNumber);
}

std::string	Contact::get_secret(){
	return	(this->_secret);
}

void	Contact::set_firstName(std::string str){
	this->_firstName.assign(str);
}

void	Contact::set_lastName(std::string str){
	this->_lastName.assign(str);
}

void	Contact::set_nickname(std::string str){
	this->_nickname.assign(str);
}

void	Contact::set_phoneNumber(std::string str){
	this->_phoneNumber.assign(str);
}

void	Contact::set_secret(std::string str){
	this->_secret.assign(str);
}
