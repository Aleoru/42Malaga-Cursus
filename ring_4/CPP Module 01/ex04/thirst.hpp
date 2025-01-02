/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirst.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:37:16 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/02 13:37:17 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THIRST_HPP
# define THIRST_HPP

# include <iostream>
# include <fstream>

class Thirst{

	public:

		Thirst(std::string file);
		~Thirst(void);
		void	replace(std::string s1, std::string s2);

	private:
		
		std::string	_infile;
		std::string	_outfile;

};


#endif
