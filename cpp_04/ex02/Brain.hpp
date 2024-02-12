
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	ideas[100];
		int			size;
	
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain	&operator= (const Brain &copy);
		
		void	make_ideas(const std::string &idea);
		void	say_ideas(void);
		void	dup_ideas(const Brain &copy);
};

#endif