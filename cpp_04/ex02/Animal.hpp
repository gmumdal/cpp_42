
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
	
		Animal();
		Animal(const Animal &copy);
		Animal	&operator= (const Animal &copy);

	public:
		virtual ~Animal();

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
