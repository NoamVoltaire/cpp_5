#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") 
{
	// std::cout << "RobotomyRequestForm is getting contructed" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm deconstructor for "<< this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor for "<< this->_target << " is getting called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
	//std::cout << "RobotomyRequestForm constructor is getting called and copying " << copy._name <<
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_signed= src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &other)
{
	os << static_cast <const AForm&>(other);
	os << "Has target : " << other.getTarget() << std::endl;
	return (os);
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

static int rotbotomy_sucess = 0;

void RobotomyRequestForm::execution()const
{
	if (++rotbotomy_sucess %2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy foor " << this->_target << " has failed." << std::endl;
}

