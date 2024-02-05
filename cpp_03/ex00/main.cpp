
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jax("Jax");
	ClapTrap	malphite("Malphite");
	ClapTrap	riot;

	std::cout << std::endl;
	for (int i = 0 ; i < 5; i++)
		malphite.beRepaired(10);
	std::cout << std::endl;
	malphite.attack(riot.get_name());
	riot.takeDamage(malphite.get_attack_damage());
	malphite.attack(riot.get_name());
	riot.takeDamage(malphite.get_attack_damage());
	std::cout << std::endl;
	for (int i = 0 ; i < 11; i++)
	{
		jax.attack(malphite.get_name());
		malphite.takeDamage(jax.get_attack_damage());
	}
}
