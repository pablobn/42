#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"){}

Bureaucrat::Bureaucrat(std::string name): name(name){}

Bureaucrat::Bureaucrat(int grade): name("default")
{
	try
	{
		if (grade > 150)
			throw GradeTooHighException;
		else if(grade <= 0)
			throw GradeTooLowException;
		this->grade = grade;
	}
	catch (std::exception& e)
	{
		std::cerr << "Excepcion: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	try
	{
		if (grade > 150)
			throw GradeTooHighException;
		else if(grade <= 0)
			throw GradeTooLowException;
		this->grade = grade;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade > 150)
			throw GradeTooHighException;
		else if(grade <= 0)
			throw GradeTooLowException;
		this->grade = grade;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade(void)
{
	setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(this->grade + 1);
}

std::ostream &operator <<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade();
	return out;
}

void	Bureaucrat::signForm(const Form &form)
{
	std::cout << this->getName();
	if (form.getIsSigned())
		std::cout << " signed " << form.getName();
	else
	{
		std::cout << " couldn't sign " << form.getName() << " because ";
		if (form.getSignGrade() < this->getGrade())
			std::cout << "grade is too low";
		else
			std::cout << "didn't sign the form yet";

	}
	std::cout << std::endl;
}