
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;	
	
		Bureaucrat();
		Bureaucrat &operator= (const Bureaucrat &copy);

	public:
		Bureaucrat(const std::string &_name, const int _grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incGrade(void);
		void		decGrade(void);

		class GradeTooHighException : public std::logic_error
		{
			public:
				GradeTooHighException(const std::string &_name);
		};

		class GradeTooLowException : public std::logic_error
		{
			public:
				GradeTooLowException(const std::string &_name);
		};

		void	signForm(AForm &form);
		void	executeForm(AForm const &form);
};

std::ostream	&operator<< (std::ostream& os, const Bureaucrat &bureaucrat);

#endif
