#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

const std::string RobotomyRequestForm::FORM_NAME = "Robotomy request form";
const int RobotomyRequestForm::SIGN_GRADE = 72;
const int RobotomyRequestForm::EXEC_GRADE = 45;

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
	if (this != &src)
		this->_is_signed = src._is_signed;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException) {
	if (!_is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();

	std::cout << "... drilling noises ..." << std::endl;
	srand(time(0));
	if (std::rand() % 2 > 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
