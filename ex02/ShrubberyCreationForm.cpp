#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target){}

ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target){}

    