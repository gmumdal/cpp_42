
#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

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

class PMergeMe
{
	private:
		std::vector<int> vec;
		Tlist<int> lst;
	
		PMergeMe();
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator= (const PMergeMe &copy);

		bool isNumber(const std::string &number);
		size_t jacobsthalNum(size_t n);

		void mergeVec(std::vector< Pair > &before, int iter);
		void insertVec(std::vector< Pair > &top, std::vector< Pair > &bot, int iter);
		void insertVecOdd(std::vector< Pair > &top, Pair &odd);
		std::vector< Pair > binarySearchVec(std::vector<Pair> &arr, int start, int end, Pair &value);

		void mergeLst(Tlist< Pair > &before, int iter);
		void insertLst(Tlist< Pair > &top, Tlist< Pair > &bot, int iter);
		void insertLstOdd(Tlist< Pair > &top, Pair &odd);
		Tlist< Pair > binarySearchLst(Tlist<Pair> &arr, int start, int end, Pair &value);


	public:
		PMergeMe(int ac, char **av);
		~PMergeMe();
		void mergeInsertVec();
		void mergeInsertLst();

		void printArr(int state);
};

#endif
