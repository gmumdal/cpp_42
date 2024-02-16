
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		try
		{
			Bureaucrat	bure1("bure_1", 151);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat	bure2("bure_2", 149);
		Bureaucrat	bure3("bure_3", 1);

		std::cout << bure2 << std::endl;
		bure2.decGrade();
		std::cout << bure2 << std::endl;
		bure2.decGrade();
		bure3.incGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
