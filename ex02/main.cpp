#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
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
}
