
#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		RobotomyRequestForm &operator= (const RobotomyRequestForm &copy);

	public:
		RobotomyRequestForm(const std::string &_name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
