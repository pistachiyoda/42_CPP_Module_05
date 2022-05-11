#include "Bureaucrat.hpp"

int main()
{
    {
        std::cout << "////////// Basic Function TEST //////////" << std::endl;
        Bureaucrat bureaucrat("fmai", 100);
        std::cout << bureaucrat.getName() << std::endl;
        std::cout << bureaucrat.getGrade() << std::endl;
        std::cout << bureaucrat;
        std::cout << "~~ Decrement grade ~~" << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat;
        std::cout << "~~ Increment grade ~~" << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat;
    }
    std::cout << std::endl;
    {
        std::cout << "////////// Exception TEST //////////" << std::endl;
        std::cout << "~~ TEST with lower grade 1. ~~" << std::endl;
        try
        {
            Bureaucrat bureaucrat("fmai", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
        std::cout << "~~ TEST with higher grade 1. ~~" << std::endl;
        try
        {
            Bureaucrat bureaucrat("fmai", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
        std::cout << "~~ TEST with lower grade 2. ~~" << std::endl;
        try
        {
            Bureaucrat bureaucrat("fmai", 150);
            bureaucrat.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
        std::cout << "~~ TEST with higher grade 2. ~~" << std::endl;
        try
        {
            Bureaucrat bureaucrat("fmai", 1);
            bureaucrat.incrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
