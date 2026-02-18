#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int exeGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _exeGrade(exeGrade) {

    if (signGrade < 1 || exeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || exeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _signGrade(other._signGrade), _exeGrade(other._exeGrade), _isSigned(other._isSigned) {
}

Form& Form::operator=(const Form &other) {
    if (this != &other)
        this->_isSigned = other.getSigned();
    return *this;
}

Form::~Form() {
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    // Renamed parameter to 'bureaucrat' (lowercase) to avoid shadowing Class name
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_isSigned;
}

int Form::getsignGrade() const {
    return this->_signGrade;
}

int Form::getExeGrade() const {
    return this->_exeGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << "Form " << f.getName() 
        << ", Status: " << (f.getSigned() ? "Signed" : "Unsigned")
        << ", Sign Grade: " << f.getsignGrade()
        << ", Exec Grade: " << f.getExeGrade();
    return out;
}