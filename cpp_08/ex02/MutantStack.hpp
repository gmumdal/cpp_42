
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename F = std::deque<T> >
class MutantStack : public std::stack<T, F>
{
	public:
		MutantStack() : std::stack<T, F>() {
			std::cout << "MutantStack constructor called" << std::endl;
		}
		~MutantStack() {
			std::cout << "MutantStack destructor called" << std::endl;
		}
		MutantStack(const MutantStack &copy) : std::stack<T, F> (copy) {
			std::cout << "MutantStack copy constructor called" << std::endl;
		}
		MutantStack &operator= (const MutantStack &copy) {
			if (this == &copy)
				return (*this);
			*this = copy;
			std::cout << "MutantStack copy operator called" << std::endl;
			return (*this);
		}

		typedef typename F::iterator iterator;
		typedef typename F::const_iterator const_iterator;
		typedef typename F::reverse_iterator reverse_iterator;
		typedef typename F::const_reverse_iterator const_reverse_iterator;
		
		//default
		iterator	begin() {
			return (this->c.begin());
		}
		iterator	end() {
			return (this->c.end());
		}
		const_iterator	begin() const {
			return (this->c.begin());
		}
		const_iterator	end() const {
			return (this->c.end());
		}
		
		//reverse
		reverse_iterator	rbegin() {
			return (this->c.rbegin());
		}
		reverse_iterator	rend() {
			return (this->c.rend());
		}
		const_reverse_iterator	rbegin() const {
			return (this->c.rbegin());
		}
		const_reverse_iterator	rend() const {
			return (this->c.rend());
		}
};

#endif
