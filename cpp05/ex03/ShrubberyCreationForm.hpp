#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException);
	virtual AForm *create(std::string &target);

private:
	const std::string _target;

	static const std::string FORM_NAME;
	static const int SIGN_GRADE;
	static const int EXEC_GRADE;
};
