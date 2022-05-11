#include "Form.hpp"

Form::Form(): name_("Anonymous"), isSigned_(false), requiredGrade_(lowestGrade_)
{
    std::cout << GREEN << "=== Form default constructor called. ===" << RESET << std::endl;
    std::cout << GREEN << "[Form name: " << name_ << "]" << RESET << std::endl;
}

Form::Form(const std::string &name, const int &grade): name_(name), isSigned_(false), requiredGrade_(grade)
{
    std::cout << GREEN << "=== Form constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[Form name: " << name_ << "]" << RESET << std::endl;
    if (grade < highestGrade_)
        throw GradeTooHighException("Error! Grade is too High!!");
    if (grade > lowestGrade_)
        throw GradeTooLowException("Error! Grade is too Low!!");
}

Form::~Form()
{
    std::cout << RED << "=== Form destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[Form name: " << name_ << "]" << RESET << std::endl;
}

Form::Form(const Form &form) : name_(form.name_), requiredGrade_(form.requiredGrade_)
{
    std::cout << YELLOW << "=== Form copy constructor called. ===" << RESET  << std::endl;
    std::cout << YELLOW << "[Coppied Form name: " << form.name_ << "]" << RESET << std::endl;
  
    *this = form;
}

Form& Form::operator=(const Form &form)
{
    std::cout << YELLOW << "=== Form Copy assignment operator called ===" << RESET  << std::endl;
    std::cout << YELLOW << "[Substituted Form name: " << form.name_ << "]" << RESET << std::endl;
    // 自己代入プロテクト
    if (this == &form)
        return *this;
    // constじゃないものだけここで代入
    isSigned_ = form.getIsSigned();
    return *this;
}

std::string Form::getName() const
{
    return name_;
}

int Form::getRequiredGrade() const
{
    return requiredGrade_;
}

bool Form::getIsSigned() const
{
    return isSigned_;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (requiredGrade_ < bureaucrat.getGrade())
        throw GradeTooLowException("Error! Grade is too Low!!");
    isSigned_ = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg): std::runtime_error(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg): std::runtime_error(msg) {}

std::ostream &operator<<(std::ostream &ost, Form const &form)
{
    std::string status = "form is not sigend";
    if (form.getIsSigned())
        status = "form is signed";

    ost << form.getName() << ", required grade " << form.getRequiredGrade() << ", " << status << ".";
    return ost;
}
