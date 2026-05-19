#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed for Robotomy randomness
    std::srand(std::time(NULL));

    std::cout << "==========================================" << std::endl;
    std::cout << "         CREATING BUREAUCRATS             " << std::endl;
    std::cout << "==========================================" << std::endl;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat assistant("Youssef", 40);
    Bureaucrat intern("Yoyo", 150);

    std::cout << boss << std::endl;
    std::cout << assistant << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n==========================================" << std::endl;
    std::cout << "       TEST 1: SHRUBBERY CREATION         " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        ShrubberyCreationForm shrub("Backyard");
        std::cout << shrub << std::endl;

        intern.signForm(shrub);    // Fails (150 > 145)
        assistant.signForm(shrub); // Succeeds (40 <= 145)
        assistant.executeForm(shrub); // Succeeds (40 <= 137) -> Creates Backyard_shrubbery
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "        TEST 2: ROBOTOMY REQUEST          " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        RobotomyRequestForm robot("Claptrap");
        std::cout << robot << std::endl;

        assistant.signForm(robot); // Succeeds (40 <= 72)
        intern.executeForm(robot); // Fails (150 > 45)

        std::cout << "\n--- Running Robotomy 4 times for 50% randomness ---" << std::endl;
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "       TEST 3: PRESIDENTIAL PARDON        " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        assistant.signForm(pardon); // Fails (40 > 25)
        boss.signForm(pardon);      // Succeeds (1 <= 25)
        boss.executeForm(pardon);    // Succeeds (1 <= 5) -> Prints pardon message
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "            END OF TESTS                  " << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}