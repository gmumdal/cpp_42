
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
    void (*converter[5])(const std::string &target) = {
        &ScalarConverter::printError, &ScalarConverter::charConvert,
        &ScalarConverter::intConvert, &ScalarConverter::floatConvert,
        &ScalarConverter::doubleConvert};
	
	converter[ScalarConverter::checkType(av[1])](av[1]);
    return (0);
}