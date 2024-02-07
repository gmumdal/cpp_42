
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	DiamondTrap	riot;

	riot = DiamondTrap("teemo");

	std::cout << std::endl;

	riot.attack("Garen");
	riot.takeDamage(10);
	riot.beRepaired(10);
	riot.guardGate();
	riot.highFivesGuys();
	riot.whoAmI();

	std::cout << std::endl;

	DiamondTrap	jax(riot);

	jax.whoAmI();
	std::cout << std::endl;
}
