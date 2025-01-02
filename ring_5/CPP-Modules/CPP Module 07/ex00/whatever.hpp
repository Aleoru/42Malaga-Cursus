/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:10:26 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/23 19:35:38 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template< typename T >
void	swap(T &a, T &b){
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
T	max(T const &a, T const &b){
	return ((a>b) ? a : b);
}

template< typename T >
T	min(T const &a, T const &b){
	return ((a<b) ? a : b);
}

#endif