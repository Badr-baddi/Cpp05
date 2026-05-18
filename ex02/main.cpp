#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("The Boss", 1);
        Bureaucrat yoyo("yoyo", 150);

        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");

        std::cout << "--- Testing Shrubbery ---" << std::endl;
        std::cout << shrub << std::endl;
        
        yoyo.signForm(shrub); 
        
        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << "\n--- Testing Robotomy ---" << std::endl;
        boss.signForm(robot);
        boss.executeForm(robot);

    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}