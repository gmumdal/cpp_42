
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
		T	&operator[] (int idx)
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
		std::vector<int>	vec;
		Tlist<int>		lst;
	
		PMergeMe();
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator= (const PMergeMe &copy);

		bool is_number(const std::string &number);
		size_t jacobsthal_num(size_t n);
		void merge_vec(std::vector< Pair > &before, int iter);
		void insert_vec(std::vector< Pair > &top, std::vector< Pair > &bot, int iter);
		void insert_vec_odd(std::vector< Pair > &top, Pair &odd);
		std::vector< Pair > binary_search_vec(std::vector<Pair> arr, int start, int end, Pair value);
		void merge_lst(Tlist< Pair > &before, int iter);
		void insert_lst(Tlist< Pair > &top, Tlist< Pair > &bot, int iter);
		void insert_lst_odd(Tlist< Pair > &top, Pair &odd);
		Tlist< Pair > binary_search_lst(Tlist<Pair> arr, int start, int end, Pair value);


	public:
		PMergeMe(int ac, char **av);
		~PMergeMe();
		void merge_insert_vec();
		void merge_insert_lst();

		void print_arr(int state);
};

#endif
