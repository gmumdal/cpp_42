
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		index;
		Contact	contact[8];

	public:
		PhoneBook();
	
		void		add_book();
		void		print_book();
		std::string	ten_sentence(std::string s);
};

#endif