#include "ShrubberyCreationForm.hpp"
//#include <fstream>
//#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") 
{
	std::cout << "ShrubberyCreationForm is getting contructed" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor for "<< this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor for "<< this->getTarget() << " is getting called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm constructor is getting called and copying " << copy.getName() <<
		"for" << this->getName() << std::endl;
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	//std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &other)
{
	os << "ShrubberyCreationForm : " << other.getName() << "is signed = " << other.getSigned() << std::endl;
	return (os);
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	//try
	//{
		if (this->getSigned() == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->exec_grade)
			throw Bureaucrat::GradeTooLowException();
	//}
	//catch (const std::exception &e)
	//{
		//std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because " << e.what() << std::endl;
		//return ;
	//}
	
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
	for (int i = 0; i < 5; i++)
       {
		outfile << "                                                         .\n" ;
		outfile << "                                              .         ;  \n" ;
		outfile << "                 .              .              ;%     ;;   \n" ;
		outfile << "                   ,           ,                :;%  %;   \n" ;
		outfile << "                    :         ;                   :;%;'     .,   \n" ;
		outfile << "           ,.        %;     %;            ;        %;'    ,;\n" ;
		outfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" ;
		outfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" ;
		outfile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n" ;
		outfile << "                `%;.     ;%;     %;'         `;%%;.%;'\n" ;
		outfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n" ;
		outfile << "                    `:%;.  :;bd%;          %;@%;'\n" ;
		outfile << "                      `@%:.  :;%.         ;@@%;'   \n" ;
		outfile << "                        `@%.  `;@%.      ;@@%;         \n" ;
		outfile << "                          `@%%. `@%%    ;@@%;        \n" ;
		outfile << "                            ;@%. :@%%  %@@%;       \n" ;
		outfile << "                              %@bd%%%bd%%:;     \n" ;
		outfile << "                                #@%%%%%:;;\n" ;
		outfile << "                                %@@%%%::;\n" ;
		outfile << "                                %@@@%(o);  . '         \n" ;
		outfile << "                                %@@@o%;:(.,'         \n" ;
		outfile << "                            `.. %@@@o%::;         \n" ;
		outfile << "                               `)@@@o%::;         \n" ;
		outfile << "                                %@@(o)::;        \n" ;
		outfile << "                               .%@@@@%::;         \n" ;
		outfile << "                               ;%@@@@%::;.          \n" ;
		outfile << "                              ;%@@@@%%:;;;. \n" ;
		outfile << "                          ...;%@@@@@%%:;;;;,..     " << std::endl;
	}
	outfile.close();

}

