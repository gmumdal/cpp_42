
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;
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
	int i = 0;
	while (it != ite)
	{
		std::cout << "index " << i << " : " << *it << std::endl;
		++it;
		i++;
	}
	std::cout << "--------------------------" << std::endl;
	i = mstack.size() - 1;
	while (rit != rite)
	{
		std::cout << "index " << i << " : " << *rit << std::endl;
		++rit;
		i--;
	}
	std::cout << "--------------------------" << std::endl;
	std::stack<int> s(mstack);
	while (s.size() != 0) {
		std::cout << "pop : " << s.top() << std::endl;
		s.pop();
	}
	return 0;
}

// int main()
// {
// 	std::list<int> mlist;
// 	mlist.push_back(5);
// 	mlist.push_back(17);
// 	std::cout << "front : " << mlist.front() << std::endl;
// 	mlist.pop_back();
// 	std::cout << "size : " << mlist.size() << std::endl;
// 	mlist.push_back(3);
// 	mlist.push_back(5);
// 	mlist.push_back(737);
// 	//[...]
// 	mlist.push_back(0);
// 	std::list<int>::iterator it = mlist.begin();
// 	std::list<int>::iterator ite = mlist.end();
// 	std::list<int>::const_reverse_iterator rit = mlist.rbegin();
// 	std::list<int>::const_reverse_iterator rite = mlist.rend();
// 	++it;
// 	--it;
// 	int i = 0;
// 	while (it != ite)
// 	{
// 		std::cout << "index " << i << " : " << *it << std::endl;
// 		++it;
// 		i++;
// 	}
// 	std::cout << "--------------------------" << std::endl;
// 	i = mlist.size() - 1;
// 	while (rit != rite)
// 	{
// 		std::cout << "index " << i << " : " << *rit << std::endl;
// 		++rit;
// 		i--;
// 	}
// 	return 0;
// }
