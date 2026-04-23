#include "FragTrap.hpp"

int main() {
    FragTrap frag("Fraggy");
    frag.attack("EnemyBot");
    frag.highFivesGuys();
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.takeDamage(90);
    frag.attack("AnotherEnemyBot");

    return 0;
}

