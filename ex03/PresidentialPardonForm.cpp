#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getIssigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getgradeExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}