#include "PresidentialPardonForm.hpp"
//#include <fstream>
//#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") 
{
	std::cout << "PresidentialPardonForm is getting contructed" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor for "<< this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor for "<< this->getTarget() << " is getting called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm constructor is getting called and copying " << copy.getName() <<
		"for" << this->getName() << std::endl;
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	//std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &other)
{
	os << "PresidentialPardonForm : " << other.getName() << "is signed = " << other.getSigned() << std::endl;
	return (os);
}

std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

static int rotbotomy_sucess = 0;

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
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
		//return (false);
	//}
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

