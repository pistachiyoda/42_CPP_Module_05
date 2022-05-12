#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5, "Anonymous")
{
    std::cout << GREEN << "=== PresidentialPardonForm default constructor called. ===" << RESET << std::endl;
    std::cout << GREEN << "[PresidentialPardonForm target: " << getTarget() << "]" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5, target)
{
    std::cout << GREEN << "=== PresidentialPardonForm constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[PresidentialPardonForm target: " << getTarget() << "]" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED << "=== PresidentialPardonForm destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[PresidentialPardonForm target: " << getTarget() << "]" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : Form(form)
{
    std::cout << YELLOW << "=== PresidentialPardonForm copy constructor called. ===" << RESET << std::endl;
    std::cout << YELLOW << "[Coppied PresidentialPardonForm target: " << form.getTarget() << "]" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
    std::cout << YELLOW << "=== PresidentialPardonForm Copy assignment operator called ===" << RESET << std::endl;
    std::cout << YELLOW << "[Substituted PresidentialPardonForm name: " << form.getName() << "]" << RESET << std::endl;
    if (this == &form)
        return *this;
    if (form.getIsSigned())
        setSign();
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormIsNotSigned("form is not signed.");
    if (executor.getGrade() > getRequiredGradeForExec())
        throw GradeTooLowException("grade is lower than required.");

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
