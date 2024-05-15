
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
    void (*converter[7])(const std::string &target) = {
        NULL, &ScalarConverter::charConvert,
        &ScalarConverter::intConvert, &ScalarConverter::floatConvert,
        &ScalarConverter::doubleConvert, &ScalarConverter::strError, &ScalarConverter::sizeError};
	
	converter[ScalarConverter::checkType(av[1])](av[1]); 
    return (0);
}
