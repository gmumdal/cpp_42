
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
		lst.push_back(number);
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
	std::list<int>::iterator	it = lst.begin();
	std::cout << "------ vector, deque ------" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "] : " << vec[i] << "  |  "
		<< "lst[" << i << "] : " << *it++ << std::endl;
}

void	PMergeMe::merge_insert_vec()
{
	int	merge_size = vec.size() / 2;
	std::pair< int, int >	odd = std::make_pair(-1, -1);
	if (vec.size() % 2 == 1)
		odd = std::make_pair(vec[vec.size() - 1], -1);
	std::vector< std::pair< int, int > >	top;
	std::vector< std::pair< int, int > >	bot;
	int	i = 0;
	int	index = 0;
	while (merge_size--)
	{
		top.push_back(std::make_pair(vec[i + !(vec[i] > vec[i + 1])], index++));
		bot.push_back(std::make_pair(vec[i + (vec[i] > vec[i + 1])], -1));
		i += 2;
	}
	merge_vec(top, 1);
	insert_vec(top, bot, 0);
	if (odd.first > -1)
		insert_odd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
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
	if (odd.first > -1)
		insert_odd(top, odd);
	before = top;
}

void	PMergeMe::insert_vec(std::vector< std::pair< int, int > > &top, std::vector< std::pair< int, int > > &bot, int iter)
{
	for (size_t i = 0; i < bot.size(); i++)
	{
		int	check = top[i * 2].second / pow(2, iter);
		int	st = 0;
		int	en = i * 2;
		while (st != en)
		{
			int	mid = st + en / 2;
			if (top[mid].first > bot[check].first)
				en = mid - 1;
			else
				st = mid + 1;
		}
		if (top[st].first > bot[check].first)
			top.insert(top.begin() + st, bot[check]);
		else
			top.insert(top.begin() + st + 1, bot[check]);
	}
}

void	PMergeMe::insert_odd(std::vector< std::pair< int, int > > &top, std::pair< int, int > &odd)
{
	int	st = 0;
	int	en = top.size() - 1;
	while (st != en)
	{
		int	mid = st + en / 2;
		if (top[mid].first > odd.first)
			en = mid - 1;
		else
			st = mid + 1;
	}
	if (top[st].first > odd.first)
		top.insert(top.begin() + st, odd);
	else
		top.insert(top.begin() + st + 1, odd);
}
