
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		index;
		Contact	contact[8];

		std::string	ten_sentence(std::string s);
		
	public:
		PhoneBook();
	
		void		add_book();
		void		print_book();
};

#endif