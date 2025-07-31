

#include "RobotomyRequestForm.hpp"

uint64_t nanosec_seed();

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
AForm("RobotomyRequestForm", false, 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : \
AForm(other.getName(), other.getSignedStatus(), other.getSignRequirement(), other.getExecuteRequirement())
{
    this->_target = other.getTarget();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    this->_target = other.getTarget();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const	&RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getExecuteRequirement() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << "* BZZZZZ BRRRRR BZZZZZZ * (drilling noises)" << std::endl;
    srand(nanosec_seed());
    int n = rand();
    std::cout << n << " " << n % 10 << std::endl;
    if (n >= 5) //rand() % 10
        std::cout << "Robotomy on " << this->_target << " was successful" << std::endl;
    else
        std::cout << "Oops... Robotomy on " << this->_target << " was butchered" << std::endl;
}

uint64_t nanosec_seed() {
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    return (uint64_t)t.tv_sec * 1000000000ULL + t.tv_nsec;
}