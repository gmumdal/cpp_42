
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice &copy);
		Ice &operator= (const Ice &copy);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
