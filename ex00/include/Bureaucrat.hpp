#ifndef BUREAUCRAT.CPP
# define BUREAUCRAT.CPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int   _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "Error: Age it's very high!!!";
                }
        }
        class GradeTooLowException : public std::exception{
            virtual const  char* what() const throw(){
                return "Error: Age it's very low!!!";
            }
        }
};

#endif