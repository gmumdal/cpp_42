
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		//Bureaucrat	bure1("bure_1", 151);
		Bureaucrat	bure2("bure_2", 149);
		Bureaucrat	bure3("bure_3", 1);

		std::cout << bure2 << std::endl;
		bure2.decGrade();
		std::cout << bure2 << std::endl;
		bure2.decGrade();
		bure3.incGrade();
		std::cout << bure2 << std::endl;
		std::cout << bure3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
