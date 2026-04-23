#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default_Frag") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created with default constructor!" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}   
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->name << " copied!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << this->name << " assigned!" << std::endl;
    return *this;
}
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
void FragTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << this->name << " has insufficient energy or hit points to attack." << std::endl;
    }
}

