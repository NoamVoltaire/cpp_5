#include "Intern.hpp"
#include <exception>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	//std::cout << "Intern is getting contructed" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern gets decontructed" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	// *this = copy;
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

void	trim_spaces(std::string &f_name)
{
	unsigned int start = 0;
	unsigned int end = f_name.size() - 1;

	while (start < end && std::isspace(f_name[start]))
		start++;
	
	if (start == end)
		return ;

	while (end > start && std::isspace(f_name[end]))
		end--;
	//return (f_name.substr(start, end - start + 1));
	f_name = f_name.substr(start, end - start + 1);

		
}
//cool trick with += (apppend) and reserve (to no reallocate)
void	case_down(std::string &f_name)
{
	std::string	formatted;
	formatted.reserve(f_name.size());

	for (size_t i = 0; i < f_name.size(); i++)
		if(!std::isspace(f_name[i]))
			formatted += std::tolower(f_name[i]);

	f_name = formatted;
}

void	format_name(std::string &f_name)
{
	trim_spaces(f_name);
	case_down(f_name);
}

AForm *Intern::createShrubberyCreationForm(const std::string &f_target)
{
	return new ShrubberyCreationForm(f_target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &f_target)
{
	return new PresidentialPardonForm(f_target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &f_target)
{
	return new RobotomyRequestForm(f_target);
}

AForm *Intern::makeForm(std::string f_name, std::string f_target)
{
	Existing_forms	forms[] =
	{
	 	{"shrubberycreation", &Intern::createShrubberyCreationForm},
	 	{"robotomyrequest", &Intern::createRobotomyRequestForm},
	 	{"presidentialpardon", &Intern::createPresidentialPardonForm}
	};
	format_name(f_name);
	for (size_t i = 0; i < 3; i++)
	{
		if (f_name == forms[i].name)
		{
			std::cout << "Intern creates " << f_name << std::endl;
			return ((this->*forms[i].form_maker)(f_target));
		}
	}
	std::cout << "\033[31m" << "Error : Intern doesn't know about" << f_name << " form, cannot make form" << "\033[0m" << std::endl;
	return NULL;
}
