#include "Form.hpp"
#include "Bureaucrat.hpp"
//#include <string>

Form::Form() : name("Form"), _signed(false), sign_grade(150), exec_grade(150) 
{
	std::cout << "Form is getting contructed" << std::endl;
}
Form::~Form()
{
	std::cout << "Form gets decontructed" << std::endl;
}

Form::Form(const std::string name, short sign, short exec) : name(name), _signed(false), sign_grade(sign), exec_grade(exec) 
{
	//if ( grade < 1)
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	std::cout << this->getName() << " is getting contructed" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), _signed(copy._signed), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) 
{
	//*this = copy;
	//std::cout << "That unoriginal " << this->getName()
			//<< "copied it's contruction from " << copy.getName() << std::endl;
}

Form	&Form::operator=(const Form &src)
{
	//std::cout << "Form Assignment operator called" << std::endl;
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
	os << "Form :" << other.getName() << "is signed = " << other.getSigned() << std::endl;
	return (os);
}

std::string	Form::getName(void)const
{
	return (this->name);
}

bool	Form::getSigned(void)const
{
	return (this->_signed);
}

//short	Form::getGrade(void)const
//{
//	return (this->grade);
//}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high");
	//std::cout << "rank cannot be higher than 1" << std::endl;
}


const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form's grade is too low");
	//std::cout << getName() << "' s grade is too low" << std::endl;
	//std::cout << "rank cannot be lower than 150" << std::endl;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}
//void	Form::GradeUp()
//{
//	if (this->grade <= 1)
//		throw GradeTooHighException();
//	this->grade--;
//}
//
//
//void	Form::GradeDown()
//{
//	if (this->grade >= 150)
//		throw GradeTooLowException();
//	this->grade++;
//}
