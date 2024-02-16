
#include "Form.hpp"

Form::Form()
	: name("no name"), sign(false), sign_grade(0), execute_grade(0) {}

Form &Form::operator= (const Form &copy)
{
	(void)copy;
	return (*this);
}

Form::Form(const std::string &_name, const int _sign_grade, const int _execute_grade)
	: name(_name), sign(false), sign_grade(_sign_grade), execute_grade(_execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw (GradeTooLowException(name));
	if (sign_grade < 1 || execute_grade < 1)
		throw (GradeTooHighException(name));
	std::cout << "* Form constructor called *" << std::endl;
}

Form::~Form()
{
	std::cout << "* Form destructor called *" << std::endl;
}

Form::Form(const Form &copy)
	: name(copy.name), sign(copy.sign), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
	std::cout << "* Form copy constructor called *" << std::endl;
}

std::string	Form::getName() const
{
	return (name);
}

bool		Form::getSign() const
{
	return (sign);
}

int			Form::getSignGrade() const
{
	return (sign_grade);
}

int			Form::getExecuteGrade() const
{
	return (execute_grade);
}

Form::GradeTooLowException::GradeTooLowException(const std::string _name) : logic_error(_name + " Grade Too Low ..") {}

Form::GradeTooHighException::GradeTooHighException(const std::string _name) : logic_error(_name + " Grade Too High ..") {}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > sign_grade)
			throw (GradeTooLowException(bureaucrat.getName()));
		std::cout << bureaucrat.getName() << " signed " << name << std::endl;
		sign = 1;
	}
	catch(const std::exception &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t sign " << name << " because ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator<< (std::ostream& os, const Form &form)
{
	os << "name : " << form.getName() << std::endl
		<< "sign : " << form.getSign() << std::endl
		<< "sign_grade : " << form.getSignGrade() << std::endl
		<< "execute_grade : " << form.getExecuteGrade();
	return (os);
}
