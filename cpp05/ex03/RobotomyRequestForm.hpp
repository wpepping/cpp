#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException);
	virtual AForm *create(std::string &target);

private:
	const std::string _target;

	static const std::string FORM_NAME;
	static const int SIGN_GRADE;
	static const int EXEC_GRADE;
};
