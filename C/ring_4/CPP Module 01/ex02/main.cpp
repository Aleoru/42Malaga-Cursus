#include <iostream>

int	main(void){

	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "string address: " << &string << std::endl;
	std::cout << "PTR address: " << stringPTR << std::endl;
	std::cout << "REF address: " << &stringREF << std::endl;
	std::cout << "string value: " << string << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;

}