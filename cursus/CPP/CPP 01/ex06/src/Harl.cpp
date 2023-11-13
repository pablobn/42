#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger."<<std::endl;
	std::cout<<"I really do!"<<std::endl;
}
void	Harl::info(void)
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}
void	Harl::warning(void)
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I've been coming for years whereas you started working here since last month."<<std::endl;
}
void	Harl::error(void)
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void	Harl::complain(std::string level)
{
	int option = 5;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			option = i;
	}

	switch (option)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
	}

}