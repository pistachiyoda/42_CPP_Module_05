#include "Intern.hpp"

Intern::Intern()
{
    std::cout << GREEN << "=== Intern default constructor called. ===" << RESET << std::endl;

    forms_[0] = &Intern::makeShrubberyCreationForm;
    forms_[1] = &Intern::makeRobotomyRequestForm;
    forms_[2] = &Intern::makePresidentialPardonForm;

    requests_[0] = "shruberry creation request";
    requests_[1] = "robotomy request";
    requests_[2] = "presidential pardon request";
}

Intern::~Intern()
{
    std::cout << RED << "=== Intern destructor called. ===" << RESET << std::endl;
}

Intern::Intern(const Intern &intern)
{
    std::cout << YELLOW << "=== Intern copy constructor called. ===" << RESET  << std::endl;
  
    *this = intern;
}

Intern& Intern::operator=(const Intern &intern)
{
    std::cout << YELLOW << "=== Intern Copy assignment operator called ===" << RESET  << std::endl;
    if (this == &intern)
        return *this;
    return *this;
}

Form *Intern::makeShrubberyCreationForm(std::string target)
{
    Form *srform = new ShrubberyCreationForm(target);
    return srform;
}

Form *Intern::makeRobotomyRequestForm(std::string target)
{
    Form *rform = new RobotomyRequestForm(target);
    return rform;
}

Form *Intern::makePresidentialPardonForm(std::string target)
{
    Form *ppform = new PresidentialPardonForm(target);
    return ppform;
}

Form *Intern::makeForm(std::string formName, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName.compare(requests_[i]) == 0)
        {
            std::cout << "Intern creates " << formName << "." << std::endl;
            return (this->*(forms_[i]))(target);
        }
    }
    std::cerr << "Name of the form dosen't exist." << std::endl;
    return NULL;
}
