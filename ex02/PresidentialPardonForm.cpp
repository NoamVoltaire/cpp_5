#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") 
{
	std::cout << "PresidentialPardonForm is getting contructed" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor for "<< this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor for "<< this->_target << " is getting called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
	std::cout << "PresidentialPardonForm constructor is getting called and copying " << copy._name <<
		"for" << this->_name << std::endl;
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_signed= src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &other)
{
	os << static_cast <const AForm&>(other);
	os << "Has target : " << other.getTarget() << std::endl;
	return (os);
}


std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
		if (this->_signed == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->exec_grade)
			throw Bureaucrat::GradeTooLowException();
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

