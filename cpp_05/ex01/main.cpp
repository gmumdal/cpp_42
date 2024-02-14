
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bure1("bure_1", 150);
		Bureaucrat	bure2("bure_2", 1);
		Form	form1("form_1", 50, 50);
		//Form	form2("form_2", 151, 50);

		bure1.signForm(form1);
		std::cout << "------------------------------" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << "------------------------------" << std::endl;
		bure2.signForm(form1);
		std::cout << "------------------------------" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << "------------------------------" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		e.ErrorTooLow();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		e.ErrorTooHigh();
	}
	catch(const Form::GradeTooLowException& e)
	{
		e.ErrorTooLow();
	}
	catch(const Form::GradeTooHighException& e)
	{
		e.ErrorTooHigh();
	}

}
