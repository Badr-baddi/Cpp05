#include "Bureaucrat.hpp"

Bureaucrat:Bureaucrat(): _name("Default"), _grade(150){

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){}

Bureaucrat::Bureaucrat &operator=(const Bureaucrat &other){
    if (this != &other)
}