#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<int> nums;
		std::string str;
	public:
		RPN(std::string str);
		RPN(const RPN& other);
		~RPN();
		RPN &operator=(const RPN& other);
		int	resolve();
};
#endif