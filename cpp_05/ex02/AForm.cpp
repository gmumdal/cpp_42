
#include "AForm.hpp"

AForm::AForm()
	: name("no name"), sign(false), sign_grade(0), execute_grade(0) {}

AForm &AForm::operator= (const AForm &copy)
{
	(void)copy;
	return (*this);
}

AForm::AForm(const std::string &_name, const int _sign_grade, const int _execute_grade)
	: name(_name), sign(false), sign_grade(_sign_grade), execute_grade(_execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw (GradeTooLowException(name));
	if (sign_grade < 1 || execute_grade < 1)
		throw (GradeTooHighException(name));
	std::cout << "* AForm constructor called *" << std::endl;
}

AForm::~AForm()
{
	std::cout << "* AForm destructor called *" << std::endl;
}

AForm::AForm(const AForm &copy)
	: name(copy.name), sign(copy.sign), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
	std::cout << "* AForm copy constructor called *" << std::endl;
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getSign() const
{
	return (sign);
}

int	AForm::getSignGrade() const
{
	return (sign_grade);
}

int	AForm::getExecuteGrade() const
{
	return (execute_grade);
}

AForm::GradeTooLowException::GradeTooLowException(const std::string _name) : name(_name) {}

AForm::GradeTooHighException::GradeTooHighException(const std::string _name) : name(_name) {}

void	AForm::GradeTooLowException::ErrorTooLow() const
{
	std::cerr << name << " grade too low." << std::endl;
}

void	AForm::GradeTooHighException::ErrorTooHigh() const
{
	std::cerr << name << " grade too high." << std::endl;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > sign_grade)
			throw (GradeTooLowException(bureaucrat.getName()));
		std::cout << bureaucrat.getName() << " signed " << name << std::endl;
		sign = 1;
	}
	catch(const GradeTooLowException &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t sign " << name << " because ";
		e.ErrorTooLow();
	}
}

std::ostream	&operator<< (std::ostream& os, const AForm &Aform)
{
	os << "name : " << Aform.getName() << std::endl
		<< "sign : " << Aform.getSign() << std::endl
		<< "sign_grade : " << Aform.getSignGrade() << std::endl
		<< "execute_grade : " << Aform.getExecuteGrade();
	return (os);
}

int	AForm::checkExec(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > execute_grade)
			throw (GradeTooLowException(executor.getName()));
		return (1);
	}
	catch(const GradeTooLowException &e)
	{
		std::cerr << executor.getName() << " couldn’t execve " << name << " because ";
		e.ErrorTooLow();
		return (0);
	}	
}
