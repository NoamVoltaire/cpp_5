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
(void)notaform;
// b.signForm(*notaform); // NULL pointer
// (void)rrf;
// (void)scf;
// (void)ppf;

delete rrf;
delete scf;
delete ppf;
// delete notaform;
}

