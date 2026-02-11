#include "include/Bureaucrat.hpp"
#include <exception>

int main()
{
    std::cout << "---test valid---" << std::endl;
    try{
        Bureaucrat john("john", 1);
        // std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}