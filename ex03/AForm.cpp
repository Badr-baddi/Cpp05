#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"

AForm::AForm() : _name_("Default"), _isSigned(false), _gradeSigned(150), _gradeExecute(150){}

AForm::AForm(std::string name, int signGrade, int exeGrade) : _name_(name), _isSigned(false),_gradeSigned(signGrade), _gradeExecute(exeGrade)
{
    if (signGrade > 150 || exeGrade > 150)
        throw AForm::GradeTooLowException();
    if (signGrade < 1 || exeGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other) : _name_(other._name_), _isSigned(other._isSigned), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute){}

AForm &AForm::operator=(const AForm &other){
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

std::string AForm::getName() const {
    return this->_name_;
}

bool AForm::getIssigned() const{
    return this->_isSigned;
}

int AForm::getgradeSigned() const{
    return this->_gradeSigned;
}

int AForm::getgradeExecute() const{
    return this->_gradeExecute;
}

void AForm::beSigned(const Bureaucrat &b){
    if (b.getGrade() <= this->_gradeSigned)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
    o << "AForm: " << rhs.getName() << " | Signed: ";
    
    if (rhs.getIssigned())
        o << "Yes";
    else
        o << "No";

    o << " | Grade to Sign: " << rhs.getgradeSigned()
      << " | Grade to Execute: " << rhs.getgradeExecute();
    
    return o;
}