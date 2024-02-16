
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bure1("bure_1", 150);
		Bureaucrat	bure2("bure_2", 1);
		ShrubberyCreationForm	form1("form_1");
		RobotomyRequestForm		form2("form_2");
		PresidentialPardonForm	form3("form_3");
		//Form	form2("form_2", 151, 50);

		bure1.incGrade();
		bure2.incGrade();
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

		bure2.executeForm(form1);
		bure2.executeForm(form2);
		bure2.executeForm(form3);
		std::cout << "------------------------------" << std::endl;
	
		bure2.signForm(form2);
		bure2.signForm(form3);
		bure2.executeForm(form2);
		bure2.executeForm(form3);
		std::cout << "------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
