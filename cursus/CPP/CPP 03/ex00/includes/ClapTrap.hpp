#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int health;
        int energy;
        int damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif