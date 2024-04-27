
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "* Intern constructor called *" << std::endl;
}

Intern::~Intern()
{
	std::cout << "* Intern destructor called *" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "* Intern copy constructor called *" << std::endl;
}

Intern	&Intern::operator= (const Intern &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "* Intern copy operator called *" << std::endl;
	return (*this);
}

AForm	*Intern::ShrubberyReturn(const std::string _name)
{
	AForm	*form;

	form = new ShrubberyCreationForm(_name);
	return (form);
}

AForm	*Intern::robotomyReturn(const std::string _name)
{
	AForm	*form;

	form = new RobotomyRequestForm(_name);
	return (form);
}

AForm	*Intern::presidentialReturn(const std::string _name)
{
	AForm	*form;

	form = new PresidentialPardonForm(_name);
	return (form);
}

AForm	*Intern::makeForm(std::string type, std::string name)
{
	AForm	*(Intern::*func[3])(const std::string _name);
	func[0] = &Intern::presidentialReturn;
	func[1] = &Intern::robotomyReturn;
	func[2] = &Intern::ShrubberyReturn;
	std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (types[i] == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return ((this->*func[i])(name));
		}
	}
	throw NoType(type);
	return (NULL);
}

Intern::NoType::NoType(std::string _type) : logic_error(_type + "is not type of form") {}
