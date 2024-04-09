#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string getTree(void)
{
    return ("         .     .  .      +     .      .          .\n"
            "     .       .      .     #       .           .\n"
            "        .      .         ###            .      .      .\n"
            "      .      .   '#:. .:##'##:. .:#'  .      .\n"
            "          .      . '####'###'####'  .\n"
            "       .     '#:.    .:#'###'#:.    .:#'  .        .       .\n"
            "  .             '#########'#########'        .        .\n"
            "        .    '#:.  '####'###'####'  .:#'   .       .\n"
            "     .     .  '#######''##'##''#######'                  .\n"
            "                .'##'#####'#####'##'           .      .\n"
            "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n"
            "      .     '#######'##'#####'##'#######'      .     .\n"
            "    .    .     '#####''#######''#####'    .      .\n"
            "            .     '      000      '    .     .\n"
            "       .         .   .   000     .        .       .\n"
            ".. .. ..................O000O........................ ...... ...\n");
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
			throw GradeTooLowException;
		else
		{
			std::ofstream newFile(this->getTarget() + "_shrubbery");
			newFile << getTree();
			newFile.close();
		}
	} 
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

AForm* ShrubberyCreationForm::makeForm(std::string name, std::string target, AForm *form)
{
	if (!form && name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (form);
}