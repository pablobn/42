#include "AForm.hpp"

AForm::AForm(): 
name("default"), target("default"),isSigned(false), signGrade(60), execGrade(30)
{}

AForm::AForm(std::string name, const int signGrade): 
name(name), target("default"),isSigned(false), signGrade(signGrade), execGrade(30)
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

AForm::AForm(std::string name, const int signGrade, const int execGrade): 
name(name), target("default"),isSigned(false), signGrade(signGrade), execGrade(execGrade)
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

AForm::AForm(const int signGrade, const int execGrade): 
name("default"), target("default"), isSigned(false), signGrade(signGrade), execGrade(execGrade)
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

AForm::AForm(std::string name, std::string target, const int signGrade, const int execGrade):
name(name), target(target), isSigned(false), signGrade(signGrade), execGrade(execGrade)
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



AForm::~AForm(){}

int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

const std::string AForm::getName(void) const
{
	return (this->name);
}

const std::string AForm::getTarget(void) const
{
	return (this->target);
}

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

std::ostream &operator <<(std::ostream &out, const AForm &form)
{
	out << form.getName() << std::endl;
	out << "______________" <<std::endl;
	out << "Sign grade -> " << form.getSignGrade()<<std::endl;
	out << "Execution grade -> " << form.getExecGrade()<<std::endl;
	out << "Signed -> " << form.getIsSigned()<<std::endl;
	return out;
}

void	AForm::beSigned(Bureaucrat bureaucrat)
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