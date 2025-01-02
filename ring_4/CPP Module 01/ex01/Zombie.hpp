/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:50:39 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:50:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

	public:

		Zombie(std::string str);
		Zombie(void);
		~Zombie(void);
		void	announce( void );
		void	set_name(std::string name);

	private:

		std::string	_name;

};

#endif
