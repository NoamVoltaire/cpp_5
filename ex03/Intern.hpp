# ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
//#include <exception>
//#include "AForm.hpp"
//#include "ShrubberyCreationForm.hpp"

class	AForm;

class	Intern
{
	private:
		typedef AForm *(Intern::*ft_func)(const std::string &);

	struct Existing_forms
	{
		const std::string	name;
		Intern::ft_func	form_maker;
	};
	
		AForm *createShrubberyCreationForm(const std::string &f_target);
		AForm *createPresidentialPardonForm(const std::string &f_target);
		AForm *createRobotomyRequestForm(const std::string &f_target);
	
	public:
		Intern();
		Intern(const Intern &copy);

		~Intern();

		Intern	&operator=(const Intern &src);

		AForm	*makeForm(std::string f_name, std::string f_target);


};
//std::ostream &operator<<(std::ostream & os, Interns const &other);


#endif


