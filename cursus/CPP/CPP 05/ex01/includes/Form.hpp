#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <string.h>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		void setIsSigned(bool isSigned);
	public:
		//Constructors
		Form();
		Form(std::string name);
		Form(std::string name, const int signGrade);
		Form(const int execGrade, const int signGrade);
		Form(std::string name, const int signGrade, const int execGrade);
		//Destructor
		~Form();
		//Get
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		const std::string getName(void) const;
		//operator
		friend std::ostream &operator <<(std::ostream &out, const Form &form);
		//functions
		void beSigned(const Bureaucrat bureaucrat);
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
			virtual const char *what() const throw()
			{
				return "The grade entered must be greater!";
			};
		} GradeTooLowException;

};

#endif