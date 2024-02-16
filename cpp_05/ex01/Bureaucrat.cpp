
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooLowException(name);
	else if (grade < 1)
		throw GradeTooHighException(name);
	std::cout << "* Bureaucrat constructor called *" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "* Bureaucrat distructor called *" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "* Bureaucrat copy constructor called *" << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &copy)
{
	(void)copy;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::incGrade(void)
{
	try
	{
		if (grade == 1)
			throw GradeTooHighException(name);
		grade--;
		std::cout << name << " " <<  grade + 1 << "->" << grade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Increase fail, because " << e.what() << std::endl;
	}
}

void	Bureaucrat::decGrade(void)
{
	try
	{	
		if (grade == 150)
			throw GradeTooLowException(name);
		grade++;
		std::cout << name << " " << grade - 1 << "->" << grade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Decrease fail, because " << e.what() << std::endl;
	}
}

std::ostream	&operator<< (std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &_name) : logic_error(_name + " Grade Too High ..") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &_name) : logic_error(_name + " Grade Too Low ..") {}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}
