
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	first;
		std::string	name;
		std::string	nick;
		std::string	number;
		std::string	secret;
	
	public:
		Contact();

		void		set_first(const std::string &s);
		void		set_name(const std::string &s);
		void		set_nick(const std::string &s);
		void		set_number(const std::string &s);
		void		set_secret(const std::string &s);
		std::string	get_first() const;
		std::string	get_name() const;
		std::string	get_nick() const;
		std::string	get_number() const;
		std::string	get_secret() const;
};

#endif