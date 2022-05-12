#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45, "Anonymous")
{
    std::cout << GREEN << "=== RobotomyRequestForm default constructor called. ===" << RESET << std::endl;
    std::cout << GREEN << "[RobotomyRequestForm target: " << getTarget() << "]" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45, target)
{
    std::cout << GREEN << "=== RobotomyRequestForm constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[RobotomyRequestForm target: " << getTarget() << "]" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED << "=== RobotomyRequestForm destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[RobotomyRequestForm target: " << getTarget() << "]" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : Form(form)
{
    std::cout << YELLOW << "=== RobotomyRequestForm copy constructor called. ===" << RESET << std::endl;
    std::cout << YELLOW << "[Coppied RobotomyRequestForm target: " << form.getTarget() << "]" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    std::cout << YELLOW << "=== RobotomyRequestForm Copy assignment operator called ===" << RESET << std::endl;
    std::cout << YELLOW << "[Substituted RobotomyRequestForm name: " << form.getName() << "]" << RESET << std::endl;
    if (this == &form)
        return *this;
    if (form.getIsSigned())
        setSign();
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormIsNotSigned("form is not signed.");
    if (executor.getGrade() > getRequiredGradeForExec())
        throw GradeTooLowException("grade is lower than required.");
    
    std::cout << "WHIR! WHIR!! WHIR!!! (drilling noises)" << std::endl;

    srand((unsigned int)std::time(NULL));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully " << std::endl;
    else
        std::cout << getTarget() << " has not been robotomized" << std::endl;
}
