#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include "PmergeMe.hpp"

class ConversionFailedException : std::exception {
	const char* what() const throw() {
		return ("Conversion failed");
	}
};

int err_handl(std::string message, int error_code) {
	std::cout << "Error: " << message << std::endl;
	return error_code;
}

template <typename T>
void printContainer(const T &container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (it != container.begin())
			std::cout << ' ';
		std::cout << *it;
	}
}

bool isDigits(std::string str) {
	size_t	i;

	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return (i > 0);
}

std::vector<int> convertInput(unsigned int argc, char *argv[]) {
	long				l;
	char				*str_end;
	std::vector<int>	result;

	result.reserve(argc - 1);
	for (size_t i = 1; i < argc; i++) {
		if (!isDigits(argv[i]))
			throw ConversionFailedException();
		l = strtol(argv[i], &str_end, 10);
		if (argv[i] == str_end || l < std::numeric_limits<int>::min()
			|| l > std::numeric_limits<int>::max())
			throw ConversionFailedException();
		if (std::find(result.begin(), result.end(), l) != result.end())
		throw ConversionFailedException();
		result.push_back(l);
	}
	return result;
}

int main(int argc, char *argv[]) {
	std::vector<int>	input;
	std::vector<int>	output;
	std::list<int>		list_input;
	std::list<int>		list_output;
	std::clock_t		start;
	std::clock_t		end;

	if (argc == 1)
		return err_handl("Incorrect arguments", 1);

	try {
		input = convertInput(argc, argv);
	} catch (ConversionFailedException &e) {
		return err_handl("Incorrect arguments", 1);
	}

	std::cout << "Input: ";
	printContainer(input);
	std::cout << std::endl;

	start = std::clock();
	output = PmergeMe::VectorSort::sort(input);
	end = std::clock();

	std::cout << "Output: ";
	printContainer(output);
	std::cout << std::endl;

	std::cout << "Processing time using std::vector: ";
	std::cout << (double(end - start) * 1000000 / CLOCKS_PER_SEC);
	std::cout << "us" << std::endl;

	list_input = std::list<int>(input.begin(), input.end());

	start = std::clock();
	list_output = PmergeMe::ListSort::sort(list_input);
	end = std::clock();

	std::cout << "Processing time using std::list: ";
	std::cout << (double(end - start) * 1000000 / CLOCKS_PER_SEC);
	std::cout << "us" << std::endl;
}
