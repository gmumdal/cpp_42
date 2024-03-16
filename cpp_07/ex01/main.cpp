
#include "iter.hpp"

int	main(void)
{
	int		arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const char	arr2[10] = "abcdefghi";
	int		arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	iter(arr1, 10, func1<int>);
	iter(arr3, 10, func3<int>);

	for (int i = 0; i < 10; i++)
		std::cout << arr1[i] << ' ' << arr3[i] << std::endl;
	iter(arr2, 10, func2<const char>);
	std::cout << std::endl;
}
