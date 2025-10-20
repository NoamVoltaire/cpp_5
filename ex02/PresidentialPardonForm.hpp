# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm;

class	PresidentialPardonForm: public AForm
{
	private:
		const std::string	_target;
//		bool			_signed;
//		const short			sign_grade;
//		const short			exec_grade;
			
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);

		std::string	getTarget(void)const;
		void execute(Bureaucrat const & executor)const;
		//bool	getSigned(void)const;
		//short		getGrade(void)const;
		//void	beSigned(const Bureaucrat &bureaucrat);

		//void	GradeUp();
		//void	GradeDown();

};
std::ostream &operator<<(std::ostream & os, PresidentialPardonForm const &other);


#endif


