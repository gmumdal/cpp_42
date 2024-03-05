
#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>

#define BEFORE 0
#define AFTER 1

class PMergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		dq;

		PMergeMe();
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator= (const PMergeMe &copy);

		bool	is_number(const std::string &number);
		void	merge_vec(std::vector< std::pair< int, int > > &before, int iter);
		void	insert_vec(std::vector< std::pair< int, int > > &top, std::vector< std::pair< int, int > > &bot, int iter);


	public:
		PMergeMe(int ac, char **av);
		~PMergeMe();
		void	merge_insert_vec();

		void	print_arr(int state);
};

#endif
