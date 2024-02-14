
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("no_name", 72, 45) {}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &copy)
{
	(void)copy;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_name) : AForm(_name, 72, 45)
{
	std::cout << "** Robotomy constructor called **" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "** Robotomy destructor called **" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout << "** Robotomy copy constructor called **" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (checkExec(executor) == 0)
		return ;
	std::cout << "Drill sound : Drrr...!!" << std::endl;
	int	tmp = (rand() % 2);

	if (tmp)
		std::cout << "success !" << std::endl;
	else
		std::cout << "fail .." << std::endl;
}
