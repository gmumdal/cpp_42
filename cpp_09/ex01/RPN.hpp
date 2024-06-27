
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <string>

class RPN : public std::stack< double >
{
	private:
		double result;
		RPN();
		RPN(const RPN &copy);
		RPN &operator= (const RPN &copy);

	public:
		RPN(std::string str);
		~RPN();
		double getResult() const;
};

#endif
