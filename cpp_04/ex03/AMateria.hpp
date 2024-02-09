
#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	type;

		AMateria();
		
	public:
		AMateria(std::string const &_type);
		virtual ~AMateria();
		AMateria(const AMateria &copy);
		AMateria &operator= (const AMateria &copy);
		
		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
