
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0)
{

}
	
void	PhoneBook::add_book()
{
	std::string	buf;

	std::cout << "first name : ";
	std::cin >> buf;
	contact[index % 8].set_first(buf);
	std::cout << "name : ";
	std::cin >> buf;
	contact[index % 8].set_name(buf);
	std::cout << "nickname : ";
	std::cin >> buf;
	contact[index % 8].set_nick(buf);
	std::cout << "phone number (xxx-xxxx-xxxx) : ";
	std::cin >> buf;
	contact[index % 8].set_number(buf);
	std::cout << "darkest secret : ";
	std::cin >> buf;
	contact[index % 8].set_secret(buf);
	index++;
}
void	PhoneBook::print_book()
{
	int	size;
	int	choose;

	if (index > 9)
		size = 8;
	else
		size = index;
	for (int i = 0; i < size; i++)
	{
		std::cout << "|         " << i << "|";
		std::cout << ten_sentence(contact[i].get_first()) << "|";
		std::cout << ten_sentence(contact[i].get_name()) << "|";
		std::cout << ten_sentence(contact[i].get_nick()) << "|" << std::endl; ;
	}
	std::cout << "select index : ";
	std::cin >> choose;
	if (choose < size)
	{
		std::cout << "first name : " << contact[choose].get_first() << std::endl;
		std::cout << "last name  : " << contact[choose].get_name() << std::endl;
		std::cout << "nickname   : " << contact[choose].get_nick() << std::endl;
		std::cout << "number     : " << contact[choose].get_number() << std::endl;
		std::cout << "secret     : " << contact[choose].get_secret() << std::endl;
	}
	else
		std::cout << "wrong index" << std::endl;
}

std::string	PhoneBook::ten_sentence(std::string s)
{
	std::string	str = "          ";

	if (s.length() <= 10)
		str.replace(10 - s.length(), s.length(), s);
	else
	{
		str.replace(0, s.length(), s);
		str.replace(9, 1, ".");
		str.erase(10, str.length() - 10);
	}
	return (str);
}
