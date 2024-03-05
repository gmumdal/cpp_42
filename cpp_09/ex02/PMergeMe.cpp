
#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &copy)
{
	(void)copy;
}

PMergeMe &PMergeMe::operator= (const PMergeMe &copy)
{
	(void)copy;
	return (*this);
}

PMergeMe::PMergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (is_number(av[i]) == false)
			throw std::logic_error("Error: not a number: " + std::string(av[i]));
		long long	number = atol(av[i]);
		if (number > 2147483647)
			throw std::logic_error("Error: too large number: " + std::string(av[i]));
		vec.push_back(number);
		dq.push_back(number);
	}
	std::cout << "PMergeMe constructor called" << std::endl;
}

PMergeMe::~PMergeMe()
{
	std::cout << "PMergeMe destructor called" << std::endl;
}

bool	PMergeMe::is_number(const std::string &number)
{
	for (size_t i = 0; i < number.size(); i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (false);
	}
	return (true);
}

void	PMergeMe::print_arr(int state)
{
	/* origin */
	// if (state == BEFORE)
	// 	std::cout << "before: ";
	// if (state == AFTER)
	// 	std::cout << "after: ";
	// for (size_t i = 0; i < vec.size() - 1; i++)
	// 	std::cout << vec[i] << ' ';
	// std::cout << vec[vec.size() -1] << std::endl;

	/* test */
	(void)state;
	std::cout << "------ vector, deque ------" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "] : " << vec[i] << "  |  "
		<< "dq[" << i << "] : " << dq[i] << std::endl;
}

void	PMergeMe::merge_insert_vec()
{
	int	merge_size = vec.size() / 2;
	std::pair< int, int >	odd = std::make_pair(-1, -1);
	if (vec.size() % 2 == 1)
		odd = std::make_pair(vec[vec.size() - 1], vec.size() - 1);
	std::vector< std::pair< int, int > >	top;
	std::vector< std::pair< int, int > >	bot;
	int	i = 0;
	while (merge_size--)
	{
		top.push_back(std::make_pair(vec[i + !(vec[i] > vec[i + 1])], i));
		bot.push_back(std::make_pair(vec[i + (vec[i] > vec[i + 1])], i + 1));
		i += 2;
	}
	merge_vec(top, 1);
	insert_vec(top, bot, 1);
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
	// for (size_t j = 0; j < top.size(); j++)
	// {
	// 	std::cout << "top number: " << top[j].first << "  top index: " << top[j].second << std::endl;
	// 	std::cout << "bot number: " << bot[j].first << "  bot index: " << bot[j].second << std::endl;
	// }
	//	if (odd.first != -1)
	//		std::cout << "odd: " << odd.first << std::endl;
}

void	PMergeMe::merge_vec(std::vector< std::pair< int, int > > &before, int iter)
{
	if (before.size() == 1)
		return ;
	int	merge_size = before.size() / 2;
	std::pair< int, int >	odd = std::make_pair(-1, -1);
	if (before.size() % 2 == 1)
		odd = before[vec.size() - 1];
	std::vector< std::pair< int, int > >	top;
	std::vector< std::pair< int, int > >	bot;
	int	i = 0;
	while (merge_size--)
	{
		top.push_back(before[i + !(before[i].first > before[i + 1].first)]);
		bot.push_back(before[i + (before[i].first > before[i + 1].first)]);
		i += 2;
	}
	merge_vec(top, iter + 1);
	insert_vec(top, bot, iter);
	before = top;
}

void	PMergeMe::insert_vec(std::vector< std::pair< int, int > > &top, std::vector< std::pair< int, int > > &bot, int iter)
{

}
