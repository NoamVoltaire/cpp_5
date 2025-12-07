# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
//#include "ShrubberyCreationForm.hpp"

class	AForm;

class	Bureaucrat
{
	protected:
		const std::string	_name;
		short			_grade;
			
	public:
		Bureaucrat();
		Bureaucrat(std::string name, short grade );
		Bureaucrat(const Bureaucrat &other);
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
		void	signForm(AForm &form);
		void	executeForm(AForm const & form) const;

};
std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);


#endif


