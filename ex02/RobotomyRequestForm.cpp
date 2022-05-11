#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45, "Anonymous")
{
    std::cout << GREEN << "=== RobotomyRequestForm default constructor called. ===" << RESET << std::endl;
    std::cout << GREEN << "[RobotomyRequestForm target: " << target_ << "]" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45, target)
{
    std::cout << GREEN << "=== RobotomyRequestForm constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[RobotomyRequestForm target: " << target_ << "]" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED << "=== RobotomyRequestForm destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[RobotomyRequestForm target: " << target_ << "]" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : Form(form)
{
    std::cout << YELLOW << "=== RobotomyRequestForm copy constructor called. ===" << RESET << std::endl;
    std::cout << YELLOW << "[Coppied RobotomyRequestForm target: " << form.target_ << "]" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    std::cout << YELLOW << "=== RobotomyRequestForm Copy assignment operator called ===" << RESET << std::endl;
    std::cout << YELLOW << "[Substituted RobotomyRequestForm name: " << form.name_ << "]" << RESET << std::endl;
    if (this == &form)
        return *this;
    isSigned_ = form.getIsSigned();
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormIsNotSigned("form is not signed.");
    if (executor.getGrade() > requiredGradeForExec_)
        throw GradeTooLowException("grade is lower than required.");
    
    std::cout << "WHIR! WHIR!! WHIR!!! (drilling noises)" << std::endl;

    srand((unsigned int)std::time(NULL));
    if (rand() % 2)
        std::cout << target_ << " has been robotomized successfully " << std::endl;
    else
        std::cout << target_ << " has not been robotomized" << std::endl;
}
