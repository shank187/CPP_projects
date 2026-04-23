#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default") {
    std::cout << "DiamondTrap " << this->name << " default constructed." << std::endl;
    this->hitPoints = FragTrap::hitPoints; // Use FragTrap's hitpoints
    this->energyPoints = ScavTrap::energyPoints; // Use ScavTrap's energy points
    this->attackDamage = FragTrap::attackDamage; // Use FragTrap's attack damage
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
    this->hitPoints = FragTrap::hitPoints; // Use FragTrap's hitpoints
    this->energyPoints = ScavTrap::energyPoints; // Use ScavTrap's energy points
    this->attackDamage = FragTrap::attackDamage; // Use FragTrap's attack damage
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap " << this->name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
