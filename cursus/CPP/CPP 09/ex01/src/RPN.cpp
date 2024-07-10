#include "RPN.hpp"

RPN::RPN(std::string str): str(str)
{}

RPN::~RPN(){}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN&   RPN::operator=(const RPN& other)
{
    (void) other;
    return *this;
}

int    RPN::resolve()
{
    std::stringstream   s(this->str);
    std::string token;
    int n;
    int n1;
    int n2;

    while (s >> token)
    {
        if (isdigit(token[0]))
        {
            n = std::stoi(token);
            this->nums.push(n);
        }
        else
        {
            if (this->nums.empty())
            {
                std::cout << "Error" <<std::endl;
                return (-1);
            }
            n1 = this->nums.top(); this->nums.pop();
            if (this->nums.empty())
            {
                std::cout << "Error" <<std::endl;
                return (-1);
            }
            n2 = this->nums.top(); this->nums.pop();
            if (token[0] == '+')
                this->nums.push(n2 + n1);   
            else if (token[0] == '-')
                this->nums.push(n2 - n1);
            else if (token[0] == '*')
                this->nums.push(n2 * n1);
            else if (token[0] == '/')
                this->nums.push(n2 / n1);
            else if (token[0] != ' ')
            {
                std::cout << "Error" <<std::endl;
                return (-1);
            }
        }
    }
    n = this->nums.top();this->nums.pop();
    if (!this->nums.empty())
    {
        std::cout << "Error" <<std::endl;
        return (-1);
    }
    std::cout<<n<<std::endl;
    return (0);
}