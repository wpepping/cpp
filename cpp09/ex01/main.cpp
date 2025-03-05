#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	try {
		std::cout << RPN::parse(argv[1]) << std::endl;
	} catch (RPN::InvalidExpressionException &e) {
		std::cout << "Error" << std::endl;
	} catch (RPN::DivisionByZeroException &e) {
		std::cout << "Division by zero" << std::endl;
	}
}
