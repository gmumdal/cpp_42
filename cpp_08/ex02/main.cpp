
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator rite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "--------------------------" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	std::list<int> lst;
// 	lst.push_back(5);
// 	lst.push_back(17);
// 	std::cout << lst.front() << std::endl;
// 	lst.pop_back();
// 	std::cout << lst.size() << std::endl;
// 	lst.push_back(3);
// 	lst.push_back(5);
// 	lst.push_back(737);
// 	//[...]
// 	lst.push_back(0);
// 	std::list<int>::iterator it = lst.begin();
// 	std::list<int>::iterator ite = lst.end();
// 	std::list<int>::const_reverse_iterator rit = lst.rbegin();
// 	std::list<int>::const_reverse_iterator rite = lst.rend();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::cout << "--------------------------" << std::endl;
// 	while (rit != rite)
// 	{
// 		std::cout << *rit << std::endl;
// 		++rit;
// 	}
// 	return 0;
// }
