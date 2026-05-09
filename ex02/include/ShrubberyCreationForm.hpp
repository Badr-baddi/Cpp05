#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "include/AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
    private:
        const std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std:: &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};
#endif