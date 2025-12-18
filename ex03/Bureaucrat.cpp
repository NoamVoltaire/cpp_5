#include "Bureaucrat.hpp"
#include <exception>
//#include <string>

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(0)
{
	//std::cout << "Bureaucrat is getting contructed" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat gets decontructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
	//std::cout << this->getName() << " is getting contructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		//this->_name = src._name;
		this->_grade = src._grade;
	return (*this);
	//this->_name = src._name;
	//return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

short	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
}


const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low");
}

void	Bureaucrat::GradeUp()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}


void	Bureaucrat::GradeDown()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}
