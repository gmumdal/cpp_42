
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[4];
		AMateria	*save[50];
		int			size;
		int			save_size;
	
		Character();
		
	public:
		Character(const std::string _name);
		virtual ~Character();
		Character(const Character &copy);
		Character &operator= (const Character &copy);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
