#include "Intern.hpp"

Intern::Intern() {
	_form_names[0] = "presidential pardon";
	_form_names[1] = "robotomy request";
	_form_names[2] = "shrubbery creation";
    _form_classes[0] = &PresidentialPardonForm::create;
	_form_classes[1] = &RobotomyRequestForm::create;
	_form_classes[2] = &ShrubberyCreationForm::create;
}

Intern::Intern(Intern &i) {
	(void)i;
}

Intern::~Intern() { }

Intern &Intern::operator=(Intern const &src) {
	(void)src;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	for (int i = 0; i < NR_OF_FORMS; ++i) {
		if (_form_names[i] == formName)
			return (*_form_classes[i])(target);
	}
	std::cout << "Form type " << formName << " not found." << std::endl;
	return NULL;
}
