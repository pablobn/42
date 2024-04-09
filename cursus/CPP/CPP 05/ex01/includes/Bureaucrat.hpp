#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string.h>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		void setGrade(int grade);
	public:
		//Constructors
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		//Destructor
		~Bureaucrat();
		//incremet and decrement
		void incrementGrade(void);
		void decrementGrade(void);
		//operator
		friend std::ostream &operator <<(std::ostream &out, const Bureaucrat &bureaucrat);
		//get
		int	getGrade(void) const;
		const std::string getName(void) const;
		//member function
		void	signForm(const Form &form);
		//Exceptions
		class GradeTooHighException : public std::exception
		{			
			virtual const char *what() const  throw()
			{
				return "The grade entered cannot exceed 150!";
			}
		} GradeTooHighException;

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const  throw()
			{
				return "The grade entered must be greater than 0!";
			};
		} GradeTooLowException;
};

#endif