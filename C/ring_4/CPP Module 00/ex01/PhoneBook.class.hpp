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
		Contact	get_contact(int index);
		std::string	adapt_str(std::string data);

	private:
		int		_index;
		Contact	_contacts[8];

};

#endif