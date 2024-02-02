
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jax("Jax");
	ClapTrap	malphite("Malphite");
	ClapTrap	riot;

	for (int i = 0 ; i < 5; i++)
		malphite.beRepaired(10);
	malphite.attack(riot.get_name());
	riot.takeDamage(malphite.get_attack_damage());
	malphite.attack(riot.get_name());
	riot.takeDamage(malphite.get_attack_damage());
	for (int i = 0 ; i < 10; i++)
	{
		jax.attack(malphite.get_name());
		malphite.takeDamage(jax.get_attack_damage());
	}
}
