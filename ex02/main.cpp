#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat yoyo("yoyo", 150);
        Form contrat("Employment Contract", 50, 20);
        std::cout << yoyo << std::endl;
        yoyo.signForm(contrat);
        std::cout << contrat << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Excwption caught: " << e.what() << std::endl;
    }
}