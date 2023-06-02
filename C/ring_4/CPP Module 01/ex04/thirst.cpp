/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirst.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:37:05 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/02 13:37:06 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thirst.hpp"

Thirst::Thirst(std::string file) : _infile(file){

	this->_outfile = file + ".replace";

}

Thirst::~Thirst(){

}

void	Thirst::replace(std::string s1, std::string s2){

	std::ifstream	ifs(this->_infile);
	std::string		str;
	size_t			pos;

	if (!ifs.is_open()){
		std::cout << "Could not open this file" << std::endl;
		return ;
	}
	if (!std::getline(ifs, str, '\0')) {
		ifs.close();
		std::cout << "File is empty." << std::endl;
		return ;
	}
	else {

		std::ofstream	ofs(this->_outfile);
		pos = str.find(s1);
		while (pos != std::string::npos) {
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			pos = str.find(s1);
		}
		ofs << str;
		ofs.close();
	}
	ifs.close();
}
