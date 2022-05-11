#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        std::cout << "////////// Basic Function TEST 1 //////////" << std::endl;
        Form form;
        std::cout << form << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// Basic Function TEST 2 //////////" << std::endl;
        Form form("Important Document", 10);
        std::cout << form << std::endl;
        std::cout << form.getName() << std::endl;
        std::cout << form.getRequiredGrade() << std::endl;
        std::cout << form.getIsSigned() << std::endl;

        Bureaucrat bureaucrat("fmai", 5);
        std::cout << bureaucrat << std::endl;
        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// Exception TEST 1 //////////" << std::endl;
        try
        {
            Form form("Important Document", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }
    {
        std::cout << "////////// Exception TEST 2 //////////" << std::endl;
        try
        {
            Form form("Important Document", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }
    std::cout << std::endl;
    {
        std::cout << "////////// Exception TEST 3 //////////" << std::endl;
        Form form("Important Document", 1);
        std::cout << form << std::endl;

        Bureaucrat bureaucrat("fmai", 5);
        std::cout << bureaucrat << std::endl;
        try
        {
            form.beSigned(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
