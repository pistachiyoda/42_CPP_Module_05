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
        Form form("Important Document", 10, 20);
        std::cout << form << std::endl;
        std::cout << form.getName() << std::endl;
        std::cout << form.getRequiredGradeForSign() << std::endl;
        std::cout << form.getRequiredGradeForExec() << std::endl;
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
            Form form("Important Document", 0, 10);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            Form form("Important Document", 10, 0);
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
            Form form("Important Document", 151, 10);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            Form form("Important Document", 10, 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << std::endl;
    {
        std::cout << "////////// Exception TEST 3 //////////" << std::endl;
        Form form("Important Document", 1, 1);
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
    std::cout << std::endl;
    {
        std::cout << "////////// Exception TEST 4 //////////" << std::endl;
        Form form("Important Document", 1, 1);
        std::cout << form << std::endl;
        Bureaucrat bureaucrat("fmai", 5);
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
        Form weakForm("Unimportant Document", 100, 1);
        std::cout << weakForm << std::endl;
        bureaucrat.signForm(weakForm);
        std::cout << weakForm << std::endl;
    }
}
