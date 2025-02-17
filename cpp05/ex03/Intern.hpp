#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	class UnknownFormException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Intern();
	Intern(Intern &i);
	~Intern();
	Intern &operator=(Intern const &src);

	AForm *makeForm(std::string formName, std::string target);

private:
	const std::string	FORM_NAMES[3];
	const AForm			(*FORM_CLASSES[3])(std::string);
};
