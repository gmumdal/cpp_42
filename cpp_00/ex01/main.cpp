
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	buf;
	PhoneBook	phonebook;

	while (42)
	{
		std::cout << "ADD | SEARCH | EXIT : ";
		std::cin >> buf;
		if (buf == "ADD")
			phonebook.add_book();
		if (buf == "SEARCH")
			phonebook.print_book();
		if (buf == "EXIT")
			break ;
	}
}