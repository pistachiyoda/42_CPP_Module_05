#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &form);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
    virtual void execute(const Bureaucrat &executor) const ;
};

#endif
