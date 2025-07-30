

#include "Form.hpp"

Form::Form() : _name("Form : Idable"){}

Form::Form(std::string name, bool is_signed, unsigned int sign_grade, unsigned int execute_grade) : _name(name)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
    this->_signed = is_signed;
    this->_sign_req = sign_grade;
    this->_execute_req = execute_grade;
}

Form::Form(Form &other) : _name(other._name)
{
    this->_signed = other._signed;
    this->_sign_req = other._sign_req;
    this->_execute_req = other._execute_req;
}

Form &Form::operator=(Form &other)
{
    this->_signed = other._signed;
    this->_sign_req = other._sign_req;
    this->_execute_req = other._execute_req;
    return (*this);
}

Form::~Form() {}

void	Form::beSigned(Bureaucrat &GrattePapier)
{
    if (GrattePapier.getGrade() > this->_sign_req)
        throw GradeTooLowException();
    this->_signed = true;
}

std::string const	&Form::getName(void) const
{
    return (this->_name);
}

bool				Form::getSignedStatus(void) const
{
    return (this->_signed);
}

unsigned int		Form::getSignRequirement(void) const
{
    return (this->_sign_req);
}

unsigned int		Form::getExecuteRequirement(void) const
{
    return (this->_execute_req);
}

std::ostream &operator<<(std::ostream &os, const Form &operand)
{
    os << operand.getName() << " is currently signed : " << operand.getSignedStatus() \
    << "form needs a Bureaucrat of level >= " << operand.getSignRequirement() \
    << "to be signed and a Bureacrat of level >= " << operand.getExecuteRequirement() \
    << "to be executed" << std::endl;
    return (os);
}
