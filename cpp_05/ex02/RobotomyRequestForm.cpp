
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
	try
	{
		checkExec(executor);
		std::cout << "Drill sound : Drrr...!!" << std::endl;
		srand(time(NULL));
		int	tmp = (rand() % 2);

		if (tmp)
			std::cout << "success !" << std::endl;
		else
			std::cout << "fail .." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn’t exeute " << getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}
