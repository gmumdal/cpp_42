
#include "Serializer.hpp"

int	main(void)
{
	Data	prev;
	Data	*next;
	uintptr_t	ptr;

	prev.c = 97;
	prev.i = 97;
	prev.f = 97;
	prev.d = 97;

	std::cout << "prev.c : " << prev.c << std::endl;
	std::cout << "prev.i : " << prev.i << std::endl;
	std::cout << "prev.f : " << prev.f << std::endl;
	std::cout << "prev.d : " << prev.d << std::endl;
	std::cout << "prev : " << &prev << std::endl;
	std::cout << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	std::cout << std::endl;
	next = Serializer::deserialize(ptr);
	std::cout << "next->c : " << next->c << std::endl;
	std::cout << "next->i : " << next->i << std::endl;
	std::cout << "next->f : " << next->f << std::endl;
	std::cout << "next->d : " << next->d << std::endl;
	std::cout << "next : " << next << std::endl;

}
