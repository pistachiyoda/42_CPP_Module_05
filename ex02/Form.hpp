#ifndef FORM_HPP
#define FORM_HPP

#define RESET "\033[0m"
#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    static const int highestGrade_ = 1;
    static const int lowestGrade_ = 150;
    const std::string name_;
    bool isSigned_;
    const int requiredGradeForSign_;
    const int requiredGradeForExec_;
    const std::string target_;
public:
    Form();
    Form(const std::string &name, const int &gradeForSign, const int &gradeForExec, const std::string &target);
    virtual ~Form();
    Form(const Form &form);
    Form &operator=(const Form &form);
    std::string getName() const;
    std::string getTarget() const;
    int getRequiredGradeForSign() const;
    int getRequiredGradeForExec() const;
    bool getIsSigned() const;
    void setSign();
    void unsetSign();
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

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

std::ostream &operator<<(std::ostream &ost, Form const &form);

#endif
