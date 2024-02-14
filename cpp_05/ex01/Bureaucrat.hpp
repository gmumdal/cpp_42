
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

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

		class GradeTooHighException
		{
			private:
				const std::string	name;

			public:
				GradeTooHighException(const std::string &_name);
				void	ErrorTooHigh() const;
		};

		class GradeTooLowException
		{
			private:
				const std::string	name;

			public:
				GradeTooLowException(const std::string &_name);
				void	ErrorTooLow() const;
		};

		void	signForm(Form &form);
};

std::ostream	&operator<< (std::ostream& os, const Bureaucrat &bureaucrat);

#endif
