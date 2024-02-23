
#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// int	main(void)
// {
// 	std::cout << "max: " << max<int>(123, 456) << std::endl;
// 	std::cout << "min: " << min<int>(123, 456) << std::endl;
	
// 	char	c[4] = {'a', 'b', 'c'};
// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "0: " << c[0] << std::endl;
// 	std::cout << "1: " << c[1] << std::endl;
// 	std::cout << "2: " << c[2] << std::endl;
// 	std::cout << "---------------------------------" << std::endl;
// 	swap<char>(c[0], c[1]);
// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "0: " << c[0] << std::endl;
// 	std::cout << "1: " << c[1] << std::endl;
// 	std::cout << "2: " << c[2] << std::endl;
// 	std::cout << "---------------------------------" << std::endl;
// }
