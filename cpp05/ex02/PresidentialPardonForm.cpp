#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

const std::string PresidentialPardonForm::FORM_NAME = "Presidential pardon form";
const int PresidentialPardonForm::SIGN_GRADE = 25;
const int PresidentialPardonForm::EXEC_GRADE = 5;

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) { }

PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
	if (this != &src)
		this->_is_signed = src._is_signed;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException) {
	if (!_is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
