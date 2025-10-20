#include "AForm.hpp"
#include "Bureaucrat.hpp"
//#include <string>

AForm::AForm() : name("AForm"), _signed(false), sign_grade(150), exec_grade(150) 
{
	std::cout << "AForm is getting contructed" << std::endl;
}
AForm::~AForm()
{
	std::cout << "AForm gets decontructed" << std::endl;
}

AForm::AForm(const std::string name, short sign, short exec) : name(name), _signed(false), sign_grade(sign), exec_grade(exec) 
{
	//if ( grade < 1)
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	std::cout << this->getName() << " is getting contructed" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), _signed(copy._signed), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) 
{
	//*this = copy;
	//std::cout << "That unoriginal " << this->getName()
			//<< "copied it's contruction from " << copy.getName() << std::endl;
}

AForm	&AForm::operator=(const AForm &src)
{
	//std::cout << "AForm Assignment operator called" << std::endl;
	if (this != &src)
		this->_signed= src._signed;
		//this->name = src.name;
		//this->sign_grade = src.sign_grade;
		//this->sign_grade = src.sign_grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
	os << "AForm :" << other.getName() << "is signed = " << other.getSigned() << std::endl;
	return (os);
}

std::string	AForm::getName(void)const
{
	return (this->name);
}

bool	AForm::getSigned(void)const
{
	return (this->_signed);
}

//short	AForm::getGrade(void)const
//{
//	return (this->grade);
//}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high");
	//std::cout << "rank cannot be higher than 1" << std::endl;
}


const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form's grade is too low");
	//std::cout << getName() << "' s grade is too low" << std::endl;
	//std::cout << "rank cannot be lower than 150" << std::endl;
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
	//std::cout << getName() << "' s grade is too low" << std::endl;
	//std::cout << "rank cannot be lower than 150" << std::endl;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &executor)const
{
	(void)executor;
}
//void	AForm::GradeUp()
//{
//	if (this->grade <= 1)
//		throw GradeTooHighException();
//	this->grade--;
//}
//
//
//void	AForm::GradeDown()
//{
//	if (this->grade >= 150)
//		throw GradeTooLowException();
//	this->grade++;
//}
