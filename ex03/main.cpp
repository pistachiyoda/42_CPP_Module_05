#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

__attribute__((destructor))
static void destructor() {
    // system("leaks -q intern");
}

int main()
{
    {
        std::cout << "////////// robotomy request TEST //////////" << std::endl;
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// shruberry creation request TEST //////////" << std::endl;
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("shruberry creation request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// presidential pardon request TEST //////////" << std::endl;
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// non exist request TEST //////////" << std::endl;
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("non exist request", "Bender");
        if (rrf == NULL)
            std::cout << "OK" << std::endl;
        else
            std::cout << "NG" << std::endl;
    }
}
