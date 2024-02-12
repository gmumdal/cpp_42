
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : size(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	save[0] = NULL;
	save[1] = NULL;
	save[2] = NULL;
	save[3] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < size; i++)
		delete save[i];
	std::cout << "MateriaSource distructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	size = copy.size;
	for (int i = 0; i < 4; i++)
	{
		if (copy.save[i] == NULL)
			continue ;
		save[i] = copy.save[i]->clone();
	}
}

MateriaSource &MateriaSource::operator= (const MateriaSource &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "MateriaSource copy operator called" << std::endl;
	size = copy.size;
	for (int i = 0; i < 4; i++)
	{
		if (copy.save[i] == NULL)
			continue ;
		save[i] = copy.save[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (size == 4)
	{
		delete m;
		return ;
	}
	save[size++] = m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*toss;

	toss = NULL;
	for (int i = 0; i < size; i++)
	{
		if (save[i]->getType() == type)
		{
			if (type == "ice")
				toss = new Ice();
			else if (type == "cure")
				toss = new Cure();
			break ;
		}
	}
	return (toss);
}
 