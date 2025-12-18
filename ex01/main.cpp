#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	
	std::cout << "\033[33m" << std::endl << "_____Test ex00_____" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.GradeUp();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.GradeUp();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;

	std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.GradeDown();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.GradeDown();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;





	std::cout << "\033[33m" << std::endl << "_____Test ex01_____" << "\033[0m" << std::endl;


	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Form too_high("high form", -1, 2);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught at Form creation: " << e.what() << std::endl;
	}
	try
	{
		Form too_low("low form", 160, 2);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught at Form creation: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Test signForm" << "\033[0m" << std::endl;
	Bureaucrat mr_id("MR_ID", 100);
	Form id_form("ID FORM", 100, 90);
	std::cout << mr_id << id_form << std::endl;

	mr_id.signForm(id_form);

	std::cout << "\033[33m" << std::endl << "Test couldn't sign" << "\033[0m" << std::endl;
	Form high("HIGH FORM", 2, 2);
	Bureaucrat mr_slow("MR_150", 150);
	std::cout << mr_slow << high << std::endl;

	mr_slow.signForm(high);
	mr_id.signForm(id_form);
	
	return (0);
}
