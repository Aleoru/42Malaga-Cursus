/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:47:53 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 20:27:07 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef	struct	s_data
{
	int			num;
	std::string	str;
}		Data;


class	Serializer {

	private:
		Serializer(void);
		Serializer(Serializer &src);
		~Serializer(void);
		Serializer	&operator=(Serializer const &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);

};

#endif