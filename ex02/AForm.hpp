# ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class	AForm
{
	protected:
		const std::string	_name;
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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

		void	beSigned(const Bureaucrat &bureaucrat);

		void execute(Bureaucrat const & executor)const;
		virtual void execution()const = 0;
};
std::ostream &operator<<(std::ostream & os, AForm const &other);


#endif


