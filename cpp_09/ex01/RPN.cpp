
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) : std::stack< double >(copy) {}

RPN &RPN::operator= (const RPN &copy)
{
	this->result = copy.result;
	return (*this);
}

RPN::RPN(std::string str)
{
	std::string number = "0123456789";
	std::string	oper = "+-*/";
	std::istringstream iss(str);
	std::string buffer;

	while (std::getline(iss, buffer, ' '))
	{
		if (buffer.size() == 0)
			continue ;
		if (buffer.size() > 1)
			throw std::logic_error("Error: invaild argument : " + buffer);
		if (number.find(buffer[0]) != std::string::npos)
			push(buffer[0] - '0');
		else if (oper.find(buffer[0]) != std::string::npos)
		{
			if (size() < 2)
				throw std::logic_error("Error: invaild argument : " + buffer);
			double tmp2 = top();
			pop();
			double tmp1 = top();
			pop();
			if (buffer[0] == oper[0])
				push(tmp1 + tmp2);
			else if (buffer[0] == oper[1])
				push(tmp1 - tmp2);
			else if (buffer[0] == oper[2])
				push(tmp1 * tmp2);
			else if (buffer[0] == oper[3])
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
