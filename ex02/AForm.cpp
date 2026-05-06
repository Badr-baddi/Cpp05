#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"

Form::Form() : _name_("Default"), _isSigned(false), _gradeExecute(150), _gradeSigned(150){}

Form::Form(std::string name, int signGrade, int exeGrade) : _name_(name), _isSigned(false),_gradeSigned(signGrade), _gradeExecute(exeGrade)
{
    if (signGrade > 150 || exeGrade > 150)
        throw Form::GradeTooLowException();
    if (signGrade < 1 || exeGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &other) : _name_(other._name_), _isSigned(other._isSigned), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute){}

Form &Form::operator=(const Form &other){
    if (this != &other)
        this->_isSigned = other._isSigned;
        return *this;
}

Form::~Form(){}

std::string Form::getName() const {
    return this->_name_;
}

bool Form::getIssigned() const{
    return this->_isSigned;
}

int Form::getgradeSigned() const{
    return this->_gradeSigned;
}

int Form::getgradeExecute() const{
    return this->_gradeExecute;
}

void Form::beSigned(const Bureaucrat &b){
    if (b.getGrade() <= this->_gradeSigned)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
    o << "Form: " << rhs.getName() << " | Signed: ";
    
    if (rhs.getIssigned())
        o << "Yes";
    else
        o << "No";

    o << " | Grade to Sign: " << rhs.getgradeSigned()
      << " | Grade to Execute: " << rhs.getgradeExecute();
    
    return o;
}