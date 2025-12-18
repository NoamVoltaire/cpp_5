#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _signed(false), sign_grade(150), exec_grade(150) 
{
	std::cout << "Form is getting contructed" << std::endl;
}
Form::~Form()
{
	std::cout << "Form gets decontructed" << std::endl;
}

Form::Form(const std::string name, short sign, short exec) : _name(name), _signed(false), sign_grade(sign), exec_grade(exec) 
{
	//if ( grade < 1)
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	// std::cout << this->getName() << " is getting contructed" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) 
{
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
	os << "Form : " << other.getName() << 
	"\nis " << ((other.getSigned())? "signed" : "NOT signed") << 
	"\nwith sign_grade : " << other.getiSignGrade() <<
	"\nand exec_grade : " << other.getiSignGrade() << std::endl;
	return (os);
}

std::string	Form::getName(void)const
{return (this->_name);}

bool	Form::getSigned(void)const
{return (this->_signed);}

short		Form::getiSignGrade(void)const
{return (this->sign_grade);}

short		Form::getExecGrade(void)const
{return (this->exec_grade);}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char	*Form::AlreadySigned::what() const throw()
{
	return ("form is already signed");
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw Form::AlreadySigned();
		// std::cout << this->getName() << " is already signed" << std::endl;
	else if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}