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
			
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);

		std::string	getTarget(void)const;
		void executeForm()const;

};
std::ostream &operator<<(std::ostream & os, RobotomyRequestForm const &other);


#endif


