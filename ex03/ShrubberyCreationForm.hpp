#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
    virtual void execute(const Bureaucrat &executor) const;
};

#endif
