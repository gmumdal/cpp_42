
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
	try
	{
		checkExec(executor);
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
		std::string		tmp = getName() + "_shrubbery";
		std::ofstream	output(tmp.c_str());
		if (!output.is_open())
			return ;
		output << tree;
		output.close();
		std::cout << executor.getName() << " make a tree." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn’t execve " << getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}
