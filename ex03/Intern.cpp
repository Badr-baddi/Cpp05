#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {

    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int formIndex = -1;


    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formName) {
            formIndex = i;
            break;
        }
    }


    switch (formIndex) {
        case 0:
            std::cout << "Intern creates shrubbery creation" << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates robotomy request" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates presidential pardon" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Error: Intern cannot create form '" << formName << "' because it doesn't exist!" << std::endl;
            return NULL;
    }
}