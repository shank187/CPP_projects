#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Guardian");

    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    scav.takeDamage(80);
    scav.attack("AnotherIntruder");

    return 0;
}

