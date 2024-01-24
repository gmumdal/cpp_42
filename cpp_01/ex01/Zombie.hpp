
#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie();

		void	announce(void);
		void	set_name(std::string _name);
};

Zombie	*zombieHorde(int N, std::string name);
