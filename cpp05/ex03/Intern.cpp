#include "Intern.hpp"

// Static array initialization outside of the constructor
const std::string Intern::FORM_NAMES[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
const AForm* (*Intern::FORM_CLASSES[3])(std::string) = {&createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm};

// Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(Intern &i) {}

// Destructor
Intern::~Intern() {}

// Assignment Operator
Intern &Intern::operator=(Intern const &src) {
    if (this != &src) {
        // Normally you'd copy any dynamic state, but FORM_NAMES and FORM_CLASSES are static and cannot be changed.
    }
    return *this;
}

// The makeForm function implementation
AForm* Intern::makeForm(std::string formName, std::string target) {
    for (int i = 0; i < 3; ++i) {
        if (FORM_NAMES[i] == formName) {
            return FORM_CLASSES[i](target);
        }
    }
    throw UnknownFormException();
}
