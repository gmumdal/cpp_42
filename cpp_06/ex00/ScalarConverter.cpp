
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
	std::cout << "* ScalarConverter constructor called *" << std::endl;
}

ScalarConverter::~ScalarConverter() 
{
	std::cout << "* ScalarConverter destructor called *" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	(void)copy;
	std::cout << "* ScalarConverter copy constructor called *" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) 
{
	(void)copy;
	std::cout << "* ScalarConverter copy operator called *" << std::endl;
	return (*this);
}

int ScalarConverter::checkType(const std::string &target) 
{
	if (target == "inff" || target == "+inff" || target == "-inff" || target == "nanf")
		return (FLOAT);
	if (target == "inf" || target == "+inf" || target == "-inf" || target == "nan")
		return (DOUBLE);
	if (target[0] < '0' || target[0] > '9') 
	{
		if (target.size() == 1)
			return (CHAR);
		if ((target[0] != '-' && target[0] != '+') && target.size() > 1)
			return (STR_ERROR);
		else if ((target[0] == '-' || target[0] == '+') && (target[1] < '0' || target[1] > '9'))
			return (STR_ERROR);
	}
	int	zom = 0;
	for (unsigned long i = 1; i < target.size(); i++)
	{
		if (target[i] < '0' || target[i] > '9')
		{
			if (target[i] == '.' && (i == target.size() - 1 || zom == 1))
				return (STR_ERROR);
			else if (target[i] == '.')
				zom++;
			else if ((target[i] == 'f' && (i != target.size() - 1 || target[i - 1] == '.')))
				return (STR_ERROR);
			else
				return (STR_ERROR);
		}
	}
	if (target.find(".") == std::string::npos && target.size() <= 19)
		return (INT);
	else if (target.find(".") == std::string::npos && target.size() > 19)
		return (SIZE_ERROR);
	if (target.find("f", 0) == std::string::npos)
		return (DOUBLE);
	else
		return (FLOAT);
}

void	ScalarConverter::charConvert(const std::string &target) 
{
	char	c = target[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	printConvert(c, i, f, d, OK);
}

void ScalarConverter::intConvert(const std::string &target)
{
	long	l = std::atol(target.c_str());
	int		i = std::atoi(target.c_str());
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (l > 2147483647 || l < -2147483648)
		printConvert(c, i, f, d, NOINT);
	else if (l > 127 || l < -128)
		printConvert(c, i, f, d, NOCHAR);
	else
		printConvert(c, i, f, d, OK);
}

void ScalarConverter::floatConvert(const std::string &target)
{
	float	f = std::strtod(target.c_str(), NULL);
	char	c = static_cast<char>(f);
	long	l = static_cast<long>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	if (target == "inff" || target == "+inff" || target == "-inff" || target == "nanf")
		printConvert(c, i, f, d, NOINT);
	else if (l > 2147483647 || l < -2147483648)
		printConvert(c, i, f, d, NOINT);
	else
		printConvert(c, i, f, d, OK);
}

void ScalarConverter::doubleConvert(const std::string &target)
{
	double	d = std::strtod(target.c_str(), NULL);
	char	c = static_cast<char>(d);
	long	l = static_cast<long>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	if (target == "inf" || target == "+inf" || target == "-inf" || target == "nan")
		printConvert(c, i, f, d, NOINT);
	else if (l > 2147483647 || l < -2147483648)
		printConvert(c, i, f, d, NOINT);
	else
		printConvert(c, i, f, d, OK);
}

void ScalarConverter::strError(const std::string &target)
{
	std::cout << "str error: \"" << target << "\"" << std::endl;
}

void ScalarConverter::sizeError(const std::string &target)
{
	std::cout << "size error: \"" << target << "\"" << std::endl;
}

void	ScalarConverter::printConvert(char c, int i, float f, double d, int check)
{
	if (c >= 32 && c <= 126 && check == OK)
		std::cout << "char: \'" << c << "\'" << std::endl;
	else if (check == OK)
		std::cout << "char: Non displayable" << std::endl;
	else if (check > OK)
		std::cout << "char: impossible" << std::endl;
	if (check < NOINT)
		std::cout << "int: " << i << std::endl;
	else if (check == NOINT)
		std::cout << "int: " << "impossible" << std::endl;
	if (f - i == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
