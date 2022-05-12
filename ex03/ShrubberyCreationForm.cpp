#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137, "Anonymous")
{
    std::cout << GREEN << "=== ShrubberyCreationForm default constructor called. ===" << RESET << std::endl;
    std::cout << GREEN << "[ShrubberyCreationForm target: " << getTarget() << "]" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << GREEN << "=== ShrubberyCreationForm constructor with arg called. ===" << RESET << std::endl;
    std::cout << GREEN << "[ShrubberyCreationForm target: " << getTarget() << "]" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RED << "=== ShrubberyCreationForm destructor called. ===" << RESET << std::endl;
    std::cout << RED << "[ShrubberyCreationForm target: " << getTarget() << "]" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : Form(form)
{
    std::cout << YELLOW << "=== ShrubberyCreationForm copy constructor called. ===" << RESET << std::endl;
    std::cout << YELLOW << "[Coppied ShrubberyCreationForm target: " << form.getTarget() << "]" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    std::cout << YELLOW << "=== ShrubberyCreationForm Copy assignment operator called ===" << RESET << std::endl;
    std::cout << YELLOW << "[Substituted ShrubberyCreationForm name: " << form.getName() << "]" << RESET << std::endl;
    if (this == &form)
        return *this;
    if (form.getIsSigned())
        setSign();
    else
        unsetSign();
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormIsNotSigned("form is not signed.");
    if (executor.getGrade() > getRequiredGradeForExec())
        throw GradeTooLowException("grade is lower than required.");
    std::string content =
        "          &&& &&  & &&\n"
        "      && &\\/&\\|& ()|/ @, &&\n"
        "      &\\/(/&/&||/& /_/)_&/_&\n"
        "   &() &\\/&|()|/&\\/ '%' & ()\n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "&&   && & &| &| /& & % ()& /&&\n"
        " ()&_---()&\\&\\|&&-&&--%---()~\n"
        "     &&     \\|||\n"
        "             |||\n"
        "             |||\n"
        "             |||\n"
        "       , -=-~  .-^- _\n"
        "ejm97          `\n"
        "\n"
        "------------------------------------------------\n"
        "Thank you for visiting https://asciiart.website/\n"
        "This ASCII pic can be found at\n"
        "https://asciiart.website/index.php?art=plants/trees\n";

    std::ofstream ofs;
    ofs.open(getTarget() + "_shrubbery");
    if (!ofs.is_open())
        throw std::runtime_error("Failed to open the file.");
    ofs << content;
    ofs.close();
}
