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
			
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);

		std::string	getTarget(void)const;
		void execution()const;

};
std::ostream &operator<<(std::ostream & os, ShrubberyCreationForm const &other);


#endif


