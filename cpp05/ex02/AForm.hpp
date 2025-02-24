#include <stdexcept>
#include <string>
#include <iostream>

#ifndef __FORM_H__
# define __FORM_H__

class Bureaucrat;

class AForm {
public:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	AForm();
	AForm(const std::string name, int sign_grade, int exec_grade) throw(GradeTooHighException, GradeTooLowException);
	AForm(const AForm &f);
	virtual ~AForm();
	AForm &operator=(AForm const &src);

	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &b) throw(GradeTooLowException);
	virtual void execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::FormNotSignedException) = 0;

protected:
	void setSigned(bool value);

private:
	const std::string	_name;
	const int			_sign_grade;
	const int			_exec_grade;
	bool				_is_signed;
};

std::ostream& operator<<(std::ostream &out, AForm const &f);

#endif
