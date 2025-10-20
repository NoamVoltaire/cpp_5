#include "Bureaucrat.hpp"
//#include <string>

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(0)
{
	//std::cout << "Bureaucrat is getting contructed" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat gets decontructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name), grade(grade)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &src)
		//this->name = src.name;
		this->grade = src.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

std::string	Bureaucrat::getName(void)const
{
	return (this->name);
}

short	Bureaucrat::getGrade(void)const
{
	return (this->grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
	//std::cout << "rank cannot be higher than 1" << std::endl;
}


const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low");
	//std::cout << getName() << "' s grade is too low" << std::endl;
	//std::cout << "rank cannot be lower than 150" << std::endl;
}

void	Bureaucrat::GradeUp()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}


void	Bureaucrat::GradeDown()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}
