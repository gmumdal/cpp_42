
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure &copy);
		Cure &operator= (const Cure &copy);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
