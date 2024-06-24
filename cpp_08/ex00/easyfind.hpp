
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

// template <typename T>
// typename T::iterator	easyfind(T container, int find)
// {
// 	typename T::iterator	it = container.begin();
// 	for (; it != container.end(); it++)
// 		if (*it == find)
// 			return (it);
// 	return (it);
// }

template <typename T>
typename T::iterator easyfind(T container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::logic_error("Cannot find value.");
	return (it);
}

#endif
