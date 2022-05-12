#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET "\033[0m"
#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name_;
    static const int lowestGrade_ = 150;
    static const int highestGrade_ = 1;
    int grade_;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int &grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
    void executeForm(Form const &form) const;

    class GradeTooHighException: public std::runtime_error
    {
    public:
       GradeTooHighException(const std::string &msg);
    };
    class GradeTooLowException: public std::runtime_error
    {
    public:
        GradeTooLowException(const std::string &msg);
    };
    class FormIsNotSigned: public std::runtime_error
    {
    public:
        FormIsNotSigned(const std::string &msg);
    };
};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bureaucrat);

#endif
