
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("no_name", 145, 137) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_name) : AForm(_name, 145, 137)
{
	std::cout << "** Shrubbery constructor called **" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "** Shrubbery destructor called **" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "** Shrubbery copy constructor called **" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (checkExec(executor) == 0)
		return ;
	std::string	tree = "     / \\     \n"
                       "    /   \\    \n"
                       "   /     \\   \n"
                       "  /       \\  \n"
                       " /         \\ \n"
                       " -----------  \n"
                       "  /        \\ \n"
                       " /          \\\n"
                       " -----------  \n"
					   "     |||      \n"
					   "     |||      \n";
	std::ofstream	output(getName() + "_shrubbery");
	if (!output.is_open())
		return ;
	output << tree;
	output.close();
}
