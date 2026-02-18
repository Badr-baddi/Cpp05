#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _exeGrade;
    public:
        Form();
        Form(const std::string name, const int signGrade, const int exeGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        void beSigned(Bureaucrat &bureaucrat);

        std::string getName() const;
        bool getSigned() const;
        int getsignGrade() const;
        int getExeGrade()  const;

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const Form &b);
#endif