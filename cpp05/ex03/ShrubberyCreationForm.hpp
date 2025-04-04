#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

#ifndef __SHRUBBERY_CREATION_FORM_H__
# define __SHRUBBERY_CREATION_FORM_H__

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const
		throw(AForm::GradeTooLowException, AForm::FormNotSignedException);
	static AForm* create(std::string target);

private:
	const std::string _target;

	static const std::string FORM_NAME;
	static const int SIGN_GRADE;
	static const int EXEC_GRADE;
};

#endif
