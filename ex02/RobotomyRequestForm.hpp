# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm;

class	RobotomyRequestForm: public AForm
{
	private:
		const std::string	_target;
//		bool			_signed;
//		const short			sign_grade;
//		const short			exec_grade;
			
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);

		std::string	getTarget(void)const;
		void execute(Bureaucrat const & executor)const;
		//bool	getSigned(void)const;
		//short		getGrade(void)const;
		//void	beSigned(const Bureaucrat &bureaucrat);

		//void	GradeUp();
		//void	GradeDown();

};
std::ostream &operator<<(std::ostream & os, RobotomyRequestForm const &other);


#endif


