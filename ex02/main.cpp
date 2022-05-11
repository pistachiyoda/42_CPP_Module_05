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
        Bureaucrat bureaucrat("fmai", 5);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// ShrubberyCreationForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 150);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// ShrubberyCreationForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 140);
        ShrubberyCreationForm srform("42tokyo");
        bureaucrat.signForm(srform);
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// ShrubberyCreationForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 140);
        ShrubberyCreationForm srform("42tokyo");
        std::cout << srform << std::endl;
        bureaucrat.executeForm(srform);
    }
    std::cout << std::endl;

    // RobotomyRequestForm TEST
    {
        // サインできて実行もできる
        std::cout << "////////// RobotomyRequestForm TEST 1 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 1);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// RobotomyRequestForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 80);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// RobotomyRequestForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 50);
        RobotomyRequestForm ppform("McMurphy");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// RobotomyRequestForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("Ratched", 140);
        RobotomyRequestForm ppform("McMurphy");
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;

    // PresidentialPardonForm TEST
    {
        // サインできて実行もできる
        std::cout << "////////// PresidentialPardonForm TEST 1 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 1);
        PresidentialPardonForm ppform("42tokyo");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // グレードが足りずサインできない
        std::cout << "////////// PresidentialPardonForm TEST 2 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 30);
        PresidentialPardonForm ppform("42tokyo");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
    }
    std::cout << std::endl;
    {
        // サインできるがグレードが足りず実行できない
        std::cout << "////////// PresidentialPardonForm TEST 3 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 20);
        PresidentialPardonForm ppform("42tokyo");
        bureaucrat.signForm(ppform);
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
    {
        // サインされていないため実行できない
        std::cout << "////////// PresidentialPardonForm TEST 4 //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 140);
        PresidentialPardonForm ppform("42tokyo");
        std::cout << ppform << std::endl;
        bureaucrat.executeForm(ppform);
    }
    std::cout << std::endl;
}
