
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	int		i;
	char	c;
	float	f;
	double	d;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator= (const Serializer &copy);
	
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
