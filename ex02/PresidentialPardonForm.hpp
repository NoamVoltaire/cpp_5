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
			
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);

		std::string	getTarget(void)const;
		void executeForm()const;

};
std::ostream &operator<<(std::ostream & os, PresidentialPardonForm const &other);


#endif


