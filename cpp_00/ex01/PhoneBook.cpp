
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void	PhoneBook::add_book()
{
	std::string	buf;

	while (42)
	{
		std::cout << "first name : ";
		std::getline(std::cin, buf);
		if (buf[0] == 0)
			continue ;
		contact[index % 8].set_first(buf);
		break ;
	}
	while (42)
	{
		std::cout << "name : ";
		std::getline(std::cin, buf);
		if (buf[0] == 0)
			continue ;
		contact[index % 8].set_name(buf);
		break ;
	}
	while (42)
	{
		std::cout << "nickname : ";
		std::getline(std::cin, buf);
		if (buf[0] == 0)
			continue ;
		contact[index % 8].set_nick(buf);
		break ;
	}
	while (42)
	{
		std::cout << "phone number (xxx-xxxx-xxxx) : ";
		std::getline(std::cin, buf);
		if (buf[0] == 0)
			continue ;
		contact[index % 8].set_number(buf);
		break ;
	}
	while (42)
	{
		std::cout << "secret : ";
		std::getline(std::cin, buf);
		if (buf[0] == 0)
			continue ;
		contact[index % 8].set_secret(buf);
		break ;
	}
	index++;
}

void	PhoneBook::print_book()
{
	int			size;
	std::string	choose;

	if (index > 8)
		size = 8;
	else
		size = index;
	std::cout << std::setw(10) << std::setfill(' ') << std::right << "index" << "|";
	std::cout << std::setw(10) << std::setfill(' ') << std::right << "firstname" << "|";
	std::cout << std::setw(10) << std::setfill(' ') << std::right << "lastname" << "|";
	std::cout << std::setw(10) << std::setfill(' ') << std::right << "nickname" << "|" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(10) << std::setfill(' ') << std::right << i << "|";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << ten_sentence(contact[i].get_first()).substr(0,10) << "|";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << ten_sentence(contact[i].get_name()).substr(0,10) << "|";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << ten_sentence(contact[i].get_nick()).substr(0,10) << "|" << std::endl;
	}
	std::cout << "select index : ";
	std::getline(std::cin, choose);
	if (choose[0] < '0' || choose[0] >= size + '0' || choose[1] != 0 || size == 0)
		std::cout << "wrong index" << std::endl;
	else if (choose[0] - '0' < size)
	{
		std::cout << "first name : " << contact[choose[0] - '0'].get_first() << std::endl;
		std::cout << "last name  : " << contact[choose[0] - '0'].get_name() << std::endl;
		std::cout << "nickname   : " << contact[choose[0] - '0'].get_nick() << std::endl;
		std::cout << "number     : " << contact[choose[0] - '0'].get_number() << std::endl;
		std::cout << "secret     : " << contact[choose[0] - '0'].get_secret() << std::endl;
	}
}

std::string	PhoneBook::ten_sentence(std::string s)
{
	std::string	str;

	str = s;
	if (s.length() > 10)
		str.replace(9, 1, ".");
	return (str);
}
