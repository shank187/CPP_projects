#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("RoboWarrior");

    robot.attack("TargetDummy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("AnotherTarget");

    return 0;
}