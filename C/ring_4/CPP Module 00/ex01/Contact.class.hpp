/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:52:38 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 11:52:42 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <iomanip>

class	Contact {

	public:

		Contact(void);
		~Contact(void);
		std::string	get_firstName(void);
		std::string	get_lastName(void);
		std::string	get_nickname(void);
		std::string	get_phoneNumber(void);
		std::string	get_secret(void);
		void	set_firstName(std::string str);
		void	set_lastName(std::string str);
		void	set_nickname(std::string str);
		void	set_phoneNumber(std::string str);
		void	set_secret(std::string str);


	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_secret;
};

#endif
