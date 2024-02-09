
#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource 
{
	private:
		AMateria	*save[4];
		int			size;

	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator= (const MateriaSource &copy);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
