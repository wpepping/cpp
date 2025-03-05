#include <iterator>
#include "RPN.hpp"

RPN::RPN() { }
RPN::~RPN() { }

int RPN::parse(const std::string &expression) throw(InvalidExpressionException, DivisionByZeroException) {
	int							result;
	char						curr;
	std::stack<char>			stack;
	std::string::const_iterator	str_it = expression.begin();
	std::string::const_iterator	str_end = expression.end();

	while (str_it != str_end) {
		curr = *str_it;
		if (_is_valid(*str_it))
			stack.push(*str_it);
		else if (*str_it != ' ')
			throw InvalidExpressionException();
		str_it++;
		if (isdigit(curr) && isdigit(*str_it))
			throw InvalidExpressionException();
	}

	result = _calculate(stack);
	if (!stack.empty())
		throw InvalidExpressionException();
	return result;
}

int RPN::_calculate(std::stack<char> &stack) throw(InvalidExpressionException, DivisionByZeroException) {
	char	op;
	int		lhs;
	int		rhs;

	if (stack.empty())
		throw InvalidExpressionException();
	if (!_is_operator(stack.top()))
		return RPN::_pop<char>(stack) - '0';
	op = RPN::_pop<char>(stack);
	if (stack.empty())
		throw InvalidExpressionException();
	rhs = _calculate(stack);
	if (stack.empty())
		throw InvalidExpressionException();
	lhs = _calculate(stack);
	return _calc_operator(lhs, rhs, op);
}

int	RPN::_calc_operator(int lhs, int rhs, char op) throw(DivisionByZeroException) {
	switch (op) {
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '*':
			return lhs * rhs;
		case '/':
			if (rhs == 0)
				throw DivisionByZeroException();
			return lhs / rhs;
	}
	return 0;
}

bool RPN::_is_valid(char c) {
	return std::isdigit(c) || _is_operator(c);
}

bool RPN::_is_operator(char c) {
	return std::string("+-*/").find(c) != std::string::npos;
}

const char* RPN::InvalidExpressionException::what() const throw() {
	return "invalid expression";
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return "division by zero";
}
