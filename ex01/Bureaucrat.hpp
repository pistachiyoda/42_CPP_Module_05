#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET "\033[0m"
#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#include <iostream>

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

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bureaucrat);

#endif
