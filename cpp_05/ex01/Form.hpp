
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			sign_grade;
		const int			execute_grade;

		Form();
		Form &operator= (const Form &copy);

	public:
		Form(const std::string &_name, const int _sign_grade, const int _execute_grade);
		~Form();
		Form(const Form &copy);

		void	beSigned(const Bureaucrat &bureaucrat);

		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		class GradeTooLowException : public std::logic_error
		{
			public:
				GradeTooLowException(const std::string _name);
		};

		class GradeTooHighException : public std::logic_error
		{
			public:
				GradeTooHighException(const std::string _name);
		};
};

std::ostream	&operator<< (std::ostream& os, const Form &form);

#endif
