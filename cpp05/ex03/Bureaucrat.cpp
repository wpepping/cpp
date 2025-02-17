#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) { }

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	throw(GradeTooLowException, GradeTooHighException) :
		_name(name),
		_grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b._name), _grade(b._grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f) const throw(GradeTooLowException) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << "." << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn’t sign " << f.getName()
			<< " because their grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f) {
	try {
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << "." << std::endl;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << _name << " couldn’t executed " << f.getName()
			<< " because the form is not signed." << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn’t executed " << f.getName()
			<< " because their grade is too low." << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
