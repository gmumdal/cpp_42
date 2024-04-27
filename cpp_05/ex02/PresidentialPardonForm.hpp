
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		PresidentialPardonForm &operator= (const PresidentialPardonForm &copy);

	public:
		PresidentialPardonForm(const std::string &_name);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		virtual void	execute(Bureaucrat const &executor) const;
};

#endif
