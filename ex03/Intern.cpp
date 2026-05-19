#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string &target) const {
    std::cout << "Intern creates shrubbery creation" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) const {
    std::cout << "Intern creates robotomy request" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) const {
    std::cout << "Intern creates presidential pardon" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreatorFn creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formName) {
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create form '" << formName << "' because it doesn't exist!" << std::endl;
    return NULL;
}