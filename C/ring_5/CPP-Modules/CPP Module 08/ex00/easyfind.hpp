/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:01:06 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/03 14:01:06 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <deque>

class	OutOfRangeException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Value Out of Range"; }
};

template <typename T>
int	easyfind(T &cont, int find) {

	int	res = 0;

	if (std::find(cont.begin(), cont.end(), find))
		std::cout << "funciona" << std::endl;
	if (find != res)
		throw std::exception();
	return res;

}

#endif