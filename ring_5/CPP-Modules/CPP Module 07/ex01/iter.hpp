/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:50:41 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/23 20:04:33 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template< typename T >
void	iter(T *array, size_t len, void (*f)(T &)){

	for(size_t i = 0; i < len; i++){
		f(array[i]);
	}

}

template< typename T >
void	printany(T &any){

	std::cout << any << std::endl;

}

#endif