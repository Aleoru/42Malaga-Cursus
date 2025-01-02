/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:51:19 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/23 19:07:46 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>

class	Base{

	public:
		virtual	~Base(void){};
		static Base	*generate(void);
		static void	identify(Base *p);
		static void	identify(Base &p);

};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

#endif