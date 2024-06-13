#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(0));
	int n = std::rand() % 3 + 1;

	std::cout<<n<<std::endl;
	if (n == 1)
		return (new A());
	else if (n == 2)
		return (new B());

	return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "class identify A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "class identify B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "class identify C" << std::endl;
	else
		std::cerr << "class identify NULL" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int	main()
{
	Base base;
	A a;
	B b;
	C c;

	identify(&a);
	identify(&b);
	identify(&c);
	identify(generate());

	return (0);
}