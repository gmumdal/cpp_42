
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("no_name", 25, 5) {}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &copy)
{
	(void)copy;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_name) : AForm(_name, 25, 5)
{
	std::cout << "** Presidential constructor called **" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "** Presidential destructor called **" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout << "** Presidential copy constructor called **" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (checkExec(executor) == 0)
		return ;
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
