# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm;

class	ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
//		bool			_signed;
//		const short			sign_grade;
//		const short			exec_grade;
			
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);

		std::string	getTarget(void)const;
		void execute(Bureaucrat const & executor)const;
		//bool	getSigned(void)const;
		//short		getGrade(void)const;
		//void	beSigned(const Bureaucrat &bureaucrat);

		//void	GradeUp();
		//void	GradeDown();

};
std::ostream &operator<<(std::ostream & os, ShrubberyCreationForm const &other);


#endif


