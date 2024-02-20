
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define OK 0
#define NO 1

class ScalarConverter 
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		

	public:
		static int checkType(const std::string &target);

		static void charConvert(const std::string &target);
		static void intConvert(const std::string &target);
		static void floatConvert(const std::string &target);
		static void doubleConvert(const std::string &target);
		static void printError(const std::string &target);
		static void	printConvert(char c, int i, float f, double d, int check);
};

#endif
