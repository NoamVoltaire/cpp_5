#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	
Intern someRandomIntern;
Bureaucrat	b("Bender", 1);
Bureaucrat	p("Patrick", 1);
Bureaucrat	j("JFK", 1);
AForm* rrf;
AForm* scf;
AForm* ppf;
AForm* notaform;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
std::cout << "\n";
scf = someRandomIntern.makeForm("Shrubbery Creation", "Patrick");
std::cout << "\n";
ppf = someRandomIntern.makeForm("PreSiDenTial PardOn", "JFK");
std::cout << "\n";
notaform = someRandomIntern.makeForm("nonexistent form", "JFK");
std::cout << "\n";

b.signForm(*rrf);
p.signForm(*scf);
j.signForm(*ppf);
// b.signForm(*notaform);
// (void)rrf;
// (void)scf;
// (void)ppf;
// (void)notaform;

delete rrf;
delete scf;
delete ppf;
// delete notaform;
}


// int	main(void)
// {
	
// 	{
// 		std::cout << std::endl;

// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat *a = new Bureaucrat("Emperor", 1);
// 		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
// 		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
// 		std::cout << std::endl;

// 		std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		std::cout << *a;
// 		std::cout << *b;
// 		std::cout << *c;
// 		a->signForm(*b);
// 		b->beSigned(*a);
// 		a->signForm(*c);
// 		for (int i= 0; i < 10; i++)
// 			b->execute(*a);
// 		 a->executeForm(*c);
// 		c->execute(*a);
// 		std::cout << std::endl;

// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 		delete a;
// 		delete b;
// 		delete c;
// 		std::cout << std::endl;
// 	}
// 	return (0);
// }	


//	std::cout << "\033[33m" << std::endl << "Test ex01" << "\033[0m" << std::endl;
//
//	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
//	try
//	{
//		Bureaucrat Sleeper1("Bernd", 1500);
//	}
//	catch(const std::exception &e)
//	{
//		std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//
//	try
//	{
//		Bureaucrat Sleeper2("Olaf", -10);
//	}
//	catch(const std::exception &e)
//	{
//		std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//
//	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
//	Bureaucrat bob("Bob", 2);
//	std::cout << bob;
//	try
//	{
//		bob.GradeUp();
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//	std::cout << bob;
//	
//	try
//	{
//	bob.GradeUp();
//	}
//	catch(const std::exception& e)
//	{
//	std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//	std::cout << bob;
//
//
//
//	std::cout << "\033[33m" << std::endl << "Test GradeDown "<< "\033[0m" << std::endl;
//	Bureaucrat tim("Tim", 149);
//	std::cout << tim;
//	try
//	{
//		tim.GradeDown();
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//	std::cout << tim;
//	
//	try
//	{
//	tim.GradeDown();
//	}
//	catch(const std::exception& e)
//	{
//	std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//	std::cout << tim;
//	
//	return (0);

