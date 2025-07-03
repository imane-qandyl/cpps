#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 150);

        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;

        // Create forms
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target1");
        PresidentialPardonForm pardon("criminal");

        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        std::cout << shrubbery << std::endl;
        
        // Try to execute unsigned form
        try {
            highRank.executeForm(shrubbery);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // Sign and execute
        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        std::cout << robotomy << std::endl;
        midRank.signForm(robotomy);
        midRank.executeForm(robotomy);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        std::cout << pardon << std::endl;
        highRank.signForm(pardon);
        highRank.executeForm(pardon);

        // Test with insufficient grade
        std::cout << "\n--- Testing with insufficient grade ---" << std::endl;
        try {
            lowRank.executeForm(shrubbery);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
