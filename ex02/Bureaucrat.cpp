#include "Bureaucrat.hpp"
#include <exception>
//#include <string>

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(0)
{
	//std::cout << "Bureaucrat is getting contructed" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat gets decontructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name), grade(grade)
{
	//if ( grade < 1)
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade < 1)
		throw GradeTooHighException();
	//std::cout << this->getName() << " is getting contructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
	//std::cout << "That unoriginal " << this->getName()
			//<< "copied it's contruction from " << copy.getName() << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &src)
		//this->name = src.name;
		this->grade = src.grade;
	return (*this);
	//this->name = src.name;
	//return (*this);
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}
