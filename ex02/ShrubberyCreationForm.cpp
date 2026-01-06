#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") 
{
	std::cout << "ShrubberyCreationForm is getting contructed" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor for "<< this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor for "<< this->_target << " is getting called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm constructor is getting called and copying " << copy._name <<
		"for" << this->_name << std::endl;
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_signed= src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &other)
{
	os << static_cast <const AForm&>(other);
	os << "Has target : " << other.getTarget() << std::endl;
	return (os);
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}


void ShrubberyCreationForm::execution()const
{
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
