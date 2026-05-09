#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "include/AForm.hpp"
#include "string"

class Bureaucrat;

class RobotomyRequestForm : public AForm{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};
#endif