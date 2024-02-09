
#include "Brain.hpp"

Brain::Brain() : size(2)
{
	std::cout << "Brain constructor called" << std::endl;
	ideas[0] = "Who am I..?";
	ideas[1] = "Where am I?!";
}

Brain::~Brain()
{
	std::cout << "Brain distructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	size = copy.size;
	for (int i = 0; i < size; i++)
		ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator= (const Brain &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Brain copy assignment operator called" << std::endl;
	size = copy.size;
	for (int i = 0; i < size; i++)
		ideas[i] = copy.ideas[i];
	return (*this);
}

void	Brain::make_ideas(std::string &idea)
{
	if (size == 99)
	{
		std::cout << "I can't think anymore" << std::endl;
		return ;
	}
	ideas[size] = idea;
	size++;
}

void	Brain::say_ideas(void)
{
	if (size == 0)
	{
		std::cout << "I don't think anything" << std::endl;
		return ;
	}
	for (int i = 0; i < size; i++)
		std::cout << ideas[i] << std::endl;
}
