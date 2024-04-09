#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <string.h>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const std::string target;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		void setIsSigned(bool isSigned);
	public:
		//Constructors
		AForm();
		AForm(std::string name);
		AForm(std::string name, const int signGrade);
		AForm(const int signGrade, const int execGrade);
		AForm(std::string name, const int signGrade, const int execGrade);
		AForm(std::string name, std::string target, const int signGrade, const int execGrade);
		//Destructor
		virtual ~AForm();
		//Get
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		const std::string getName(void) const;
		const std::string getTarget(void) const;
		//operator
		friend std::ostream &operator <<(std::ostream &out, const AForm &form);
		//functions
		void beSigned(const Bureaucrat bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
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