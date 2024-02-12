
#include "Character.hpp"

Character::Character() : name("no_name"), size(0), save_size(0)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 50; i++)
		save[i] = NULL;
	
}

Character::Character(const std::string _name) : name(_name), size(0)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 50; i++)
		save[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 50; i++)
		delete save[i];
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	std::cout << "Character distructor called" << std::endl;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	name = copy.name;
	size = copy.size;
	for (int i = 0; i < size; i++)
		inventory[i] = copy.inventory[i]->clone();
}

Character &Character::operator= (const Character &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Character copy constructor called" << std::endl;
	name = copy.name;
	size = copy.size;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i] == NULL)
			continue ;
		inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	int	idx;

	if (size == 4)
	{
		delete m;
		return ;
	}
	for (idx = 0; idx < 4; idx++)
	{
		if (inventory[idx] == NULL)
			break ;
	}
	inventory[idx] = m;
	size++;
}

void Character::unequip(int idx)
{
	if (inventory[idx] == NULL)
		return ;
	save[save_size++] = inventory[idx];
	inventory[idx] = NULL;
	size--;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
