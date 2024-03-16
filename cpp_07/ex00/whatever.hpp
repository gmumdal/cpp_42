
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &first, T &second)
{
	T	tmp = first;

	first = second;
	second = tmp;
}

template <typename T>
const T	&min(const T &first, const T &second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

template <typename T>
const T	&max(const T &first, const T &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

#endif
