#include <stdexcept>
#include <string>
#include <iostream>

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__


class Bureaucrat {
public:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string name, const int grade) throw(GradeTooLowException, GradeTooHighException);
	Bureaucrat(Bureaucrat const &b);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &src);

	const std::string getName() const;
	int getGrade() const;
	void incrementGrade() throw(GradeTooHighException);
	void decrementGrade() throw(GradeTooLowException);

private:
	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &b);

#endif
