#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signed(false), sign_grade(150), exec_grade(150) 
{
	std::cout << "AForm is getting contructed" << std::endl;
}
AForm::~AForm()
{
	std::cout << "AForm gets decontructed" << std::endl;
}

AForm::AForm(const std::string _name, short sign, short exec) : _name(_name), _signed(false), sign_grade(sign), exec_grade(exec) 
{
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	std::cout << this->getName() << " is getting contructed" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) 
{
}

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->_signed= src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
	os << "Form : " << other.getName() << 
	"\nis " << ((other.getSigned())? "signed" : "NOT signed") << 
	"\nwith sign_grade : " << other.getiSignGrade() <<
	"\nand exec_grade : " << other.getiSignGrade() << std::endl;
	return (os);
}

std::string	AForm::getName(void)const
{return (this->_name);}

bool	AForm::getSigned(void)const
{return (this->_signed);}

short		AForm::getiSignGrade(void)const
{return (this->sign_grade);}

short		AForm::getExecGrade(void)const
{return (this->exec_grade);}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high");
}


const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form's grade is too low");
}

const char	*AForm::AlreadySigned::what() const throw()
{
	return ("form is already signed");
}
const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AForm::AlreadySigned();
	else if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execution() const
{

}

void	AForm::execute(const Bureaucrat &executor)const
{
		if (this->_signed == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->exec_grade)
			throw Bureaucrat::GradeTooLowException();
		
		execution();
}
