
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base	*tmp = generate();
		identify(tmp);
		identify(*tmp);
		delete tmp;
		std::cout << std::endl;
	}
}

Base	*generate(void)
{
	Base	*p;
	int		i;

	i = rand() % 3;
	if (i == 0)
		p = new A;
	if (i == 1)
		p = new B;
	if (i == 2)
		p = new C;
	return (p);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer is A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Pointer is B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Pointer is C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "reference is A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "reference is B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "reference is C" << std::endl;
	}
	catch(const std::exception& e) {}
}
