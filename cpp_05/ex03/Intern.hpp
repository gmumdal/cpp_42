
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:
		AForm	*ShrubberyReturn(const std::string _name);
		AForm	*robotomyReturn(const std::string _name);
		AForm	*presidentialReturn(const std::string _name);

	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern	&operator= (const Intern &copy);

		AForm	*makeForm(std::string type, std::string name);
		
		class NoType : public std::logic_error
		{
			public:
				NoType(std::string _type);
		};
};

#endif
