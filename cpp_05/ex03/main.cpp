
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bure1("bure_1", 151);
		Bureaucrat	bure2("bure_2", 1);
		ShrubberyCreationForm	form1("form_1");
		RobotomyRequestForm		form2("form_2");
		PresidentialPardonForm	form3("form_3");
		Intern	intern;

		//Form	form2("form_2", 151, 50);

		bure1.signForm(form1);
		std::cout << "------------------------------" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << "------------------------------" << std::endl;

		bure2.signForm(form1);
		std::cout << "------------------------------" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << "------------------------------" << std::endl;
		
		std::cout << std::endl;

		std::cout << "------------------------------" << std::endl;
		bure1.executeForm(form1);
		bure1.executeForm(form2);
		bure1.executeForm(form3);
		std::cout << "------------------------------" << std::endl;

		//presidential pardon
		//robotomy request
		//shrubbery creation

		std::cout << "------------------------------" << std::endl;
		AForm	*form7 = intern.makeForm("shrubbery creationd", "form_7");
		AForm	*form4 = intern.makeForm("presidential pardon", "form_4");
		AForm	*form5 = intern.makeForm("robotomy request", "form_5");
		AForm	*form6 = intern.makeForm("shrubbery creation", "form_6");

		bure2.executeForm(*form4);
		bure2.executeForm(*form5);
		bure2.executeForm(*form6);
		bure2.executeForm(*form7);
		std::cout << "------------------------------" << std::endl;
		bure2.signForm(*form4);
		bure2.signForm(*form5);
		bure2.signForm(*form6);
		std::cout << "------------------------------" << std::endl;
		bure2.executeForm(*form4);
		bure2.executeForm(*form5);
		bure2.executeForm(*form6);
		std::cout << "------------------------------" << std::endl;

		delete form4;
		delete form5;
		delete form6;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
