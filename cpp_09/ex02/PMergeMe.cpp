
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

size_t PMergeMe::jacobsthal_num(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
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
		<< "lst[" << i << "] : " << lst[i] << std::endl;
}

void	PMergeMe::merge_insert_vec()
{
	int	merge_size = vec.size() / 2;
	Pair odd = std::make_pair(-1, -1);
	if (vec.size() % 2 == 1)
		odd = std::make_pair(vec[vec.size() - 1], -1);
	std::vector< Pair >	top;
	std::vector< Pair >	bot;
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
		insert_vec_odd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
}

void	PMergeMe::merge_vec(std::vector< Pair > &before, int iter)
{
	if (before.size() == 1)
		return ;
	int	merge_size = before.size() / 2;
	Pair odd = std::make_pair(-1, -1);
	if (before.size() % 2 == 1)
		odd = before[before.size() - 1];
	std::vector< Pair >	top;
	std::vector< Pair >	bot;
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
		insert_vec_odd(top, odd);
	before = top;
}

void PMergeMe::insert_vec(std::vector< Pair > &top, std::vector< Pair > &bot, int iter)
{
	std::vector<Pair> sorted_arr = top;
	sorted_arr.insert(sorted_arr.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1;
	std::vector<size_t> jacobsthalArr;
	for (size_t i = 1; jacobsthal_num(i) < top.size(); i++)
		jacobsthalArr.push_back(jacobsthal_num(i + 1));
	for (size_t j = 1; j < jacobsthalArr.size(); j++) {
		for (size_t jacob_n = jacobsthalArr[j]; jacob_n > jacobsthalArr[j - 1]; jacob_n--) {
			if (jacob_n > top.size()) 
				jacob_n = top.size();
			Pair value = bot[top[jacob_n - 1].second/static_cast<int>(pow(2, iter))];
			sorted_arr = binary_search_vec(sorted_arr, 0, jacob_n + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	top = sorted_arr;
}

std::vector< Pair > PMergeMe::binary_search_vec(std::vector<Pair> arr, int start, int end, Pair value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid].first > value.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (arr[start].first > value.first)
		arr.insert(arr.begin() + start, value);
	else
		arr.insert(arr.begin() + start + 1, value);
	return (arr);
}

void PMergeMe::insert_vec_odd(std::vector< Pair > &top, Pair &odd)
{
	int	st = 0;
	int	en = top.size() - 1;
	while (st < en)
	{
		int	mid = (st + en) / 2;
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

void	PMergeMe::merge_insert_lst()
{
	int	merge_size = lst.size() / 2;
	Pair odd = std::make_pair(-1, -1);
	if (lst.size() % 2 == 1)
		odd = std::make_pair(lst[lst.size() - 1], -1);
	Tlist< Pair > top;
	Tlist< Pair > bot;
	int	i = 0;
	int	index = 0;
	while (merge_size--)
	{
		top.push_back(std::make_pair(lst[i + !(lst[i] > lst[i + 1])], index++));
		bot.push_back(std::make_pair(lst[i + (lst[i] > lst[i + 1])], -1));
		i += 2;
	}
	merge_lst(top, 1);
	insert_lst(top, bot, 0);
	if (odd.first > -1)
		insert_lst_odd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		lst[j] = top[j].first;
}

void	PMergeMe::merge_lst(Tlist< Pair > &before, int iter)
{
	if (before.size() == 1)
		return ;
	int	merge_size = before.size() / 2;
	Pair odd = std::make_pair(-1, -1);
	if (before.size() % 2 == 1)
		odd = before[before.size() - 1];
	Tlist< Pair > top;
	Tlist< Pair > bot;
	int	i = 0;
	while (merge_size--)
	{
		top.push_back(before[i + !(before[i].first > before[i + 1].first)]);
		bot.push_back(before[i + (before[i].first > before[i + 1].first)]);
		i += 2;
	}
	merge_lst(top, iter + 1);
	insert_lst(top, bot, iter);
	if (odd.first > -1)
		insert_lst_odd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		before[j] = top[j];
}

void PMergeMe::insert_lst(Tlist< Pair > &top, Tlist< Pair > &bot, int iter)
{
	Tlist<Pair> sorted_arr = top;
	sorted_arr.insert(sorted_arr.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1;
	Tlist<size_t> jacobsthalArr;
	for (size_t i = 1; jacobsthal_num(i) < top.size(); i++)
		jacobsthalArr.push_back(jacobsthal_num(i + 1));
	for (size_t j = 1; j < jacobsthalArr.size(); j++) {
		for (size_t jacob_n = jacobsthalArr[j]; jacob_n > jacobsthalArr[j - 1]; jacob_n--) {
			if (jacob_n > top.size()) 
				jacob_n = top.size();
			Pair value = bot[top[jacob_n - 1].second/static_cast<int>(pow(2, iter))];
			sorted_arr = binary_search_lst(sorted_arr, 0, jacob_n + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	top = sorted_arr;
}

Tlist< Pair > PMergeMe::binary_search_lst(Tlist<Pair> arr, int start, int end, Pair value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid].first > value.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (arr[start].first > value.first)
		arr.insert(arr.iter(start), value);
	else
		arr.insert(arr.iter(start + 1), value);
	return (arr);
}

void	PMergeMe::insert_lst_odd(Tlist< Pair > &top, Pair &odd)
{
	int	start = 0;
	int	end = top.size() - 1;
	while (start < end)
	{
		int	mid = (start + end) / 2;
		if (top[mid].first > odd.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (top[start].first > odd.first)
		top.insert(top.iter(start), odd);
	else
		top.insert(top.iter(start + 1), odd);
}
