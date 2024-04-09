#include "Form.hpp"

Form::Form(): 
name("default"), isSigned(false), signGrade(60), execGrade(30)
{}

Form::Form(std::string name, const int signGrade): 
name(name), isSigned(false), signGrade(signGrade), execGrade(30)
{
	try
	{
		if (signGrade > 150)
			throw GradeTooHighException;
		else if(signGrade <= 0)
			throw GradeTooLowException;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Form::Form(std::string name, const int signGrade, const int execGrade): 
name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooHighException;
		else if(signGrade <= 0 || execGrade <= 0)
			throw GradeTooLowException;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Form::Form(const int signGrade, const int execGrade): 
name("default"), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooHighException;
		else if(signGrade <= 0 || execGrade <= 0)
			throw GradeTooLowException;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Form::~Form(){}

int	Form::getExecGrade(void) const
{
	return (this->execGrade);
}

int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

const std::string Form::getName(void) const
{
	return (this->name);
}

void Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

std::ostream &operator <<(std::ostream &out, const Form &form)
{
	out << form.getName() << std::endl;
	out << "______________" <<std::endl;
	out << "Sign grade -> " << form.getSignGrade()<<std::endl;
	out << "Execution grade -> " << form.getExecGrade()<<std::endl;
	out << "Signed -> " << form.getIsSigned()<<std::endl;
	return out;
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > getSignGrade())
			throw GradeTooLowException;
		else
			std::cout<<this->getName()<< " is signed "<<std::endl;
		setIsSigned(true);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
}