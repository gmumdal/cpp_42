
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// 호출 인터페이스!
// 호출 가능한 개체가 따로 있는데, 밑에거는 안됨
// template <typename T, typename F>
// void iter(T *array, size_t length, F (*func)(T&))
// {
// 	if (array == NULL || func == NULL)
// 		return ;
// 	for (size_t i = 0; i < length; i++)
// 		func(array[i]);
// }

template <typename T>
void func1(T &element)
{
	element = element + 1;
}

template <typename T>
void func2(const T &element)
{
	std::cout << element;
}

template <typename T>
void func3(T &element)
{
	element = element * element;
}

#endif
