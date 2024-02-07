
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
	
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal	&operator= (const Animal &copy);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
