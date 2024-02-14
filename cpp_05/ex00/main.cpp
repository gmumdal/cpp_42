
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bure1("bure_1", 151);
		Bureaucrat	bure2("bure_2", 149);
		Bureaucrat	bure3("bure_3", 1);
		
		bure2.decGrade();
		bure2.decGrade();
		bure3.incGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		e.ErrorTooLow();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		e.ErrorTooHigh();
	}

}
