
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	buf;
	PhoneBook	phonebook;

	while (42)
	{
		std::cout << "ADD | SEARCH | EXIT : ";
		if (!std::getline(std::cin, buf))
		{
			std::cout << std::endl;
			break ;
		}
		if (buf == "ADD")
			phonebook.add_book();
		if (buf == "SEARCH")
			phonebook.print_book();
		if (buf == "EXIT")
			break ;
	}
	return (0);
}