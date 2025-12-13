#include "RobotomyRequestForm.hpp"
//#include <fstream>
//#include <string>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") 
{
	//this is called
	// std::cout << "RobotomyRequestForm is getting contructed" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor for "<< this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor for "<< this->_target << " is getting called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
	std::cout << "RobotomyRequestForm constructor is getting called and copying " << copy._name <<
		"for" << this->_name << std::endl;
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	//std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &other)
{
	os << "RobotomyRequestForm : " << other.getName() << "is signed = " << other.getSigned() << std::endl;
	return (os);
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

static int rotbotomy_sucess = 0;

void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
	//try
	//{
		if (this->_signed == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->exec_grade)
			throw Bureaucrat::GradeTooLowException();
	//}
	//catch (const std::exception &e)
	//{
		//std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because " << e.what() << std::endl;
		//return ;
	//}
	if (++rotbotomy_sucess %2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy foor " << this->_target << " has failed." << std::endl;
}

