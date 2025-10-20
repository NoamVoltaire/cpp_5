# ifndef AFORM_HPP
# define AFORM_HPP

//#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class	AForm
{
	protected:
		const std::string	name;
		bool			_signed;
		const short			sign_grade;
		const short			exec_grade;
			
	public:
		AForm();
		AForm(std::string name, short sign, short exec);
		AForm(const AForm &copy);
		virtual	~AForm();
		AForm	&operator=(const AForm &src);

		std::string	getName(void)const;
		bool	getSigned(void)const;
		//short		getGrade(void)const;

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

		void	beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(Bureaucrat const & executor)const = 0;
		//void	GradeUp();
		//void	GradeDown();

};
//std::ostream &operator<<(std::ostream & os, AForm const &other);


#endif


