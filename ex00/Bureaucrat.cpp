#include "include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string Name, int Grade) : _name(Name), _grade(Grade){
    if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (Grade > 150)
        throw  Bureaucrat::GradeToolowException();

    std::cout << "Bureaucrat " << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _grade(other._grade), _name(other._name){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

std::string Bureaucrat::getName() const{
    return this->_name;
}


void Bureaucrat::incrementGrade(){
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade >= 150)
        throw Bureaucrat::GradeToolowException();
    this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char *Bureaucrat::GradeToolowException::what() const throw()
{
    return "Grade is too low!";
}
std::ostream &operator <<(std::ostream &out, const Bureaucrat &b){
    out << b.getName() << ", bureaucrat grade "<< b.getGrade() << ".";
    return out;
}