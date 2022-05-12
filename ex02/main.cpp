#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // ShrubberyCreationForm TEST
    {
        // サインできて実行もできる
        std::cout << "////////// ShrubberyCreationForm TEST 1 //////////" << std::endl;
        Bureaucrat bureaucrat("nop", 137);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// ShrubberyCreationForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("nop", 146);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// ShrubberyCreationForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("nop", 138);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// ShrubberyCreationForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("nop", 1);
        ShrubberyCreationForm srform("42tokyo");
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;

    // RobotomyRequestForm TEST
    {
        // サインできて実行もできる
        std::cout << "////////// RobotomyRequestForm TEST 1 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 45);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// RobotomyRequestForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 73);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// RobotomyRequestForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 72);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// RobotomyRequestForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 73);
        RobotomyRequestForm ppform("McMurphy");
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;

    // PresidentialPardonForm TEST
    {
        // サインできて実行もできる
        std::cout << "////////// PresidentialPardonForm TEST 1 //////////" << std::endl;
        Bureaucrat bureaucrat("Person in high position", 5);
        PresidentialPardonForm ppform("fmai");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// PresidentialPardonForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("Person in high position", 26);
        PresidentialPardonForm ppform("fmai");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// PresidentialPardonForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("Person in high position", 6);
        PresidentialPardonForm ppform("fmai");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// PresidentialPardonForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("Person in high position", 26);
        PresidentialPardonForm ppform("fmai");
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
}
