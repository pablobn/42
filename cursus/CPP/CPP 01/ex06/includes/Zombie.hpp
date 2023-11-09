#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>
using namespace std;

class Zombie
{
private:
    string  name;
public:
    Zombie(string name);
    Zombie();
    ~Zombie();
    void    setName(string name);
    void    announce(void);
};

#endif