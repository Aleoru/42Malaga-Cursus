#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(){
	
	this->_index = 0;
	std::cout << "Welcome to your Phone Book, it has been created phonebook succesfully :)";
	std::cout << std::endl;

}

PhoneBook::~PhoneBook(){
	
	std::cout << "Goodbye, your Phone Book has been deleted :(" << std::endl;

}

void	PhoneBook::add_contact(void){

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	if (this->_index >= 8){
		std::cout << "Waring, overwriting info about ";
		std::cout << this->_contacts[this->_index % 8].get_nickname() << std::endl;
	}
	while (!std::cin.eof() && firstName == ""){
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
		this->_contacts[this->_index % 8].set_firstName(firstName);
	}
	while (!std::cin.eof() && lastName == ""){
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
		this->_contacts[this->_index % 8].set_lastName(lastName);
	}
	while (!std::cin.eof() && nickname == ""){
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		this->_contacts[this->_index % 8].set_nickname(nickname);
	}
	while (!std::cin.eof() && phoneNumber == ""){
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNumber);
		this->_contacts[this->_index % 8].set_phoneNumber(phoneNumber);
	}
	while (!std::cin.eof() && secret == ""){
		std::cout << "Darkest secret: ";
		std::getline(std::cin, secret);
		this->_contacts[this->_index % 8].set_secret(secret);
	}
	this->_index++;

}

Contact	PhoneBook::get_contact(int index){
	return	(this->_contacts[index]);
}

void	PhoneBook::search_contact(void){

	std::string str;

	this->print_contacts();
	while (!std::cin.eof()){
		std::cout << "Contact's index: ";
		std::getline(std::cin, str);
		if (str.length() == 1 && (str[0] >= '1' && str[0] <= '8')){
				this->print_selected(this->_contacts[str[0] - 1 - '0']);
				break ;
		}
		else if ((str.length() == 1 && (str[0] < '1' || str[0] > '8')) || str.length() != 1  || str == "")
			std::cout << "Invalid index!" << std::endl;
	}

}

void	PhoneBook::print_contacts(void){

	for (int index = 0; index < this->_index; index++){
		std::cout << index + 1 << "|";
		std::cout << this->adapt_str(this->get_contact(index).get_firstName()) << "|";
		std::cout << this->adapt_str(this->get_contact(index).get_lastName()) << "|";
		std::cout << this->adapt_str(this->get_contact(index).get_nickname()) << "|";
		std::cout << std::endl;
	}

}

void	PhoneBook::print_selected(Contact contact){

	if (!contact.get_firstName().length()){
		std::cout << "Information request for this contact failed" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.get_firstName() << std::endl;
	std::cout << "Last name: " << contact.get_lastName() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;

}

std::string	PhoneBook::adapt_str(std::string data){

	std::string str;
	int			len;

	len = data.length();
	if (len < 10) {
		str.assign(10 - len, ' ');
		str += data;
		return (str);
	}
	else if (len > 10) {
		str.assign(data, 0, 9);
		str += '.';
		return (str);
	}
	else
		return (data);
}