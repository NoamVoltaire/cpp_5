# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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

};
std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);


#endif


