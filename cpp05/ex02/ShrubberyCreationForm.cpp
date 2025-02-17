#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const std::string ShrubberyCreationForm::FORM_NAME = "Shrubbery creation form";
const int ShrubberyCreationForm::SIGN_GRADE = 145;
const int ShrubberyCreationForm::EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	if (this != &src)
		this->_is_signed = src._is_signed;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException) {
	std::string fname;
	std::ofstream outfile;

	if (!_is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();

	fname = _target + "_shrubbery";
	outfile.open(fname.c_str());
	if (outfile.fail())
		std::cout << "Error opening file." << std::endl;
	else {
		outfile << "       _-_" << std::endl;
		outfile << "    /~~   ~~\\" << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << "{               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~" << std::endl;
		outfile << "_-     | | _-" << std::endl;
		outfile << "  _ -  | |   -_" << std::endl;
		outfile << "      // \\\\" << std::endl;
		outfile.close();
	}
}
