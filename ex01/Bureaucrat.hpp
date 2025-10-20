# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	protected:
		const std::string	name;
		short			grade;
			
	public:
		Bureaucrat();
		Bureaucrat(std::string name, short grade );
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &src);

		std::string	getName(void)const;
		short		getGrade(void)const;
		void		setGrade(int new_grade)const;

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

		void	GradeUp();
		void	GradeDown();
		void	signForm(Form &form);

};
std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);


#endif


