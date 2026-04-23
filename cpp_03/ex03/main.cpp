#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt1("DiamondOne");
    dt1.whoAmI();
    dt1.attack("TargetA");
    dt1.takeDamage(30);
    dt1.beRepaired(20);
    dt1.highFivesGuys();
    dt1.guardGate();
    dt1.takeDamage(100);
    dt1.attack("TargetB"); 


    return 0;
}

