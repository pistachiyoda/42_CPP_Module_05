#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &form);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
    virtual void execute(const Bureaucrat &executor) const;
};

#endif
