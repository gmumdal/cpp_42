
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
		~AForm();
		AForm(const AForm &copy);

		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		int				checkExec(Bureaucrat const & executor) const;

		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		class GradeTooLowException
		{
			private:
				const std::string	name;

			public:
				GradeTooLowException(const std::string _name);
				void	ErrorTooLow() const;
		};
		class GradeTooHighException
		{
			private:
				const std::string	name;

			public:
				GradeTooHighException(const std::string _name);
				void	ErrorTooHigh() const;
		};
};

std::ostream	&operator<< (std::ostream& os, const AForm &Aform);

#endif
