
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
		if (isNumber(av[i]) == false)
			throw std::logic_error("Error: not a positive number: \'" + std::string(av[i]) + "\'");
		long long number = atol(av[i]);
		if (number > 2147483647)
			throw std::logic_error("Error: too large number: \'" + std::string(av[i]) + "\'");
		vec.push_back(number);
		lst.push_back(number);
	}
	std::cout << "PMergeMe constructor called" << std::endl;
}

PMergeMe::~PMergeMe()
{
	std::cout << "PMergeMe destructor called" << std::endl;
}

bool PMergeMe::isNumber(const std::string &number)
{
	if (number.size() == 0)
		return false;
	for (size_t i = 0; i < number.size(); i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return false;
	}
	return true;
}

size_t PMergeMe::jacobsthalNum(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
}

void PMergeMe::printArr(int state)
{
	/* origin */
	if (state == BEFORE)
		std::cout << "Before: ";
	if (state == AFTER)
		std::cout << "After:  ";
	// for (size_t i = 0; i < vec.size() - 1; i++)
	// 	std::cout << vec[i] << ' ';
	for (size_t i = 0; i < lst.size() - 1; i++)
		std::cout << lst[i] << ' ';
	std::cout << vec[vec.size() -1] << std::endl;

	/* test */
	// (void)state;
	// std::cout << "------ vector, deque ------" << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "] : " << vec[i] << "  |  "
	// 	<< "lst[" << i << "] : " << lst[i] << std::endl;
}

void PMergeMe::mergeInsertVec()
{
	if (vec.size() == 1)
		return ;
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
	merge(top, 1);
	insert(top, bot, 0);
	if (odd.first > -1)
		insertOdd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
}

void PMergeMe::merge(std::vector< Pair > &before, int iter)
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
	merge(top, iter + 1);
	insert(top, bot, iter);
	if (odd.first > -1)
		insertOdd(top, odd);
	before = top;
}

void PMergeMe::insert(std::vector< Pair > &top, std::vector< Pair > &bot, int iter)
{
	std::vector<Pair> sorted_arr = top;
	sorted_arr.insert(sorted_arr.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1;
	std::vector<size_t> jacobsthal_arr;
	for (size_t i = 1; jacobsthalNum(i) < top.size(); i++)
		jacobsthal_arr.push_back(jacobsthalNum(i + 1));
	for (size_t j = 1; j < jacobsthal_arr.size(); j++) {
		for (size_t jacob_n = jacobsthal_arr[j]; jacob_n > jacobsthal_arr[j - 1]; jacob_n--) {
			if (jacob_n > top.size()) 
				jacob_n = top.size();
			Pair value = bot[top[jacob_n - 1].second/static_cast<int>(pow(2, iter))];
			binarySearch(sorted_arr, 0, jacob_n + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	top = sorted_arr;
}

void PMergeMe::insertOdd(std::vector< Pair > &top, Pair &odd)
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
		top.insert(top.begin() + start, odd);
	else
		top.insert(top.begin() + start + 1, odd);
}

void PMergeMe::binarySearch(std::vector<Pair> &arr, int start, int end, Pair &value) {
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
}

void PMergeMe::mergeInsertLst()
{
	if (lst.size() == 1)
		return ;
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
	merge(top, 1);
	insert(top, bot, 0);
	if (odd.first > -1)
		insertOdd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		lst[j] = top[j].first;
}

void PMergeMe::merge(Tlist< Pair > &before, int iter)
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
	merge(top, iter + 1);
	insert(top, bot, iter);
	if (odd.first > -1)
		insertOdd(top, odd);
	for (size_t j = 0; j < top.size(); j++)
		before[j] = top[j];
}

void PMergeMe::insert(Tlist< Pair > &top, Tlist< Pair > &bot, int iter)
{
	Tlist<Pair> sorted_arr = top;
	sorted_arr.insert(sorted_arr.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1;
	Tlist<size_t> jacobsthal_arr;
	for (size_t i = 1; jacobsthalNum(i) < top.size(); i++)
		jacobsthal_arr.push_back(jacobsthalNum(i + 1));
	for (size_t j = 1; j < jacobsthal_arr.size(); j++) {
		for (size_t jacob_n = jacobsthal_arr[j]; jacob_n > jacobsthal_arr[j - 1]; jacob_n--) {
			if (jacob_n > top.size()) 
				jacob_n = top.size();
			Pair value = bot[top[jacob_n - 1].second/static_cast<int>(pow(2, iter))];
			binarySearch(sorted_arr, 0, jacob_n + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	top = sorted_arr;
}

void PMergeMe::insertOdd(Tlist< Pair > &top, Pair &odd)
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

void PMergeMe::binarySearch(Tlist<Pair> &arr, int start, int end, Pair &value) {
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
}
