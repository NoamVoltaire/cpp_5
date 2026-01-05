#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *robot = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *shrub = new ShrubberyCreationForm("christmas");
		PresidentialPardonForm *pardon = new PresidentialPardonForm("WORLD");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a << std::endl;
		std::cout << *robot << std::endl;
		std::cout << *shrub << std::endl;
		std::cout << *pardon << std::endl;
		 a->executeForm(*shrub);

		// robot->beSigned(*a);
		a->signForm(*robot);
		a->signForm(*shrub);
		a->signForm(*pardon);
		// srhub->execute(*a);
		std::cout << std::endl;
		for (int i= 0; i < 10; i++)
			robot->execute(*a);
		std::cout << std::endl;
		 a->executeForm(*robot);

		std::cout << std::endl;
		 a->executeForm(*shrub);
		// srhub->execute(*a);

		std::cout << std::endl;
		 a->executeForm(*pardon);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete robot;
		delete shrub;
		delete pardon;
		std::cout << std::endl;
	}
	return (0);
}	
