/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:25:20 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 19:25:20 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{

	private:
		std::string	_idea[100];

	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);

		Brain	&operator=(Brain const &rhs);

};

#endif