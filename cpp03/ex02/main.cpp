#include "FragTrap.hpp"

int main() {
	FragTrap frag("imqandyl");

	frag.attack("target dummy");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();

	return 0;
}
