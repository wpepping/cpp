#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NR_OF_FORMS 3

class Intern {
public:
	Intern();
	Intern(Intern &i);
	~Intern();
	Intern &operator=(Intern const &src);

	AForm *makeForm(std::string formName, std::string target);

private:
	std::string	_form_names[NR_OF_FORMS];
	AForm*		(*_form_classes[NR_OF_FORMS])(std::string);
};
