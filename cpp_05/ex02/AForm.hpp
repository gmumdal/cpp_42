
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool		sign;
		const int	sign_grade;
		const int	execute_grade;
		
		AForm();
		AForm &operator= (const AForm &copy);

	public:
		AForm(const std::string &_name, const int _sign_grade, const int _execute_grade);
		virtual ~AForm();
		AForm(const AForm &copy);

		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			checkExec(Bureaucrat const &executor) const;

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
		class SignException : public std::logic_error
		{
			public:
				SignException(const std::string _name);
		};
};

std::ostream	&operator<< (std::ostream& os, const AForm &Aform);

#endif
