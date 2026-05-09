#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int   _grade;
        Bureaucrat();
    public:
        Bureaucrat(const std::string &name, int _grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        virtual ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();
        void signForm(AForm &f);

        void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
#endif