#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _sign_grade(1), _exec_grade(1), _is_signed(false) { }

Form::Form(const std::string name, int sign_grade, int exec_grade)
	throw(Form::GradeTooHighException, Form::GradeTooLowException):
		_name(name),
		_sign_grade(sign_grade),
		_exec_grade(exec_grade),
		_is_signed(false) {
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &f) :
	_name(f._name),
	_sign_grade(f._sign_grade),
	_exec_grade(f._exec_grade),
	_is_signed(f._is_signed) { }

Form::~Form() { }

Form &Form::operator=(Form const &src) {
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return *this;
}

const std::string Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

bool Form::isSigned() const {
	return _is_signed;
}

void Form::beSigned(const Bureaucrat &b) throw(GradeTooLowException) {
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &os, Form const &f) {
	os << f.getName() << ": sign grade " << f.getSignGrade()
		<< ", exec grade " << f.getExecGrade() << ", signed: " << (f.isSigned()?"yes":"no");
	return os;
}
