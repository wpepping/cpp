#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _sign_grade(1), _exec_grade(1), _is_signed(false) { }

AForm::AForm(const std::string name, int sign_grade, int exec_grade)
	throw(AForm::GradeTooHighException, AForm::GradeTooLowException):
		_name(name),
		_sign_grade(sign_grade),
		_exec_grade(exec_grade),
		_is_signed(false) {
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() { }

const std::string AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _sign_grade;
}

int AForm::getExecGrade() const {
	return _exec_grade;
}

bool AForm::isSigned() const {
	return _is_signed;
}

void AForm::beSigned(const Bureaucrat &b) throw(GradeTooLowException) {
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

std::ostream& operator<<(std::ostream &os, AForm const &f) {
	os << f.getName() << ": sign grade " << f.getSignGrade()
		<< ", exec grade " << f.getExecGrade() << ", signed: " << (f.isSigned()?"yes":"no");
	return os;
}
