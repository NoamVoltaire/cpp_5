# ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool			_signed;
		const short			sign_grade;
		const short			exec_grade;
			
	public:
		Form();
		Form(std::string name, short sign, short exec);
		Form(const Form &copy);
		~Form();
		Form	&operator=(const Form &src);

		std::string	getName(void)const;
		bool	getSigned(void)const;
		short		getiSignGrade(void)const;
		short		getExecGrade(void)const;

	class GradeTooHighException : public std::exception
	{
	public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public :
		virtual const char *what() const throw();
	};
	class AlreadySigned: public std::exception
	{
	public :
		virtual const char *what() const throw();
	};

		void	beSigned(const Bureaucrat &bureaucrat);


};
std::ostream &operator<<(std::ostream & os, Form const &other);


#endif


