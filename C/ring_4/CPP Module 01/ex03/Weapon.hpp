/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:53:16 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:53:18 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{

	public:

		Weapon(std::string type);
		~Weapon(void);
		const std::string &	getType(void);
		void	setType(std::string type);

	private:

		std::string	_type;

};

#endif
