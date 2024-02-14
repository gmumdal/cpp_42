
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooHighException(name);
	else if (grade < 1)
		throw GradeTooLowException(name);
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
	if (grade == 1)
		throw GradeTooHighException(name);
	grade--;
	std::cout << name << " " <<  grade + 1 << "->" << grade << std::endl;
}

void	Bureaucrat::decGrade(void)
{
	if (grade == 150)
		throw GradeTooLowException(name);
	grade++;
	std::cout << name << " " << grade - 1 << "->" << grade << std::endl;
}

std::ostream	&operator<< (std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &_name) : name(_name) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &_name) : name(_name) {}

void	Bureaucrat::GradeTooHighException::ErrorTooHigh() const
{
	std::cerr << name << " grade too high" << std::endl;
}

void	Bureaucrat::GradeTooLowException::ErrorTooLow() const
{
	std::cerr << name << " grade too low" << std::endl;
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
}
