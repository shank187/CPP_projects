#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_Scav") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created with default constructor!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->name << " copied!" << std::endl;
} 

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << this->name << " assigned!" << std::endl;
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target
                    << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
    }
}
