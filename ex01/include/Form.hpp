#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name_;
        bool _isSigned;
        const int _gradeSigned;
        const int _gradeExecute;
    public:
        Form();
        Form(const std::string name, int signGrade, int exeGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

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
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif