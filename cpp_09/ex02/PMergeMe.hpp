
#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>
#include <ctime>

#define BEFORE 0
#define AFTER 1

typedef std::pair< int, int > Pair;

template <typename T>
class Tlist : public std::list<T>
{
	public:
		Tlist() : std::list<T>() {}
		~Tlist() {}
		Tlist(const Tlist &copy) : std::list<T>(copy) {}
		Tlist &operator= (const Tlist &copy)
		{
			this->assign(copy.begin(), copy.end());
			return (*this);
		}
		T &operator[] (int idx)
		{
			typename std::list<T>::iterator it = this->begin();
			std::advance(it, idx);
			return (*it);
		}
		typename std::list<T>::iterator	iter(int idx)
		{
			typename std::list<T>::iterator it = this->begin();
			std::advance(it, idx);
			return (it);
		}
};

class PmergeMe
{
	private:
		std::vector<int> vec;
		Tlist<int> lst;
	
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator= (const PmergeMe &copy);

		bool isNumber(const std::string &number);
		size_t jacobsthalNum(size_t n);

		void merge(std::vector< Pair > &before, int iter);
		void insert(std::vector< Pair > &top, std::vector< Pair > &bot, int iter);
		void insertOdd(std::vector< Pair > &top, Pair &odd);
		void binarySearch(std::vector< Pair > &arr, int start, int end, Pair &value);

		void merge(Tlist< Pair > &before, int iter);
		void insert(Tlist< Pair > &top, Tlist< Pair > &bot, int iter);
		void insertOdd(Tlist< Pair > &top, Pair &odd);
		void binarySearch(Tlist< Pair > &arr, int start, int end, Pair &value);


	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void mergeInsertVec();
		void mergeInsertLst();
		void printArr(int state);
};

#endif
