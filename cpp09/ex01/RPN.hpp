#include <stack>
#include <iterator>
#include <string>

class RPN {
public:
	class InvalidExpressionException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
	class DivisionByZeroException : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	static int parse(const std::string &expression) throw(InvalidExpressionException, DivisionByZeroException);

private:
	RPN();
	~RPN();

	static int	_calculate(std::stack<char> &stack) throw(InvalidExpressionException, DivisionByZeroException);
	static int	_calc_operator(int lhs, int rhs, char op) throw(DivisionByZeroException);
	static bool	_is_valid(char c);
	static bool _is_operator(char c);

	template <typename T>
	static T _pop(std::stack<T> &stack) {
		T result = stack.top();
		stack.pop();
		return result;
	}
};
