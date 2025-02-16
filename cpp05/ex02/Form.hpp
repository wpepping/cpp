#include <stdexcept>
#include <string>
#include <iostream>

#ifndef __FORM_H__
# define __FORM_H__

class Bureaucrat;

class Form {
public:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Form();
	Form(const std::string name, int sign_grade, int exec_grade) throw(GradeTooHighException, GradeTooLowException);
	Form(const Form &f);
	~Form();
	Form &operator=(Form const &src);

	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &b) throw(GradeTooLowException);

private:
	const std::string	_name;
	const int			_sign_grade;
	const int			_exec_grade;
	bool				_is_signed;
};

std::ostream& operator<<(std::ostream &out, Form const &f);

#endif
