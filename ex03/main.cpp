#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* form;

    std::cout << "==========================================" << std::endl;
    std::cout << "        TEST 1: ROBOTOMY REQUEST          " << std::endl;
    std::cout << "==========================================" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // FIXED: Prevent memory leaks!
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "        TEST 2: SHRUBBERY CREATION        " << std::endl;
    std::cout << "==========================================" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "        TEST 3: PRESIDENTIAL PARDON       " << std::endl;
    std::cout << "==========================================" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "        TEST 4: INVALID FORM NAME         " << std::endl;
    std::cout << "==========================================" << std::endl;
    form = someRandomIntern.makeForm("free money form", "Yoyo");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    return 0;
}