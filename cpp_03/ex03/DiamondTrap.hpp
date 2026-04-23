#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;
public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    DiamondTrap();
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack; // Use ScavTrap's attack method
};
#endif // DIAMONDTRAP_HPP