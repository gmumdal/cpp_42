
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) : std::stack< double, std::deque<double> >(copy) {}

RPN &RPN::operator= (const RPN &copy)
{
	*this = copy;
	return (*this);
}

RPN::RPN(std::string str)
{
	std::string number = "0123456789";
	std::string	oper = "+-*/";
	double	tmp1;
	double	tmp2;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			continue ;
		if (number.find(str[i]) != std::string::npos)
			push(str[i] - '0');
		else if (oper.find(str[i]) != std::string::npos)
		{
			if (size() < 2)
				throw std::logic_error("Error");
			tmp2 = top();
			pop();
			tmp1 = top();
			pop();
			if (str[i] == '+')
				push(tmp1 + tmp2);
			else if (str[i] == '-')
				push(tmp1 - tmp2);
			else if (str[i] == '*')
				push(tmp1 * tmp2);
			else if (str[i] == '/')
			{
				if (tmp2 == 0)
					throw std::logic_error("Error: division by Zero");
				push(tmp1 / tmp2);
			}
		}
		else
			throw std::logic_error("Error");
	}
	if (size() != 1)
		throw std::logic_error("Error: incorrect formula");
	result = top();
	pop();
	std::cout << "* RPN constructor called *" << std::endl;
}

RPN::~RPN()
{
	std::cout << "* RPN destructor called *" << std::endl;
}

double	RPN::getResult() const
{
	return (result);
}
