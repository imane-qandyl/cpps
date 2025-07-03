#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm constructor called\n" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called\n" << std::endl;
}

AForm::AForm(const AForm &copy)
    : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
    std::cout << "AForm copy constructor called\n" << std::endl;
    *this = copy;
}
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // Note: name, gradeToSign, and gradeToExecute are const, so we cannot assign them
        // (std::string)this->name = other.name; // This line would cause a compilation error
        // this->gradeToSign = other.gradeToSign; // This line would cause a compilation error
        // this->gradeToExecute = other.gradeToExecute; // This line would cause a compilation error
    }
    std::cout << "AForm assignment operator called\n" << std::endl;
    return *this;
}

std::string const& AForm::getName() const {
    return this->name;
}
bool AForm::getIsSigned() const {
    return this->isSigned;
}
int const& AForm::getGradeToSign() const {
    return this->gradeToSign;
}
int const& AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& output, const AForm& f)
{
    output << "AForm: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
           << ", Grade to Sign: " << f.getGradeToSign()
           << ", Grade to Execute: " << f.getGradeToExecute();
    return output;
}
