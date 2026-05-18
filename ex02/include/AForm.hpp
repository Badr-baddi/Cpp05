#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    protected:
        const std::string _name_;
        bool _isSigned;
        const int _gradeSigned;
        const int _gradeExecute;
    public:
        AForm();
        AForm(const std::string name, int signGrade, int exeGrade);
        AForm(const Form &other);
        AForm &operator=(const Form &other);
        virtual ~AForm(){}

        virtual void execute(Bureaucrat const & executor) const = 0;

        std::string getName() const;
        bool        getIssigned() const;
        int         getgradeSigned() const;
        int         getgradeExecute() const;

        void beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high (above 1)!";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const  char* what() const throw(){
                    return "Grade is too low (below 150)!";
            }
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form is not signed yet!";
            }
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);
#endif