#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        virtual void    makeSound() const = 0;
        std::string getType(void) const;
        void        setType(std::string type);
};

#endif