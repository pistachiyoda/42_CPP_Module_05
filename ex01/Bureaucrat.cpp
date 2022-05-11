#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_(""), grade_(lowestGrade_)
{
    std::cout << GREEN << "=== Bureaucrat default constructor called. ===" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): name_(name), grade_(grade)
{
    std::cout << GREEN << "=== Bureaucrat constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[Bureaucrat name: " << name_ << "]" << RESET << std::endl;
    if (grade < highestGrade_)
        throw GradeTooHighException("Error! Grade is too High!!");
    if (grade > lowestGrade_)
        throw GradeTooLowException("Error! Grade is too Low!!");
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "=== Bureaucrat destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[Bureaucrat name: " << name_ << "]" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.name_)
{
    std::cout << YELLOW << "=== Bureaucrat copy constructor called. ===" << RESET  << std::endl;
    std::cout << YELLOW << "[Coppied Bureaucrat name: " << bureaucrat.name_ << "]" << RESET << std::endl;
  
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << YELLOW << "=== Bureaucrat Copy assignment operator called ===" << RESET  << std::endl;
    std::cout << YELLOW << "[Substituted Bureaucrat name: " << bureaucrat.name_ << "]" << RESET << std::endl;
    // 自己代入プロテクト
    if (this == &bureaucrat)
        return *this;
    // name_ = bureaucrat.getName(); // name_がconstなので代入できない...
    grade_ = bureaucrat.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if (grade_ <= highestGrade_)
        throw Bureaucrat::GradeTooHighException("Grade is Too High!!");
    grade_--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ >= lowestGrade_)
        throw Bureaucrat::GradeTooLowException("Grade is Too Low!!");
    grade_++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg): std::runtime_error(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg): std::runtime_error(msg) {}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bureaucrat)
{
    ost << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return ost;
}
