#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
        public:
            Bureaucrat();
            Bureaucrat(const std::string Name, int Grade);
            Bureaucrat(const Bureaucrat &other);
            Bureaucrat &operator=(const Bureaucrat &other);
            ~Bureaucrat();

            std::string getName() const;
            int getGrade() const;

            void incrementGrade();
            void decrementGrade();

            class GradeTooHighException : public std::exception{
                public:
                    virtual const char* what() const throw();
            };

            class GradeToolowException : public std::exception{
                public:
                    virtual const char* what() const throw();
            };

};
//outside the class
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
#endif