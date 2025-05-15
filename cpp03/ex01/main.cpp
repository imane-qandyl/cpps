
#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("imqandyl");

	scav.attack("target dummy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	return 0;
}
