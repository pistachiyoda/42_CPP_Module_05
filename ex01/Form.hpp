#ifndef FORM_HPP
#define FORM_HPP

#define RESET "\033[0m"
#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    static const int highestGrade_ = 1;
    static const int lowestGrade_ = 150;
    const std::string name_;
    bool isSigned_;
    const int requiredGrade_;
public:
    Form();
    Form(const std::string &name, const int &grade);
    ~Form();
    Form(const Form &form);
    Form &operator=(const Form &form);
    std::string getName() const;
    int getRequiredGrade() const;
    bool getIsSigned() const;
    // 参照渡しで受け取らないと、コピこんが走る
    void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &ost, Form const &form);

#endif
