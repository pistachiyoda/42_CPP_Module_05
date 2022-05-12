#ifndef INTERN_HPP
#define INTERN_HPP

#define RESET "\033[0m"
#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */

#include <iostream>
#include <string>
#include <exception>
#include "form.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
private:
    Form *(Intern::*forms_[3])(std::string target);
    std::string requests_[3];
    Form *makeShrubberyCreationForm(std::string target);
    Form *makeRobotomyRequestForm(std::string target);
    Form *makePresidentialPardonForm(std::string target);
public:
    Intern();
    ~Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    Form *makeForm(std::string formName, std::string target);
};

#endif
