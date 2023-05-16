#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void	Harl::complain(std::string level){

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
	case 0:
		this->debug();
		break;
	case 1:
		this->info();
		break;
	case 2:
		this->warning();
		break;
	case 3:
		this->error();
		break;
	default:
		std::cout << "[ Complaining about insignificant problems ]" << std::endl;
		break;
	}

}

void	Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-picklespecial-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
	this->info();
}

void	Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
	this->warning();
}

void	Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming ";
	std::cout << "for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
	this->error();
}

void	Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}