#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default") {
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap " << name << " created with default constructor!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name) {
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;

        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount
                  << " hit points! Current hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has insufficient energy or hit points to repair." << std::endl;
    }
}

