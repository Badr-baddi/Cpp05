#include "include/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat yoyo("yoyo", 150);
        std::cout << yoyo << std::endl;
        yoyo.decrement();
        std::cout << yoyo <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Excwption caught: " << e.what() << std::endl;
    }
}