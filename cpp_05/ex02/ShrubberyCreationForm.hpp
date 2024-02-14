
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &copy);
	
	public:
		ShrubberyCreationForm(const std::string &_name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
