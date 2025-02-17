#include "AForm.hpp"

#ifndef __PRESIDENTIAL_PARDON_FORM_H__
# define __PRESIDENTIAL_PARDON_FORM_H__

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException);
	static AForm* create(std::string target);

private:
	const std::string _target;

	static const std::string FORM_NAME;
	static const int SIGN_GRADE;
	static const int EXEC_GRADE;
};

#endif
