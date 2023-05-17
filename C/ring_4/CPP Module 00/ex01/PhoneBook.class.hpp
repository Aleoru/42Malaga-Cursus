/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:54:22 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 11:54:24 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class	PhoneBook {

	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search_contact(void);
		void	print_contacts(void);
		void	print_selected(Contact contact);
		void	fill(void);
		Contact	get_contact(int index);
		std::string	adapt_str(std::string data);

	private:
		int		_index;
		Contact	_contacts[8];

};

#endif
